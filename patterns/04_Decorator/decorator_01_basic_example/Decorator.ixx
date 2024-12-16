//
// Created by Kyle on 2024/07/09.
//

module;
#include <iostream>

export module decorator.basic_example.Decorator;
import decorator.basic_example.Component;


namespace decorator::basic_example
{
    export class Decorator
        : public Component
    {
        Component* m_ptr{};

    public:
        Decorator(Component* m_ptr)
            : m_ptr(m_ptr) {}

        auto Operation() -> void override {
            m_ptr->Operation();
        }
    };
}
