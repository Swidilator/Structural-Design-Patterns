//
// Created by Kyle on 2024/07/09.
//

module;
#include <iostream>

export module decorator.basic_example.ConcreteDecoratorB;
import decorator.basic_example.Decorator;


namespace decorator::basic_example
{
    export class ConcreteDecoratorB
        : public Decorator
    {
        using Decorator::Decorator;

    public:
        auto Operation() -> void override {
            std::cout << "[ConcreteDecoratorB] Operation invoked\n";
            Decorator::Operation();
        }
    };
}
