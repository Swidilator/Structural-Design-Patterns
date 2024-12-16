//
// Created by Kyle on 2024/09/25.
//
module;

export module bridge.shapes_bridge.Shape;

import bridge.shapes_bridge.Renderer;

namespace bridge::shapes_bridge
{
    export class Shape
    {
    protected:
        Renderer* m_pRenderer{};

    public:
        auto SetRenderer(Renderer* r) -> void
        {
            m_pRenderer = r;
        }

        virtual auto Draw() -> void = 0;
        virtual ~Shape() = default;
    };
}
