//
// Created by Kyle on 2024/03/08.
//
module;

export module facade.basic_example.Facade;

import facade.basic_example.A;
import facade.basic_example.B;
import facade.basic_example.C;


namespace facade::basic_example
{
    export class Facade
    {
        A* m_pA;
        B* m_pB;
        C* m_pC;

    public:
        Facade()
        {
            m_pA = new A{};
            m_pB = new B{};
            m_pC = new C{};
        }

        ~Facade()
        {
            delete m_pA;
            delete m_pB;
            delete m_pC;
        }

        auto Use() -> void
        {
            m_pA->CallA();
            m_pB->CallB();
            m_pC->CallC();
        }
    };
}
