//
// Created by Kyle on 2024/09/26.
//
module;
#include <string>

export module bridge.PIMPL.Employee;

namespace bridge::PIMPL
{
    export class Employee
    {
        std::string m_Name{};
        int m_BasicSalary{};
        int m_HRA{};
        int m_LTA{};
        int m_CA{};

    public:
        Employee(const std::string& m_name, int m_basic_salary)
            : m_Name(m_name),
              m_BasicSalary(m_basic_salary)
        {
            m_HRA = 50;
            m_LTA = 10;
        }

        [[nodiscard]] auto GetTotalSalary() const -> int
        {
            return m_BasicSalary + m_HRA;
        }

        [[nodiscard]] auto ComputeTaxLiability() const -> int
        {
            return m_BasicSalary * 0.2f;
        }

        auto GetName() const -> const std::string
        {
            return m_Name;
        }
    };
}
