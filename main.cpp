#include <iostream>

class Employee {
public:
    std::string name;
    int id;
    double hourlyRate;

    Employee(std::string name, int id, double hourlyRate)
            : name(name), id(id), hourlyRate(hourlyRate) {}

    double computePay(int hoursWorked) const {
        return hoursWorked * hourlyRate;
    }
};

class PayrollSystem {
private:
    std::vector<Employee> employees;
public:
    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    void computePayroll() const {
        std::cout << "Payroll Summary\n";
        std::cout << "---------------\n";
        for (const auto& employee : employees) {
            std::cout << "Employee: " << employee.name << " | Pay: $" << employee.computePay(40) << std::endl;
        }

    }
};

int main() {
    PayrollSystem payroll;

    payroll.addEmployee(Employee("John Doe", 1, 20.0));
    payroll.addEmployee(Employee("Jane Smith", 2, 22.5));

    payroll.computePayroll();

    return 0;
}