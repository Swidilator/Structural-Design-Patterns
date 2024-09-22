//
// Created by kyle on 2024/09/22.
//
module;

export module composite.ui_composite.Widget;

namespace composite::ui_composite {
    export class Widget {
    protected:
        bool m_IsVisible{true};
    public:
        virtual auto Paint() -> void = 0;

        virtual auto SetVisibility(bool visibility) -> void = 0;

        virtual auto Add(Widget *pWidget) -> void = 0;

        virtual auto Remove(Widget *pWidget) -> void = 0;

        virtual ~Widget() = default;
    };
}
