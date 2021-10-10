#include <iostream>
#include "evalStr.h"

int main() {
    std::string  a = "2+4*7";
    evalStr test(a);
    double z = test.eval();
    std::cout << z << std::endl;
    return 0;
}
