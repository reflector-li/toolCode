//
// Created by Lenovo on 2021/10/9.
//

#include "evalStr.h"

#include <utility>




evalStr::evalStr():pos(-1),ch(' '),Str(" ") {}

evalStr::evalStr(std::string  inStr):pos(-1),ch(' '),Str(std::move(inStr)){
}


void evalStr::nexchar() {
    ch = (++pos < Str.length())? Str[pos] : -1;
}

bool evalStr::check(int testChar) {
    while (ch == ' ') nexchar();
    if (testChar == ch)
    {
        nexchar();
        return true;
    }
    return  false;
}

double evalStr::eval() {
    nexchar();
    double x = Expression();
    if (pos < Str.length()) std::cout<<"wrong ch: "<<ch<<std::endl;
    ;
    return x;
}

double evalStr::Expression() {
    double x = Term();
    for(;;) {
        if (check('+')) x += Term();
        else if (check('-')) x -= Term();
        else return x;
    }
}

double evalStr::Term() {
    double x = Factor();
    for(;;){
        if (check('*')) x *= Factor();
        else if (check('/')) x /= Factor();
        else return x;
    }
}

double evalStr::Factor() {
    double x;
    int startPos = pos;
    if (check('+')) return x =Factor();
    if (check('-')) return x = -Factor();

    if(check('('))
    {
        x = Expression();
        check(')');
    }
    else if ((ch >= '0' && ch <= '9') || ch == '.')
    {
        while ((ch >= '0' && ch <= '9') || ch == '.') nexchar();
        std::string subStr(&Str[startPos],&Str[pos]);
        x = std::stoi(subStr);
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        while (ch >= 'a' && ch <= 'z') nexchar();
        std::string subStr(&Str[startPos],&Str[pos]);
        x = Factor();
        if      (subStr == "sin")  x = sin(x);
        else if (subStr == "cos")  x = cos(x);
        else if (subStr == "tan")  x = tan(x);
        else if (subStr == "sqrt") x = sqrt(x);
        else std::cout<<"wrong function"<<std::endl;
    }
    else
        std::cout<<"wrong ch"<<std::endl;


    if (check('^')) x = pow(x,Factor());
    return x;
}