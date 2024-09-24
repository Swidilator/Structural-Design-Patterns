//
// Created by kyle on 2024/09/24.
//
module;
#include <iostream>

export module bridge.basic_example.ConcreteImplementorA;

import bridge.basic_example.Implementor;

namespace bridge::basic_example {
    export class ConcreteImplementorA
            : public Implementor {
    public:
        auto OperationImpl() -> void override {
            std::cout << "[ConcreteImplementorA] Implementation invoked\n";
        }
    };
}
