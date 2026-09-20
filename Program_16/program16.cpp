#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <vector>

class Employee {
protected:
    int employeeId;
    std::string name;

public:
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    virtual double calculateSalary() const = 0;

    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;
    double tax;

public:
    PermanentEmployee(int id, std::string employeeName,
                      double basic, double extra, double taxAmount)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic),
          allowance(extra),
          tax(taxAmount) {}

    double calculateSalary() const override {
        double grossSalary = basicSalary + allowance;
        return grossSalary - tax;
    }
};

class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(int id, std::string employeeName,
                     double rate, int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

class FreelanceEmployee : public Employee {
private:
    double projectRate;
    int projectsCompleted;

public:
    FreelanceEmployee(int id, std::string employeeName,
                      double rate, int projects)
        : Employee(id, std::move(employeeName)),
          projectRate(rate),
          projectsCompleted(projects) {}

    double calculateSalary() const override {
        return projectRate * projectsCompleted;
    }
};

void printPaySlip(const Employee& employee) {
    employee.displayBasicDetails();
    std::cout << "Salary: Rs. " << employee.calculateSalary() << "\n\n";
}

int main() {
    std::vector<std::unique_ptr<Employee>> employees;

    employees.push_back(
        std::make_unique<PermanentEmployee>(
            101, "Asha", 40000.0, 8000.0, 5000.0
        )
    );

    employees.push_back(
        std::make_unique<ContractEmployee>(
            102, "Vikas", 500.0, 80
        )
    );

    employees.push_back(
        std::make_unique<FreelanceEmployee>(
            103, "Riya", 15000.0, 3
        )
    );

    double totalPayroll = 0.0;

    for (const auto& employee : employees) {
        printPaySlip(*employee);
        totalPayroll += employee->calculateSalary();
    }

    std::cout << "Total Payroll: Rs. " << totalPayroll << '\n';

    return 0;
}
