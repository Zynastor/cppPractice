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
       /* for(int i=0;i<empNum;i++)
            empList[i]->ShowSalaryInfo();*/
    }

    void ShowTotalSalary() const {
        int sum = 0;
        /*for (int i=0;i<empNum;i++)
            sum+=empList[i]->GetPay();*/
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

int main(void) {//직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    TemporaryWorker *alba=new TemporaryWorker("Jung",700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);
    SalesWorker * seller=new SalesWorker("Hong",1000,0.1);
    seller->AddSalesResult(7000);//영업실적 7000
    handler.AddEmployee(seller);
    //이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();
    //총합
    handler.ShowTotalSalary();
    return 0;
}
