//
// Created by kyle on 2024/09/24.
//
module;

#include "../Window.h"

export module bridge.shapes.Line;

import bridge.Point;
import bridge.shapes.Shape;

namespace bridge::shapes
{
    export class Line
        : public Shape
    {
        Point m_Start{};
        Point m_End{};

        Window* m_pWindow{};

    public:
        Line(const Point& m_start, const Point& m_end, Window* pWin)
            : m_Start(m_start),
              m_End(m_end),
              m_pWindow{pWin}
        {
        }

        auto Draw() -> void
        {
            m_pWindow->DrawLine(m_Start, m_End);
        }
    };
}
