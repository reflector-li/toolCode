//
// Created by Lenovo on 2021/10/9.
//

#ifndef EVAL_STRFORMULA_EVALSTR_H
#define EVAL_STRFORMULA_EVALSTR_H
#include <string>
#include <cmath>
#include <iostream>

class evalStr
{
private:
    int pos ,ch;
    std::string Str;

public:
    evalStr();
    evalStr(std::string inStr);
    void nexchar();
    bool check(int testChar);
    double eval();
    double Expression();
    double Term();
    double Factor();

};


#endif //EVAL_STRFORMULA_EVALSTR_H
