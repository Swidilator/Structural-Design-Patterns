//
// Created by Kyle on 2024/09/28.
//
module;
#include <iostream>

module flyweight.basic_example.UnsharedConcreteFlyweight;


namespace flyweight::basic_example
{
    auto UnsharedConcreteFlyweight::Operation(int extrinsic) -> void
    {
        std::cout << "Internal state: " << m_InternalState << std::endl;
        std::cout << "Extrinsic state: " << extrinsic << std::endl;
    }
}
