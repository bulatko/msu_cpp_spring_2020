#include <iostream>
#include "parser.h"
#include <string>
#include <math.h>

using namespace std;

int started, numbers_count, words_count, max_words_length, 
    sum, ended, squares_sum = 0;


auto is_started()
{
    started = 1;
}

auto get_numbers_count(const int &s)
{
    numbers_count++;
}

auto get_words_count(const string &s)
{
    words_count++;
}

auto get_max_words_length(const string &s)
{
    if (s.size() > max_words_length)
        max_words_length = s.size();
}


auto count_sum(const int &s)
{
    
    sum += s;
}
auto get_squares_sum(const int &num){
    squares_sum += num * num;
}

void is_ended()
{
    ended = 1;
}

int main()
{
    started = 0;
    numbers_count = 0;
    set_onStart(is_started);
    set_onNumber(get_numbers_count);
    parse("123 edfwef 235423 dfg 2134325 1 4534 fffdd e 345");
    cout << started << " " << numbers_count << endl;

    cout << "TEST 1: ";
    started = 0;
    set_onStart(is_started);
    parse("123");
    if (!started)
    {
        cout << "NO" << endl;
        return 1;
    }
    cout << "OK" << endl;
    refresh();

    cout << "TEST 2: ";
    numbers_count = 0;
    set_onNumber(get_numbers_count);
    parse("12 sdf f 34235 dsf34 2 55 7");
    if (numbers_count != 5)
    {
        cout << "NO" << endl;
        return 1;
    }
    cout << "OK" << endl;
    refresh();

    cout << "TEST 3: ";
    max_words_length = 0;
    set_onText(get_max_words_length);
    parse("12 sdf f 34235 dsf34 2 55 7 abcdef");
    if (max_words_length != 6)
    {
        cout << "NO" << endl;
        return 1;
    }
    cout << "OK" << endl;
    refresh();

    cout << "TEST 4: ";
    max_words_length = 0;
    squares_sum = 0;
    set_onNumber(get_squares_sum);
    parse("1 2 3 4 fjsiodjfio 5");
    if (squares_sum != 55)
    {
        cout << "NO" << endl;
        return 1;
    }
    cout << "OK" << endl;
    refresh();

    cout << "TEST 5: ";
    sum = 0;
    set_onNumber(count_sum);
    parse("numbers 1 & 5 & 25 and 100");
    if (sum != 131)
    {
        cout << "NO" << endl;
        return 1;
    }
    cout << "OK" << endl;
    refresh();

    cout << "TEST 6: ";
    started = 0;
    ended = 0;
    set_onStart(is_started);
    set_onEnd(is_ended);
    parse("Any random sentence with number 123421");
    if (!(started && ended))
    {
        cout << "NO" << endl;
        return 1;
    }
    cout << "OK" << endl;
    refresh();

    return 0;
}
