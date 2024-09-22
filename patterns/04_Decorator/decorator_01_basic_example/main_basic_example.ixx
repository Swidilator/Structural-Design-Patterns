//
// Created by Kyle on 2024/04/07.
//

module;

export module decorator.basic_example.main;

import decorator.basic_example.Component;
import decorator.basic_example.ConcreteComponent;
import decorator.basic_example.ConcreteDecoratorA;
import decorator.basic_example.ConcreteDecoratorB;


namespace decorator::basic_example
{
    auto Operate(Component* c) -> void {
        c->Operation();
    }
    export auto main_basic_example() -> void {
        ConcreteComponent component{};
        ConcreteDecoratorA decA{&component};
        //decA.Operation();
        ConcreteDecoratorB decB{&decA};
        //decB.Operation();

        Operate(&decB);
    }
}
