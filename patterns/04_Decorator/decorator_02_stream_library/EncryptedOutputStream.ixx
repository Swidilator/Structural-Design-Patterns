//
// Created by kyle on 2024/09/08.
//

module;
#include <iostream>
#include <string>
#include <algorithm>


export module decorator.stream_library.EncryptedOutputStream;

import decorator.stream_library.OutputStream;
import decorator.stream_library.OutputStreamDecorator;

namespace decorator::stream_library
{
    export class EncryptedOutputStream
        : public OutputStreamDecorator
    {

    public:
        EncryptedOutputStream(OutputStream* pOS) : OutputStreamDecorator(pOS){}

        auto Write(const std::string& text) -> void
        {
            std::string encrypted{};
            encrypted.resize(text.size());
            std::transform(text.begin(), text.end(), encrypted.begin(), [](char ch)
            {
                return ch + 5;
            });
            OutputStreamDecorator::Write(encrypted);
        }

        auto Close() -> void
        {
            OutputStreamDecorator::Close();
        }
    };
}
