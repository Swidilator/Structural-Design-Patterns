//
// Created by kyle on 2024/08/02.
//
module;
#include <iostream>
#include <string>

export module decorator.stream_library.BufferedInputStream;

import decorator.stream_library.InputStream;

namespace decorator::stream_library
{
    export class BufferedInputStream
        : public InputStream
    {
        InputStream* m_pIS;
        char m_Buffer[512]{};

    public:
        BufferedInputStream(InputStream* pIS) : m_pIS(pIS)
        {
        };

        auto Read(std::string& text) -> bool
        {
            auto result = m_pIS->Read(text);
            std::cout << "Buffered Read\n";
            return result;
        }

        auto Close() -> void
        {
            m_pIS->Close();
        }
    };
}
