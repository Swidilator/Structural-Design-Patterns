//
// Created by kyle on 2024/08/02.
//

module;
#include <iostream>
#include <string>

export module decorator.stream_library.BufferedOutputStream;

import decorator.stream_library.OutputStream;
import decorator.stream_library.OutputStreamDecorator;

namespace decorator::stream_library
{
    export class BufferedOutputStream
        : public OutputStreamDecorator
    {
        char m_Buffer[512]{};

    public:
        BufferedOutputStream(OutputStream* pos)
            : OutputStreamDecorator(pos)
        {
        }

        auto Write(const std::string& text) -> void
        {
            std::cout << "Buffered Write\n";
            OutputStreamDecorator::Write(text);
        }

        auto Close() -> void
        {
            OutputStreamDecorator::Close();
        }
    };
}
