#include <iostream>

using namespace std;

class SoSimple {//Polymorphic 클래스! ShowSimpleInfo가 가상함수 이므로
public:
    virtual void ShowSimpleInfo() {
        cout << "SoSimple Base Class" << endl;
    }
};

class SoComplex : public SoSimple {
public:
    void ShowSimpleInfo() {//가상함수
        cout << "SoComplex Derived Class" << endl;
    }
};

int main() {
    SoSimple *simPtr = new SoSimple;
    SoComplex *comPtr = dynamic_cast<SoComplex *>(simPtr);
    if (comPtr == NULL)
        cout << "형 변환 실패" << endl;
    else
        comPtr->ShowSimpleInfo();
    return 0;
}