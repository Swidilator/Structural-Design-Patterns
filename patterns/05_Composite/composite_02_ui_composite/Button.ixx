//
// Created by kyle on 2024/09/22.
//
module;
#include <iostream>

export module composite.ui_composite.Button;

import composite.ui_composite.Widget;

namespace composite::ui_composite {
    export class Button
            : public Widget {
    public:
        auto Paint() -> void override {
            if (m_IsVisible) {
                std::cout << "[Button] Painting...\n";
            }
        }

        auto SetVisibility(bool visibility) -> void override {
            std::cout << std::boolalpha;
            std::cout << "[Button] Visibility : " << visibility << std::endl;
            m_IsVisible = visibility;
        }

        auto Add(Widget *pWidget) -> void override {
        }

        auto Remove(Widget *pWidget) -> void override {
        }
    };
}
