//
// Created by Kyle on 2024/04/07.
//
module;

#include <iostream>

export module proxy.basic_example.RealSubject;

import proxy.basic_example.Subject;

namespace proxy::basic_example
{
    export class RealSubject : public Subject
    {
    public:
        void Request() override
        {
            std::cout << "[RealSubject] Request processed\n";
        }
    };
}
