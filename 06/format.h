#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
void GetVectArgs(std::vector<std::string> &vec, T &&arg)
{
    std::ostringstream oss;

    oss << std::forward<T>(arg);
    if (!oss)
    {
        throw std::runtime_error("input Arg Error");
    }
    vec.push_back(oss.str());
}

template <typename T, typename... Args>
void GetVectArgs(std::vector<std::string> &vec, T &&arg, Args &&... args)
{
    GetVectArgs(vec, std::forward<T>(arg));
    GetVectArgs(vec, std::forward<Args>(args)...);
}

enum class FindBrack
{
    find_open_brack,
    find_close_brack
};

std::string InsertArgs(const std::string &s, std::vector<std::string> &vec)
{
    std::string r;
    char brack_open = '{';
    char brack_close = '}';
    size_t pos_open_brack = 0;
    size_t pos_close_brack = 0;
    FindBrack find_brack = FindBrack::find_open_brack;

    for (size_t i = 0; i < s.size(); ++i)
    {
        const char &c = s[i];
        if (find_brack == FindBrack::find_open_brack)
        {
            if (c == brack_open)
            {
                pos_open_brack = i;
                r += s.substr(pos_close_brack, pos_open_brack - pos_close_brack);
                find_brack = FindBrack::find_close_brack;
            }
            else if (c == brack_close)
            {
                throw std::runtime_error("wrong order of brackets");
            }
        }
        else
        {
            if (c == brack_close)
            {
                pos_close_brack = i + 1;
                std::string tmp = s.substr(pos_open_brack + 1, pos_close_brack - pos_open_brack);
                int nom_arg = std::stoi(tmp);
                if (nom_arg < 0 || vec.size() <= nom_arg)
                {
                    throw std::runtime_error("wrong number of arguments in formatted string");
                }
                r += vec[nom_arg];
                find_brack = FindBrack::find_open_brack;
            }
            else if (c == brack_open)
            {
                throw std::runtime_error("wrong order of brackets");
            }
        }
    }
    if (find_brack == FindBrack::find_close_brack)
    {
        throw std::runtime_error("No closing bracket");
    }

    return r;
}

template <typename... Args>
std::string format(const std::string &inStr, Args &&... args)
{
    std::vector<std::string> vec;

    GetVectArgs(vec, std::forward<Args>(args)...);

    return InsertArgs(inStr, vec);
}