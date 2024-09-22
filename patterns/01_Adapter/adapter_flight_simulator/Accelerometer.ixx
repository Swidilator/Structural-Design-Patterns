//
// Created by Kyle on 2024/03/08.
//

module;
#include <iostream>
#include <random>

export module adapter.flight_simulator.Accelerometer;

namespace adapter::flight_simulator
{
    export class Accelerometer
    {
        std::default_random_engine m_Engine;

    public:
        Accelerometer()
            : m_Engine{std::random_device{}()}
        {
        }

        auto GetHorizontalAxis() -> double
        {
            std::uniform_int_distribution<> dist{-10, 10};

            const auto value = dist(m_Engine);
            std::cout << "[Horizontal] " << value << std::endl;
            return value;
        }

        auto GetVerticalAxis() -> double
        {
            std::uniform_int_distribution<> dist{-10, 10};
            const auto value = dist(m_Engine);
            std::cout << "[Vertical] " << value << std::endl;
            return value;
        }
    };
}
