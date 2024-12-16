//
// Created by Kyle on 2024/03/08.
//

module;
#include <random>

export module adapter.flight_simulator.Keyboard;

import adapter.flight_simulator.Input;


namespace adapter::flight_simulator
{
    export class Keyboard
        : public Input
    {
    public:
        Keyboard()
            : m_Engine{std::random_device{}()}
        {
        }

    private:
        std::default_random_engine m_Engine;

    public:
        auto SimulateInput() -> bool
        {
            std::bernoulli_distribution dist{.5};
            return dist(m_Engine);
        }

        auto Up() -> bool
        {
            return SimulateInput();
        }

        auto Down() -> bool
        {
            return SimulateInput();
        }

        auto Left() -> bool
        {
            return SimulateInput();
        }

        auto Right() -> bool
        {
            return SimulateInput();
        }
    };
}
