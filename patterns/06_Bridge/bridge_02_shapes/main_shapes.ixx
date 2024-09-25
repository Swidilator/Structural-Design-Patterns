//
// Created by kyle on 2024/09/20.
//

module;

#include "Window.h"

export module bridge.shapes.main;

import bridge.shapes.Line;
import bridge.shapes.Circle;
import bridge.shapes.Shape;

namespace bridge::shapes
{
    auto RenderShape(Shape* pShape)
    {
        pShape->Draw();
    }

    export auto main_shapes() -> void
    {
        Window window{};
        window.Show();
        Line l{{100, 100}, {300, 300}, &window};
        RenderShape(&l);

        Circle c({500, 500}, 50, &window);
        RenderShape(&c);

        window.Run();
    }
}
