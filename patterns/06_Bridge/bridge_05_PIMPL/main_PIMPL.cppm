//
// Created by kyle on 2024/09/20.
//

module;
#include <iostream>


export module bridge.PIMPL.main;

import bridge.PIMPL.Employee;


namespace bridge::PIMPL {
    export auto main_PIMPL() -> void {
        Employee emp{"Kyle", 1000};
        std::cout << "Name: " << emp.GetName() << std::endl;
        std::cout << "Total salary: " << emp.GetTotalSalary() << std::endl;
        std::cout << "Tax: " << emp.ComputeTaxLiability() << std::endl;
    }
}
