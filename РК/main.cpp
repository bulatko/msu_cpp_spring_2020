#include <iostream>
#include <fstream>
#include <queue>
#include <future>
#include <thread>
#include <mutex>
#include <condition_variable>

int test_num = 1;

void Test(bool statement)
{
    std::cout << "Test " << test_num << " : ";
    if (statement)
        std::cout << "ok";
    else
        std::cout << "no";
    std::cout << std::endl;
    test_num++;
}

int sum(std::queue<int> &q, std::mutex &mut, std::condition_variable &cnd_var, std::condition_variable &cnd_var_push)
{
    bool flag = true;

    int x, res = 0;

    while (flag)
    {
        std::unique_lock<std::mutex> Lock(mut, std::defer_lock_t());
        cnd_var.wait(Lock, [&q]() { return !q.empty(); });
        while (q.size())
        {
            x = q.front();
            if (!x)
            {
                flag = false;
                break;
            }
            q.pop();
            res += x;
        }
        cnd_var_push.notify_one();
    }
    return res;
}

void read(std::ifstream &in, std::queue<int> &q1, std::queue<int> &q2,
          std::mutex &mut_push,
          std::condition_variable &cnd_var1,
          std::condition_variable &cnd_var2,
          std::condition_variable &cnd_var_push)
{
    bool first = true;
    unsigned long long cur = 0, bufsz = 1000;
    int x, cur_thread = 0;

    std::unique_lock<std::mutex> Lock(mut_push, std::defer_lock_t());

    while (in >> x)
    {
        if (cur == bufsz)
        {
            cur = 0;
            if (!first)
            {
                cnd_var_push.wait(Lock);
            }
            else
            {
                first = false;
            }

            if (cur_thread % 2)
            {
                cnd_var1.notify_one();
            }
            else
            {
                cnd_var2.notify_one();
            }
            cur_thread = (cur_thread + 1) % 2;
        }
        else
        {
            cur++;
        }
        if (cur_thread % 2 == 0)
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
    }

    if (first)
        cnd_var1.notify_one();
    cnd_var_push.wait(Lock);

    q1.push(0);
    q2.push(0);

    cnd_var1.notify_one();
    cnd_var2.notify_one();
}

int file_sum(const std::string &filename)
{
    std::ifstream in(filename);
    std::queue<int> q1, q2;
    std::mutex mut1, mut2, mut_push;
    std::condition_variable cnd_var1, cnd_var2, cnd_var_push;

    auto task = [](std::function<int(std::queue<int> &,
                                     std::mutex &,
                                     std::condition_variable &,
                                     std::condition_variable &)>
                       f,

                   std::queue<int> &q,
                   std::mutex &mut,
                   std::condition_variable &cnd_var,
                   std::condition_variable &cnd_var_push,
                   std::promise<int> &prom) {
        prom.set_value(f(q, mut, cnd_var, cnd_var_push));
    };

    std::promise<int> promise1, promise2;

    auto res1 = promise1.get_future(), res2 = promise2.get_future();

    if (!in)
        throw std::runtime_error("File open error");

    std::thread thread1(task, sum,
                        std::ref(q1), std::ref(mut1),
                        std::ref(cnd_var1), std::ref(cnd_var_push),
                        std::ref(promise1));

    std::thread thread2(task, sum,
                        std::ref(q2), std::ref(mut2),
                        std::ref(cnd_var2), std::ref(cnd_var_push),
                        std::ref(promise2));

    read(in, std::ref(q1), std::ref(q2), std::ref(mut_push),
         std::ref(cnd_var1), std::ref(cnd_var2), std::ref(cnd_var_push));
    thread1.join();
    thread2.join();

    int numbers_sum = res1.get() + res2.get();

    return numbers_sum;
}

int main()
{
    int a;

    a = file_sum("input.txt");
    Test(a == 36);
    int res;

    bool has_error = false;

    try
    {
        res = file_sum("12312412.txt");
    }
    catch (std::runtime_error &er)
    {
        has_error = true;
    }

    Test(has_error);

    return 0;
}