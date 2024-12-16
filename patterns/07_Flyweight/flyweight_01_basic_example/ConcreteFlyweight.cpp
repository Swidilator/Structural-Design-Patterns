//
// Created by Kyle on 2024/09/28.
//
module;
#include <iostream>

module flyweight.basic_example.ConcreteFlyweight;


namespace flyweight::basic_example
{
    auto ConcreteFlyweight::Operation(int extrinsic) -> void
    {
        std::cout << "Intrinsic state: " << *m_pIntrinsicState << std::endl;
        std::cout << "Extrinsic state: " << extrinsic << std::endl;
    }
}
