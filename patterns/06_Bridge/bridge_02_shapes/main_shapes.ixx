//
// Created by kyle on 2024/09/20.
//

module;

// Can't import this in multiple modules, breaks compilation
//#include <simple2d.h>

#include "Window.h"

export module bridge.shapes.main;

import bridge.shapes.Line;
import bridge.shapes.Circle;
import bridge.shapes.Shape;

import bridge.shapes.all_simple2d;

namespace bridge::shapes
{
    auto RenderShape(Shape* pShape)
    {
        pShape->Draw();
    }

    auto Software() -> void
    {
        Window window{};
        window.Show();
        Line l{{100, 100}, {300, 300}, &window};
        RenderShape(&l);

        Circle c({500, 500}, 50, &window);
        RenderShape(&c);

        window.Run();
    }

    export auto main_shapes() -> void
    {
        OpenGL();
    }
}
