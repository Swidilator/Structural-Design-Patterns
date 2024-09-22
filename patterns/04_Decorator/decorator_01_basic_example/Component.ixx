//
// Created by Kyle on 2024/07/09.
//

module;

export module decorator.basic_example.Component;


namespace decorator::basic_example
{
    export class Component
    {
    public:
        virtual auto Operation() -> void = 0;
        virtual ~Component() = default;
    };
}
