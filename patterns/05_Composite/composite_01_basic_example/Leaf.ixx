//
// Created by kyle on 2024/09/20.
//
module;
#include <iostream>

export module composite.basic_example.Leaf;

import composite.basic_example.Component;


namespace composite::basic_example {
    export class Leaf
            : public Component {
        auto Operation() -> void override {
            std::cout << "[Leaf] Operation invoked\n";
        }

        auto Add(Component *pComponent) -> void override {
        }

        auto Remove(Component *pComponent) -> void override {
        }

        auto GetChild(int index) -> Component * override {
            return nullptr;
        }
    };
}
