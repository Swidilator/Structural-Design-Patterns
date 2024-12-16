//
// Created by kyle on 2024/09/24.
//
module;
#include <iostream>

export module bridge.basic_example.ConcreteImplementorB;

import bridge.basic_example.Implementor;

namespace bridge::basic_example {
    export class ConcreteImplementorB
            : public Implementor {
    public:
        auto OperationImpl() -> void override {
            std::cout << "[ConcreteImplementorB] Implementation invoked\n";
        }
    };
}
