//
// Created by kyle on 2024/08/02.
//
module;
#include <iostream>
#include <string>

export module decorator.static_decorator.BufferedInputStreamStatic;

import decorator.static_decorator.TemplateConcepts;

namespace decorator::static_decorator {
    export template<InputStreamConcept T>
    class BufferedInputStream : public T {
        char m_Buffer[512]{};

    public:
        template<typename... Args>
        BufferedInputStream(Args &&... args)
            : T(std::forward<Args>(args)...) {
        };

        auto Read(std::string &text) -> bool {
            auto result = T::Read(text);
            std::cout << "Buffered Read\n";
            return result;
        }

        auto Close() -> void {
            T::Close();
        }
    };
}
