#include <iostream>

using namespace std;

void SimpleFuncOne();

void SimpleFuncTwo();

void SimpleFuncThree();

int main() {
    try {
        SimpleFuncOne();
    } catch (int expn) {
        cout << "μμΈμ½λ: " << expn << endl;
    }
    return 0;
}

void SimpleFuncOne() {
    cout << "SimpleFuncOne(void)" << endl;
    SimpleFuncTwo();
}

void SimpleFuncTwo() {
    cout << "SimpleFuncTwo(void)" << endl;
    SimpleFuncThree();
}

void SimpleFuncThree() {
    cout << "SimpleFuncThree(void)" << endl;
    throw -1;
}