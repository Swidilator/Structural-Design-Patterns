//
// Created by Kyle on 2024/09/25.
//
module;

#include <simple2d.h>


export module bridge.shapes.all_simple2d;

import bridge.shapes.Shape;
import bridge.Point;

namespace bridge::shapes
{
    export class Line_OpenGL
        : public Shape
    {
        inline static Point m_Start{};
        inline static Point m_End{};
        S2D_Window* m_pWindow{};

    public:
        Line_OpenGL(const Point& m_start, const Point& m_end, S2D_Window* m_p_window)
            : m_pWindow(m_p_window)
        {
            m_Start = m_start;
            m_End = m_end;
        }

        static auto Render() -> void
        {
            S2D_DrawLine(m_Start.x, m_Start.y, m_End.x, m_End.y, 1,
                         1, 1, 1, 1,
                         1, 1, 1, 1,
                         1, 1, 1, 1,
                         1, 1, 1, 1
            );
        }

        auto Draw() -> void override
        {
        }
    };

    export class Circle_OpenGL
        : public Shape
    {
        inline static Point m_Position{};
        inline static float m_Radius;
        S2D_Window* m_pWindow{};

    public:
        Circle_OpenGL(const Point& m_position, float m_radius, S2D_Window* m_p_window)
            : m_pWindow{m_p_window}
        {
            m_Position = m_position;
            m_Radius = m_radius;
        }

        static auto Render() -> void
        {
            S2D_DrawCircle(m_Position.x, m_Position.y, m_Radius, 128, 1, 1, 0, 1);
        }

        auto Draw() -> void override
        {
        }
    };

    export auto OpenGL() -> void
    {
        S2D_Window* pWin = S2D_CreateWindow("MainWindow", 800, 600, nullptr, &Circle_OpenGL::Render, S2D_RESIZABLE);
        //Line_OpenGL l {{100, 100}, {300, 300}, pWin};
        //l.Draw();
        Circle_OpenGL c{{300, 300}, 100, pWin};
        c.Draw();
        S2D_Show(pWin);
        S2D_FreeWindow(pWin);
    }
}
