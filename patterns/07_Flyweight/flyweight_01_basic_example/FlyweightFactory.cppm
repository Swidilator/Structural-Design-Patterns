//
// Created by Kyle on 2024/09/28.
//

module;
#include <iostream>
#include <unordered_map>

export module flyweight.basic_example.FlyweightFactory;

import flyweight.basic_example.Flyweight;

namespace flyweight::basic_example
{
    export class FlyweightFactory
    {
        inline static std::unordered_map<int, Flyweight*> m_Flyweights{};

    public:
        auto GetFlyweight(int key) -> Flyweight*;
        auto GetUnsharedFlyweight(int value) -> Flyweight*;
    };
}
