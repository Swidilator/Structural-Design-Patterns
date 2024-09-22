//
// Created by kyle on 2024/08/02.
//

module;
#include <string>


export module decorator.stream_library.InputStream;


namespace decorator::stream_library {
    export class InputStream {
    public:
        virtual auto Read(std::string &text) -> bool = 0;
        virtual auto Close() -> void = 0;

        virtual ~InputStream() = default;
    };
}
