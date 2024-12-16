//
// Created by Kyle on 2024/09/28.
//
module;
#include <iostream>

module flyweight.basic_example.FlyweightFactory;

import flyweight.basic_example.ConcreteFlyweight;
import flyweight.basic_example.UnsharedConcreteFlyweight;

namespace flyweight::basic_example
{
    auto FlyweightFactory::GetFlyweight(int key) -> Flyweight*
    {
        if (m_Flyweights.contains(key))
        {
            return m_Flyweights[key];
        }
        static int intrinsicState{100};
        Flyweight* p = new ConcreteFlyweight{&intrinsicState};
        m_Flyweights[key] = p;
        return p;
    }

    auto FlyweightFactory::GetUnsharedFlyweight(int value) -> Flyweight*
    {
        return new UnsharedConcreteFlyweight{value};
    }
}
