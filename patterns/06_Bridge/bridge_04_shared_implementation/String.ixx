//
// Created by Kyle on 2024/09/26.
//
module;
#include <iostream>
#include <cstddef>
#include <cstring>
#include <source_location>

export module bridge.shared_implementation.String;


namespace bridge::shared_implementation
{
#define DOTRACE
#define _CRT_SECURE_NO_WARNINGS
#ifdef DOTRACE
#define TRACETHIS std::cout << std::source_location::current().function_name() << std::endl
#else
#define TRACETHIS
#endif

    export class String
    {
        char* m_pString{};
        size_t m_Length{};

        auto Create(const char* pstr) -> void
        {
            m_Length = strlen(pstr);
            m_pString = new char[m_Length + 1];
            strcpy(m_pString, pstr);
        }

    public:
        String()
        {
            TRACETHIS;
            m_pString = new char[1]{'\0'};
        }

        String(const char* pstr)
        {
            TRACETHIS;
            Create(pstr);
        }

        String(const String& other)
        {
            TRACETHIS;
            Create(other.m_pString);
        }

        String(String&& other) noexcept
        {
            TRACETHIS;
            m_Length = other.m_Length;
            m_pString = other.m_pString;

            other.m_Length = 0;
            other.m_pString = nullptr;
        }

        auto operator=(const String& other) -> String&
        {
            TRACETHIS;
            if (this != &other)
            {
                Assign(other.m_pString);
            }
            return *this;
        }

        auto operator=(String&& other) noexcept -> String&
        {
            TRACETHIS;
            if (this != &other)
            {
                m_Length = other.m_Length;
                m_pString = other.m_pString;

                other.m_Length = 0;
                other.m_pString = nullptr;
            }
            return *this;
        }

        [[nodiscard]] auto GetLength() const -> size_t
        {
            return m_Length;
        }

        [[nodiscard]] auto GetString() const -> const char*
        {
            return m_pString;
        }

        auto Assign(const char* pstr) -> void
        {
            delete[] m_pString;
            Create(pstr);
        }

        friend auto operator <(const String& left, const String& right)
        {
            return strcmp(left.m_pString, right.m_pString) < 0;
        }

        friend auto operator >(const String& left, const String& right)
        {
            return strcmp(left.m_pString, right.m_pString) > 0;
        }

        friend auto operator !=(const String& left, const String& right)
        {
            return strcmp(left.m_pString, right.m_pString) != 0;
        }

        friend auto operator ==(const String& left, const String& right)
        {
            return strcmp(left.m_pString, right.m_pString) == 0;
        }

        friend auto operator ==(const char* left, const String& right)
        {
            return strcmp(left, right.m_pString) == 0;
        }

        friend auto operator !=(const char* left, const String& right)
        {
            return strcmp(left, right.m_pString) != 0;
        }


        ~String()
        {
            TRACETHIS;
            delete[] m_pString;
        }
    };
}
