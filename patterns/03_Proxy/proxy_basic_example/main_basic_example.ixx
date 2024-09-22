//
// Created by Kyle on 2024/04/07.
//

module;

#include <iostream>

export module proxy.basic_example.main;

import proxy.basic_example.Subject;
import proxy.basic_example.RealSubject;
import proxy.basic_example.Proxy;

namespace proxy::basic_example
{
    auto Operate(Subject* s) -> void
    {
        //s->Request();
    }

    export auto main_basic_example() -> void
    {
        Subject* sub = new Proxy{};
        Operate(sub);
    }
}
