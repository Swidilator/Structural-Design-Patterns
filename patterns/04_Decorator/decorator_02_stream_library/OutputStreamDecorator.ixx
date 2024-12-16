//
// Created by kyle on 2024/09/08.
//

module;
#include <string>

export module decorator.stream_library.OutputStreamDecorator;

import decorator.stream_library.OutputStream;

namespace decorator::stream_library
{
    export class OutputStreamDecorator
        : public OutputStream
    {
        OutputStream* m_pOS;
    public:
        OutputStreamDecorator(OutputStream* pOS)
            : m_pOS(pOS)
        {

        }

        auto Write(const ::std::string& text) -> void override = 0;
        auto Close() -> void override = 0;

    };

    auto OutputStreamDecorator::Write(const ::std::string& text) -> void
    {
        m_pOS->Write(text);
    }
    auto OutputStreamDecorator::Close() -> void
    {
        m_pOS->Close();
    }
}