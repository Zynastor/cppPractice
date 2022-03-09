//
// Created by WorldPC on 2022-03-09.
//
#include <iostream>

template <typename T>
inline T SQUARE(T x){
    return x*x;
}
int main(void){
    std::cout<<SQUARE(5.5)<<std::endl;
    std::cout<<SQUARE(12)<<std::endl;
    return 0;
}
