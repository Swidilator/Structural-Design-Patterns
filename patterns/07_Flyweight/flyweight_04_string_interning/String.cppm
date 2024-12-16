//
// Created by Kyle on 2024/10/01.
//
module;
#include <ostream>
export module flyweight.string_interning.String;


namespace flyweight::string_interning
{
    export class String
    {
        char* m_pBuffer{};
        size_t m_Length{};

        auto Allocate(const char* pstr) -> void;

    public:
        String();
        String(const char* pstr);

        String(const String& other);
        String(String&& other) noexcept;

        auto operator=(const String& other) -> String&;
        auto operator=(String&& other) noexcept -> String&;

        [[nodiscard]] auto GetLength() const -> size_t;
        [[nodiscard]] auto GetString() const -> const char*;

        auto Assign(const char* pstr) -> void;
        void Assign(const String& other);

        friend auto operator<<(std::ostream& os, const String& obj) -> std::ostream&
        {
            return os << obj.m_pBuffer;
        }

        ~String();
    };
}
