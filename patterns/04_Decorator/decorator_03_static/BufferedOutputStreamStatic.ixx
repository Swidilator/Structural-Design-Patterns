//
// Created by kyle on 2024/08/02.
//

module;
#include <iostream>
#include <string>

export module decorator.static_decorator.BufferedOutputStreamStatic;

import decorator.static_decorator.TemplateConcepts;

namespace decorator::static_decorator {
    export template<OutputStreamConcept T>
    class BufferedOutputStream : public T {
        char m_Buffer[512]{};

    public:
        template<typename... Args>
        BufferedOutputStream(Args &&... args)
            : T(std::forward<Args>(args)...) {
        }

        auto Write(const std::string &text) -> void {
            std::cout << "Buffered Write\n";
            T::Write(text);
        }

        auto Close() -> void {
            T::Close();
        }
    };
}
