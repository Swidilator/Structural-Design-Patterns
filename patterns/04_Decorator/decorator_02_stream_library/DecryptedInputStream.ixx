//
// Created by kyle on 2024/09/08.
//
module;

#include <algorithm>
#include <string>

export module decorator.stream_library.DecryptedInputStream;

import decorator.stream_library.InputStream;

namespace decorator::stream_library
{
    export class DecryptedInputStream
        : public InputStream
    {
        InputStream* m_pIS;

    public:
        DecryptedInputStream(InputStream* pIS) : m_pIS(pIS) {}

        auto Read(std::string& text) -> bool
        {
            std::string encrypted{};
            const auto result = m_pIS->Read(encrypted);
            if (!encrypted.empty())
            {
                text.resize(encrypted.size());
                std::ranges::transform(encrypted, text.begin(), [](char ch)
                {
                    return ch - 5;
                });
            }
            return result;
        }

        auto Close() -> void
        {
            m_pIS->Close();
        }
    };
}
