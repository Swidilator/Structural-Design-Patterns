//
// Created by Kyle on 2024/09/25.
//
module;

export module bridge.shapes_bridge.Renderer;

import bridge.Point;

namespace bridge::shapes_bridge
{
    export class Renderer
    {
    public:
        virtual auto RenderCircle(Point position, float radius) -> void = 0;
        virtual auto RenderLine(Point start, Point end) -> void = 0;
        virtual auto Show() -> void = 0;
        virtual ~Renderer() = default;
    };
}
