#include "parser.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

onItem onText;
onPart onStart, onEnd;
onNum onNumber;

void refresh()
{
    onNumber = nullptr;
    onText = nullptr;
    onStart = nullptr;
    onEnd = nullptr;
}

void set_onNumber(onNum func)
{
    onNumber = func;
}

void set_onText(onItem func)
{
    onText = func;
};

void set_onStart(onPart func)
{
    onStart = func;
};

void set_onEnd(onPart func)
{
    onEnd = func;
};

void parse(const string &s)
{
    stringstream ss;
    if (onStart != nullptr)
        onStart();
    ss << s;
    string str;
    while (ss >> str)
    {
        if (is_num(str) && onNumber != nullptr)
            onNumber(get_num(str));
        else if (is_text(str) && onText != nullptr)
            onText(str);
    }
    if (onEnd != nullptr)
        onEnd();
}
bool is_num(const string &s)
{
    for (int i = 0; i < s.size(); i++)
        if (!isdigit(s[i]))
            return false;

    return true;
}
bool is_text(const string &s)
{
    for (int i = 0; i < s.size(); i++)
        if (!isalpha(s[i]))
            return false;

    return true;
}

int get_num(const string &s){
    int d = 0;
    for(int i = 0; i < s.size(); i++)
        d += (s[s.size() - i - 1] - '0') * pow(10, i);
    return d;
}