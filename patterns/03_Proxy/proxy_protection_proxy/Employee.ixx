//
// Created by Kyle on 2024/06/30.
//

module;
#include <sstream>
#include <string>
#include <utility>
export module proxy.protection_proxy.Employee;


namespace proxy::protection_proxy
{
    export class Employee
    {
        std::string m_Name;
        std::string m_Role;

    public:
        Employee(std::string m_name, std::string m_role)
            : m_Name(std::move(m_name)),
              m_Role(std::move(m_role)) {}

        [[nodiscard]] std::string GetName() const {
            return m_Name;
        }

        [[nodiscard]] std::string GetRole() const {
            return m_Role;
        }

        [[nodiscard]] std::string GetInfo() const {
            std::ostringstream out;
            out << '[' << m_Role << "] " << m_Name << ' ';
            return out.str();
        }
    };
}
