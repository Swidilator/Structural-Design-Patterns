//
// Created by Kyle on 2024/09/26.
//
module;
#include <string>

export module bridge.PIMPL.Employee;

namespace bridge::PIMPL {
    export class Employee {
        class EmployeeImpl;

        EmployeeImpl *m_pEmp{};

    public:
        Employee(const std::string &m_name, int m_basic_salary);

        [[nodiscard]] auto GetTotalSalary() const -> int;

        [[nodiscard]] auto ComputeTaxLiability() const -> int;

        [[nodiscard]] auto GetName() const -> std::string;

        ~Employee();
    };
}
