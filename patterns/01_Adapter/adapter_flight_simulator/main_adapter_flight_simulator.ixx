//
// Created by Kyle on 2024/03/03.
//
module;

export module adapter.flight_simulator.main;

import adapter.flight_simulator.Game;
import adapter.flight_simulator.Keyboard;
import adapter.flight_simulator.AccelAdapter;

namespace adapter::flight_simulator
{
    export auto main_adapter_flight_simulator() -> void
    {
        // Keyboard k;
        //AccelObjectAdapter a;
        AccelClassAdapter a;
        Game(&a);
    }
}
