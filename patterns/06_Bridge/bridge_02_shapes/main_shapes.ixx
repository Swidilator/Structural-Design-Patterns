//
// Created by kyle on 2024/09/20.
//

module;

#include "Window.h"

export module bridge.shapes.main;

import bridge.shapes.Line;

namespace bridge::shapes
{
    export auto main_shapes() -> void
    {
        Line l{{100, 100}, {300, 300}};
        l.Draw();
    }
}
