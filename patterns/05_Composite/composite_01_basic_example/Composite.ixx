//
// Created by kyle on 2024/09/20.
//
module;
#include <iostream>
#include <vector>
#include <algorithm>
export module composite.basic_example.Composite;

import composite.basic_example.Component;


namespace composite::basic_example {
    int depth{};

    export class Composite
            : public Component {
        std::vector<Component *> m_Children{};

    public:
        auto Operation() -> void override {
            ++depth;
            std::cout << "[Composite] Operation\n";
            for (auto pChild: m_Children) {
                for (int i = 0; i < depth; ++i) {
                    std::cout << "\t";
                }
                std::cout << "|-";
                pChild->Operation();
            }
            --depth;
        }

        auto Add(Component *pComponent) -> void override {
            m_Children.push_back(pComponent);
        }

        auto Remove(Component *pComponent) -> void override {
            auto newend = remove(begin(m_Children), end(m_Children), pComponent);
            m_Children.erase(newend, end(m_Children));
        }

        auto GetChild(int index) -> Component * override {
            return m_Children[index];
        }
    };
}
