#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <string>

void parse(const std::string &s);
bool is_num(const std::string &s);
bool is_text(const std::string &s);
using onItem = void (*)(const std::string &number);
using onNum = void (*)(const int &number);
using onPart = void (*)();
int get_num(const std::string &s);
void set_onNumber(onNum func);
void set_onText(onItem func);
void set_onStart(onPart func);
void set_onEnd(onPart func);
void refresh();
#endif // PARSER_H_INCLUDED