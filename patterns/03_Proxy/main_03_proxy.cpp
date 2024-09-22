//
// Created by Kyle on 2024/04/07.
//

#include <iostream>

#include <filesystem>

import proxy.basic_example.main;
import proxy.virtual_proxy.main;
import proxy.protection_proxy.main;
//import proxy.remote_proxy.main;
import proxy.smart_proxy.main;

int main() {
    //auto p = std::filesystem::path(".");
    //std::cout << std::filesystem::weakly_canonical(p) << std::endl;

    //proxy::basic_example::main_basic_example();
    //proxy::virtual_proxy::main_virtual_proxy();
    //proxy::protection_proxy::main_protection_proxy();
    //proxy::remote_proxy::main_remote_proxy();
    proxy::smart_proxy::main_smart_proxy();
}


/*
 *Proxy should have the same interface as the real object
 *Client should not be able to distinguish between the two
 *You can inherit from the same class as the real subject
 *Can overload * and -> operators without having to implement all the methods of the real subject
 *Some implementations may create instance of real subject, may delay that instantiation
 *One proxy can act for multiple subjects, but only if all subjects inherit from the same base class
 *
 *Virtual proxy - creates expensive objects on demand
 *Cache proxy - caches expensive calls
 *Remote proxy - simplifies client implementation
 *Protection proxy - provides access management
 *Smart proxy - performs additional actions
*/