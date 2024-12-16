//
// Created by kyle on 2024/09/20.
//

module;

export module flyweight.basic_example.main;

import flyweight.basic_example.Flyweight;
import flyweight.basic_example.ConcreteFlyweight;
import flyweight.basic_example.UnsharedConcreteFlyweight;
import flyweight.basic_example.FlyweightFactory;


namespace flyweight::basic_example
{
    export auto main_basic_example() -> void
    {
        int extrinsicState = 1;
        FlyweightFactory factory;
        auto f1 = factory.GetFlyweight(1);
        auto f2 = factory.GetFlyweight(2);
        auto f3 = factory.GetFlyweight(3);

        f1->Operation(extrinsicState++);
        f2->Operation(extrinsicState++);
        f3->Operation(extrinsicState++);
    }
}
