//
// Created by Kyle on 2024/09/28.
//
module;

export module flyweight.basic_example.ConcreteFlyweight;

import flyweight.basic_example.Flyweight;

namespace flyweight::basic_example
{
    export class ConcreteFlyweight
        : public Flyweight
    {
        int* m_pIntrinsicState{};

    public:
        explicit ConcreteFlyweight(int* m_p_intrinsic_state)
            : m_pIntrinsicState(m_p_intrinsic_state)
        {
        }

        auto Operation(int extrinsic) -> void override;
    };
}
