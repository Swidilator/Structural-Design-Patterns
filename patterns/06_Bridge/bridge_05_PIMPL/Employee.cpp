//
// Created by kyle on 2024/09/28.
//
module;
#include <iostream>
#include <string>


module bridge.PIMPL.Employee;

namespace bridge::PIMPL {
    class Employee::EmployeeImpl {
        std::string m_Name{};
        int m_BasicSalary{};
        int m_HRA{};
        int m_LTA{};
        int m_PA{};

    public:
        EmployeeImpl(const std::string &m_name, int m_basic_salary)
            : m_Name(m_name),
              m_BasicSalary(m_basic_salary) {
            m_HRA = 50;
            m_LTA = 10;
            m_PA = 5;
        }

        [[nodiscard]] auto GetTotalSalary() const -> int {
            return m_BasicSalary + m_HRA + m_LTA + m_PA;
        }

        [[nodiscard]] auto ComputeTaxLiability() const -> int {
            return m_BasicSalary * 0.2f;
        }

        auto GetName() const -> const std::string {
            return m_Name;
        }
    };

    Employee::Employee(const std::string &m_name, int m_basic_salary) {
        m_pEmp = new EmployeeImpl{m_name, m_basic_salary};
    }

    auto Employee::GetTotalSalary() const -> int {
        return m_pEmp->GetTotalSalary();
    }

    auto Employee::ComputeTaxLiability() const -> int {
        return m_pEmp->ComputeTaxLiability();
    }

    auto Employee::GetName() const -> std::string {
        return m_pEmp->GetName();
    }

    Employee::~Employee() {
        delete m_pEmp;
    }
}
