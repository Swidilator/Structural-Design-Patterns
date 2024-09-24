//
// Created by kyle on 2024/09/24.
//
module;

#include "window.h"

export module bridge.shapes.Line;

import bridge.shapes.Point;

namespace bridge::shapes
{
    export class Line
    {
        Point m_Start{};
        Point m_End{};

        Window m_Window{};

    public:
        Line(const Point& m_start, const Point& m_end)
            : m_Start(m_start),
              m_End(m_end)
        {
        }

        auto Draw() -> void
        {
            m_Window.Show();
            m_Window.DrawLine(m_Start, m_End);
            m_Window.Run();
        }
    };
}
