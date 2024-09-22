//
// Created by kyle on 2024/08/02.
//
module;
#include <string>


export module decorator.static_decorator.OutputStreamStatic;


namespace decorator::static_decorator {
    export class OutputStream {
    public:
        virtual auto Write(const std::string &text) -> void = 0;

        virtual auto Close() -> void = 0;

        virtual ~OutputStream() = default;
    };
}
