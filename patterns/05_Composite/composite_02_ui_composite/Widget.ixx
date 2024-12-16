//
// Created by kyle on 2024/09/22.
//
module;

export module composite.ui_composite.Widget;

namespace composite::ui_composite {
    export class Widget {
        Widget *m_pParent{};

    protected:
        bool m_IsVisible{true};

    public:
        virtual auto Paint() -> void = 0;

        virtual auto SetVisibility(bool visibility) -> void = 0;

        virtual auto Add(Widget *pWidget) -> void = 0;

        virtual auto Remove(Widget *pWidget) -> void = 0;

        virtual auto GetFrame() -> Widget * {
            return nullptr;
        }

        virtual auto SetParent(Widget *p) -> void {
            m_pParent = p;
        }

        virtual auto GetParent() -> Widget * {
            return m_pParent;
        }

        virtual ~Widget() = default;
    };
}
