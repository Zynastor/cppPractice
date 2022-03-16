#include <iostream>

using namespace std;

class Car {
private:
    int gasolineGauge;
public:
    Car(int gas) : gasolineGauge(gas) {}
    int GetGasGauge() {
        return gasolineGauge;
    }
};

class HybridCar : public Car {
private:
    int electricGauge;
public:
    HybridCar(int gas, int electric) : Car(gas), electricGauge(electric) {}

    int GetElectricGauge() {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar {
private:
    int waterGauge;
public:
    HybridWaterCar(int gas, int electric, int water) : HybridCar(gas, electric), waterGauge(water) {}

    void ShowCurrentGauge() {
        cout << "잔여 가솔린: " << GetGasGauge() << endl;
        cout << "잔여 전기량: " << GetElectricGauge() << endl;
        cout << "잔여 워터량: " << waterGauge << endl;
    }
};

int main(void) {
    HybridWaterCar nexo(100, 50, 20);
    nexo.ShowCurrentGauge();
    return 0;
}