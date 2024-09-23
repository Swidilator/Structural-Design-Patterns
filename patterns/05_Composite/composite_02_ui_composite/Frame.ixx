//
// Created by kyle on 2024/09/22.
//
module;
#include <iostream>
#include <vector>
#include <algorithm>

export module composite.ui_composite.Frame;

import composite.ui_composite.Widget;

namespace composite::ui_composite {
    int depth{};

    export class Frame
            : public Widget {
        std::vector<Widget *> m_Children{};

    public:
        auto Paint() -> void override {
            if (!m_IsVisible) {
                return;
            }
            std::cout << "[Frame] Painting...\n";
            ++depth;
            for (auto pChild: m_Children) {
                for (int i = 0; i < depth; ++i) {
                    std::cout << "\t";
                }
                pChild->Paint();
            }
            --depth;
        }

        auto SetVisibility(bool visibility) -> void override {
            ++depth;
            m_IsVisible = visibility;
            std::cout << "[Frame] Changing Visibility\n";
            for (auto pChild: m_Children) {
                for (int i = 0; i < depth; ++i) {
                    std::cout << "\t";
                }
                pChild->SetVisibility(visibility);
            }
            --depth;
        }

        auto Add(Widget *pWidget) -> void override {
            m_Children.push_back(pWidget);
            pWidget->SetParent(this);
        }

        auto Remove(Widget *pWidget) -> void override {
            pWidget->SetParent(nullptr);
            m_Children.erase(
                std::ranges::remove(m_Children, pWidget).begin(),
                end(m_Children));
        }

        auto GetFrame() -> Widget * override {
            return this;
        }

        ~Frame() override {
            for (auto pChild: m_Children) {
                delete pChild;
            }
        }
    };
}
