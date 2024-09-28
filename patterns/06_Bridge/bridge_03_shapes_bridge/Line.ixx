//
// Created by Kyle on 2024/09/25.
//
module;

export module bridge.shapes_bridge.Line;

import bridge.shapes_bridge.Shape;
import bridge.Point;

namespace bridge::shapes_bridge
{
    export class Line
        : public Shape
    {
        Point m_Start{};
        Point m_End{};

    public:
        Line(const Point& m_start, const Point& m_end)
            : m_Start(m_start),
              m_End(m_end)
        {
        }

        auto Draw() -> void override
        {
            m_pRenderer->RenderLine(m_Start, m_End);
        }

        [[nodiscard]] Point GetStart() const
        {
            return m_Start;
        }

        [[nodiscard]] Point GetEnd() const
        {
            return m_End;
        }
    };
}
