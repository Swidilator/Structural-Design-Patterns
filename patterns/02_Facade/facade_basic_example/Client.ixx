//
// Created by Kyle on 2024/03/08.
//

module;

export module facade.basic_example.Client;

import facade.basic_example.Facade;

namespace facade::basic_example
{
    export class Client
    {
        Facade* m_pF;

    public:
        Client()
        {
            m_pF = new Facade{};
        }

        ~Client()
        {
            delete m_pF;
        }

        auto Invoke() -> void
        {
            m_pF->Use();
        }
    };
}
