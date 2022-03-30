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
    SoSimple *simPtr = new SoComplex;
    SoComplex *comPtr = dynamic_cast<SoComplex *>(simPtr);
    comPtr->ShowSimpleInfo();
    return 0;
}