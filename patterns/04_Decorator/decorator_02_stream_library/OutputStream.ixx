//
// Created by kyle on 2024/08/02.
//
module;
#include <string>


export module decorator.stream_library.OutputStream;


namespace decorator::stream_library
{
    export class OutputStream
    {
    public:
        virtual auto Write(const std::string& text) -> void = 0;
        virtual auto Close() -> void = 0;

        virtual ~OutputStream() = default;
    };
}
