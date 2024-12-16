//
// Created by kyle on 2024/09/08.
//
module;

#include <algorithm>
#include <string>

export module decorator.static_decorator.DecryptedInputStreamStatic;

import decorator.static_decorator.TemplateConcepts;

namespace decorator::static_decorator {
    export template<InputStreamConcept T>
    class DecryptedInputStream : public T {
    public:
        template<typename... Args>
        DecryptedInputStream(Args &&... args)
            : T(std::forward<Args>(args)...) {
        }

        auto Read(std::string &text) -> bool {
            std::string encrypted{};
            const auto result = T::Read(encrypted);
            if (!encrypted.empty()) {
                text.resize(encrypted.size());
                std::ranges::transform(encrypted, text.begin(), [](char ch) {
                    return ch - 5;
                });
            }
            return result;
        }

        auto Close() -> void {
            T::Close();
        }
    };
}
