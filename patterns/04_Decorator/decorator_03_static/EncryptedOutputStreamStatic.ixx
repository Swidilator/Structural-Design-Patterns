//
// Created by kyle on 2024/09/08.
//

module;
#include <iostream>
#include <string>
#include <algorithm>
#include <concepts>


export module decorator.static_decorator.EncryptedOutputStreamStatic;

import decorator.static_decorator.TemplateConcepts;


namespace decorator::static_decorator {
    export template<OutputStreamConcept T>
    class EncryptedOutputStream
            : public T {
    public:

        template<typename... Args>
        EncryptedOutputStream(Args &&... args) : T(std::forward<Args>(args)...) {
        }

        auto Write(const std::string &text) -> void {
            std::string encrypted{};
            encrypted.resize(text.size());
            std::transform(text.begin(), text.end(), encrypted.begin(), [](char ch) {
                return ch + 5;
            });
            T::Write(encrypted);
        }

        auto Close() -> void {
            T::Close();
        }
    };
}
