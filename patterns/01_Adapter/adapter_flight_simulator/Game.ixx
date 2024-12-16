//
// Created by Kyle on 2024/03/08.
//

module;
#include <iostream>
#include <chrono>
#include <thread>

export module adapter.flight_simulator.Game;

import adapter.flight_simulator.Input;

namespace adapter::flight_simulator
{
    export auto Game(Input* pInput)
    {
        int count{5};
        while (count != 0)
        {
            std::cout << "=====================" << std::endl;
            if (pInput->Up())
            {
                std::cout << "Pitch up" << std::endl;
            }
            else if (pInput->Down())
            {
                std::cout << "Pitch down" << std::endl;
            }
            else
            {
                std::cout << "Plane is level" << std::endl;
            }

            if (pInput->Left())
            {
                std::cout << "Plane is turning left" << std::endl;
            }
            else if (pInput->Right())
            {
                std::cout << "Plane is turning right" << std::endl;
            }
            else
            {
                std::cout << "Plane is flying straight" << std::endl;
            }
            std::cout << std::endl;
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(1s);
            --count;
        }
    }
}
