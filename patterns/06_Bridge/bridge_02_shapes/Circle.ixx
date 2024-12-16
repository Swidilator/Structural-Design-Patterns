//
// Created by Kyle on 2024/09/25.
//
module;
#include "Window.h"

export module bridge.shapes.Circle;

import bridge.shapes.Point;
import bridge.shapes.Shape;

namespace bridge::shapes
{
    export class Circle
        : public Shape
    {
        Point m_Position{};
        float m_Radius{};
        Window* m_pWindow{};

    public:
        Circle(const Point& m_position, float m_radius, Window* m_p_window)
            : m_Position(m_position),
              m_Radius(m_radius),
              m_pWindow(m_p_window)
        {
        }

        auto Draw() -> void override
        {
            m_pWindow->DrawCircle(m_Position, m_Radius);
        }
    };
}
