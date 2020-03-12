#include "parser.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

onItem onNumber, onText;
onPart onStart, onEnd;

void set_onNumber(onItem func)
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

void parse(const string s)
{
    stringstream ss;
    if (onStart != nullptr)
        onStart();
    ss << s;
    string str;
    while (ss >> str)
    {
        if (is_num(str) && onNumber != nullptr)
            onNumber(str);
        else if (is_text(str) && onText != nullptr)
            onText(str);
    }
    if (onEnd != nullptr)
        onEnd();
}
bool is_num(const string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] < '0' || s[i] > '9')
            return false;

    return true;
}
bool is_text(const string s)
{
    for (int i = 0; i < s.size(); i++)
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
            return false;

    return true;
}