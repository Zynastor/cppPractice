//
// Created by WorldPC on 2022-03-09.
//

#include <iostream>

namespace Parent {
    int num = 2;
    namespace subOne {
        int num = 3;
    }
    namespace SubTwo {
        int num = 4;
    }
}

int main(void) {
    std::cout << Parent::num << std::endl;
    std::cout << Parent::subOne::num << std::endl;
    std::cout << Parent::SubTwo::num << std::endl;
    return 0;
}

