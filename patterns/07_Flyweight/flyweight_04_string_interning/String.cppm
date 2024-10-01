//
// Created by Kyle on 2024/10/01.
//
module;
#include <ostream>
#include <unordered_map>
#include <string_view>
export module flyweight.string_interning.String;


namespace flyweight::string_interning
{
    export struct StringInfo
    {
        char* m_pBuffer{};
        size_t m_Length{};
        size_t m_Count{};
        inline static int count{};
        explicit StringInfo(const char* pstr);
        ~StringInfo();
        static auto ShowCount() -> void;
    };


    export class String
    {
        StringInfo* m_pCurrent{};
        inline static std::unordered_map<std::string_view, StringInfo*> m_Strings{};
        [[nodiscard]] auto Find(const char* p) -> StringInfo*;
        auto AddRef(StringInfo* pOther) -> void;
        auto CreateNew(const char* p) -> void;
        auto Release() -> void;
        inline static int count{};

    public:
        static auto ShowCount() -> void;
        String() = default;
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
            return os << obj.m_pCurrent->m_pBuffer;
        }

        ~String();
    };
}
