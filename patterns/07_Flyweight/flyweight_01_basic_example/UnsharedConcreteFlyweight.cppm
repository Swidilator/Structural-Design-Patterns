//
// Created by Kyle on 2024/09/28.
//
module;

export module flyweight.basic_example.UnsharedConcreteFlyweight;

import flyweight.basic_example.Flyweight;

namespace flyweight::basic_example
{
    export class UnsharedConcreteFlyweight
        : public Flyweight
    {
        int m_InternalState{};

    public:
        explicit UnsharedConcreteFlyweight(int m_internal_state)
            : m_InternalState(m_internal_state)
        {
        }

        auto Operation(int extrinsic) -> void override;
    };
}
