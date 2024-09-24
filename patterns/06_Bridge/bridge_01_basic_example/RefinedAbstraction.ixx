//
// Created by kyle on 2024/09/24.
//
module;
#include <iostream>

export module bridge.basic_example.RefinedAbstraction;

import bridge.basic_example.Abstraction;

namespace bridge::basic_example {
    export class RefinedAbstraction
            : public Abstraction {
        using Abstraction::Abstraction;

    public:
        void Operation() override {
            std::cout << "[RefinedAbstraction] =>";
            m_pImplementor->OperationImpl();
        }
    };
}
