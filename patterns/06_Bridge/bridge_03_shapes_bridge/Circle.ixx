//
// Created by Kyle on 2024/09/25.
//
module;

export module bridge.shapes_bridge.Circle;
import bridge.Point;
import bridge.shapes_bridge.Shape;

namespace bridge::shapes_bridge
{
    export class Circle
        : public Shape
    {
        Point m_Position{};
        float m_Radius{};

    public:
        Circle(const Point& m_position, float m_radius)
            : m_Position(m_position),
              m_Radius(m_radius)
        {
        }

        auto Draw() -> void override
        {
            m_pRenderer->RenderCircle(m_Position, m_Radius);
        }
    };
}
