//
// Created by Kyle on 2024/09/28.
//
module;

export module flyweight.basic_example.Flyweight;

namespace flyweight::basic_example
{
    export class Flyweight
    {
    public:
        virtual void Operation(int extrinsic) = 0;
        virtual ~Flyweight() = default;
    };
}
