//
// Created by Kyle on 2024/03/08.
//

module;

export module facade.basic_example.main;

import facade.basic_example.Client;

namespace facade::basic_example
{
    export auto main_basic_example() -> void
    {
        Client c{};
        c.Invoke();
    }
}
