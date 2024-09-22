//
// Created by Kyle on 2024/03/03.
//
module;

#include <iostream>

module adapter.basic_example.basic_classes;


namespace adapter::basic_example
{
    auto Adaptee::SpecificRequest() -> void
    {
        std::cout << "[Adaptee] SpecificRequest" << std::endl;
    }

    auto ObjectAdapter::Request() -> void
    {
        std::cout << "[ObjectAdapter] Calling SpecificRequest" << std::endl;
        m_Adaptee.SpecificRequest();
    }

    auto ClassAdapter::Request() -> void
    {
        std::cout << "[ClassAdapter] Calling SpecificRequest" << std::endl;
        SpecificRequest();
    }
}
