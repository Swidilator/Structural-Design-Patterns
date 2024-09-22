//
// Created by Kyle on 2024/04/07.
//

module;

#include <iostream>
#include <string>


export module proxy.protection_proxy.main;

import proxy.protection_proxy.Repository;
import proxy.protection_proxy.Employee;
import proxy.protection_proxy.RepoProxy;


namespace proxy::protection_proxy
{
    export auto main_protection_proxy() -> void {
        try {
            RepoProxy repo{R"(./)"};
            repo.SetAuthorisedRoles({"Manager", "Tech Lead"});
            Employee e1{"Umar", "Programmer"};
            Employee e2{"Ayaan", "Manager"};
            Employee e3{"Raihaan", "Tech Lead"};

            repo.SetEmployee(&e1);
            //repo.CreateFile("data.txt");

            repo.SetEmployee(&e1);
            repo.ViewFile("data.txt");
        }
        catch (std::exception& ex) {
            std::cout << "Exception: " << ex.what() << std::endl;
        }
    }
}
