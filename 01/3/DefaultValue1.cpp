//
// Created by WorldPC on 2022-03-09.
//

#include <iostream>

int Adder(int num1=1,int num2=2){
    return num1+num2;
}
int main(void){
    std::cout<<Adder()<<std::endl;
    std::cout<<Adder(5)<<std::endl;
    std::cout<<Adder(3,5)<<std::endl;
    return 0;
}