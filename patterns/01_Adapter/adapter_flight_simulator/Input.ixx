//
// Created by Kyle on 2024/03/08.
//

export module adapter.flight_simulator.Input;

namespace adapter::flight_simulator
{
    export class Input
    {
    public:
        virtual bool Up() = 0;
        virtual bool Down() = 0;
        virtual bool Left() = 0;
        virtual bool Right() = 0;
        virtual ~Input() = default;
    };
}
