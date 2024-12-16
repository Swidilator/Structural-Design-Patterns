//
// Created by kyle on 2024/09/20.
//

module;
#include "GDI.h"

// Can't import this in multiple modules, breaks compilation
//#include <simple2d.h>

//#include "../Window.h"

export module bridge.shapes_bridge.main;

import bridge.shapes_bridge.Renderer;
import bridge.Point;
import bridge.shapes_bridge.Circle;
import bridge.shapes_bridge.Line;
import bridge.shapes_bridge.Shape;

import birdge.shapes_bridge.OpenGL;


namespace bridge::shapes_bridge
{
    auto RenderShape(Shape* s, Renderer* r) -> void
    {
        s->SetRenderer(r);
        s->Draw();
        r->Show();
    }

    export auto main_shapes_bridge() -> void
    {
        Line line{{100, 100}, {100, 300}};
        Circle circle{{400, 400}, 100};

        GDI gdi{};
        OpenGL open_gl{};

        RenderShape(&circle, &open_gl);
    }
}
