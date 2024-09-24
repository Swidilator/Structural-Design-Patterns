//
// Created by kyle on 2024/09/24.
//
module;

export module bridge.basic_example.Abstraction;

import bridge.basic_example.Implementor;

namespace bridge::basic_example {
    export class Abstraction {
    protected:
        Implementor *m_pImplementor{};

    public:
        explicit Abstraction(Implementor *m_p_implementor)
            : m_pImplementor(m_p_implementor) {
        }

        virtual void Operation() = 0;

        virtual ~Abstraction() = default;
    };
}
