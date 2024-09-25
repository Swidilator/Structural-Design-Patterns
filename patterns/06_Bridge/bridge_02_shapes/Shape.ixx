//
// Created by Kyle on 2024/09/25.
//
module;

export module bridge.shapes.Shape;

namespace bridge::shapes
{
    export class Shape
    {
    public:
        virtual auto Draw() -> void = 0;
        virtual ~Shape() = default;
    };
}
