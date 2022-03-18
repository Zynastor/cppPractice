#include <iostream>
#include <cstring>

using namespace std;

class Employee {
private:
    char name[100];
public:
    Employee(char *name) {
        strcpy(this->name, name);
    }

    void ShowYourName() const {
        cout << "name: " << name << endl;
    }

    virtual int GetPay() const = 0;

    virtual void ShowSalaryInfo() const = 0;
};


class PermanentWorker : public Employee {
private:
    int salary;//급여
public:
    PermanentWorker(char *name, int money) : Employee(name), salary(money) {}

    int GetPay() const {
        return salary;
    }

    void ShowSalaryInfo() const {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};


class EmployeeHandler {
private:
    Employee *empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0) {}

    void AddEmployee(Employee *emp) {
        empList[empNum++] = emp;
    }

    void ShowAllSalaryInfo() const {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }

    void ShowTotalSalary() const {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    ~EmployeeHandler() {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

class TemporaryWorker : public Employee {
private:
    int workTime;//이달에 일한 시간의 합계
    int payPerHour;//시간당 급여
public:
    TemporaryWorker(char *name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}

    void AddWorkTime(int time) {
        workTime += time;
    }

    int GetPay() const {
        return workTime * payPerHour;
    }

    void ShowSalaryInfo() const {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker {
private:
    int salesResult;
    double bonusRatio;//상여금 비율
public:
    SalesWorker(char *name, int money, double ratio)
            : PermanentWorker(name, money), salesResult(0), bonusRatio(0) {}

    void AddSalesResult(int value) {
        salesResult += value;
    }

    int GetPay() const {
        return PermanentWorker::GetPay() + (int) (salesResult * bonusRatio);
    }

    void ShowSalaryInfo() const {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;//salesworker의 GetPay함수가 호출됨.
    }
};
namespace RISK_LEVEL {
    enum {
        RISK_A = 30, RISK_B = 20, RISK_C = 10
    };
}
class ForeignSalesWorker : public SalesWorker {
private:
    const int riskLevel;
public:
    ForeignSalesWorker(char *name, int money, double ratio, int risk)
            : SalesWorker(name, money, ratio), riskLevel(risk) {}

    int GetRiskPay() const {
        return (int) (SalesWorker::GetPay() * (riskLevel / 100.0));
    }

    int GetPay() const {
        return SalesWorker::GetPay() + GetRiskPay();
    }

    void ShowSalaryInfo() const {
        ShowYourName();
        cout << "salary: " << SalesWorker::GetPay() << endl;
        cout << "risk pay: " << GetRiskPay() << endl;
        cout << "sum: " << GetPay() << endl << endl;
    }
};

int main(void) {//직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;
    ForeignSalesWorker *fseller1
            = new ForeignSalesWorker("Hong", 1000, 0.0, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);//영업실적 7000
    handler.AddEmployee(fseller1);
    ForeignSalesWorker *fseller2
            = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);
    ForeignSalesWorker *fseller3
            = new ForeignSalesWorker("LEE", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);
    handler.ShowAllSalaryInfo();
    return 0;
}
