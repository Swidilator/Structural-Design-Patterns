//
// Created by Kyle on 2024/07/09.
//

module;
#include <iostream>


export module decorator.basic_example.ConcreteComponent;

import decorator.basic_example.Component;


namespace decorator::basic_example
{
    export class ConcreteComponent
        : public Component
    {
    public:
        auto Operation() -> void override {
            std::cout << "[ConcreteComponent] Operation invoked\n";
        }
    };
}
