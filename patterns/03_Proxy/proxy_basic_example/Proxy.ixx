//
// Created by Kyle on 2024/04/07.
//
module;

#include <iostream>

export module proxy.basic_example.Proxy;

import proxy.basic_example.Subject;
import proxy.basic_example.RealSubject;

namespace proxy::basic_example
{
    export class Proxy : public Subject
    {
        RealSubject* m_pSubject{};

    public:
        void Request() override
        {
            if (m_pSubject == nullptr)
            {
                std::cout << "[Proxy] Creating RealSubject\n";
                m_pSubject = new RealSubject{};
            }

            std::cout << "[Proxy] Additional behavior\n\n";
            m_pSubject->Request();
        }

        ~Proxy()
        {
            delete m_pSubject;
        }
    };
};
