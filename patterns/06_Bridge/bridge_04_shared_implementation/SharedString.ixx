//
// Created by Kyle on 2024/09/26.
//
module;
#include <unordered_map>


export module bridge.shared_implementation.SharedString;

import bridge.shared_implementation.String;

namespace bridge::shared_implementation {
    export class SharedString {
        String *m_pString{};

        auto RemoveString() -> void;

    public:
        inline static std::unordered_map<String *, size_t *> m_Strings{};

        SharedString() = default;

        SharedString(const char *pstr);

        SharedString(const SharedString &other);

        SharedString(SharedString &&other) noexcept;

        auto operator=(const SharedString &other) -> SharedString &;

        auto operator=(SharedString &&other) noexcept -> SharedString &;

        auto GetLength() const -> size_t;

        auto GetString() const -> const char *;

        auto Assign(const char *pstr) -> void;

        ~SharedString();
    };
}
