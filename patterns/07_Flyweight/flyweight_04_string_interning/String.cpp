//
// Created by Kyle on 2024/10/01.
//
module;
#include <cstring>

module flyweight.string_interning.String;


namespace flyweight::string_interning
{
    auto String::Allocate(const char* pstr) -> void
    {
        m_Length = strlen(pstr);
        m_pBuffer = new char[m_Length + 1];
        strcpy_s(m_pBuffer, m_Length + 1, pstr);
    }

    String::String()
    {
        m_pBuffer = new char[1]{'\0'};
    }

    String::String(const char* pstr)
    {
        Allocate(pstr);
    }

    String::String(const String& other)
    {
        Allocate(other.m_pBuffer);
    }

    String::String(String&& other) noexcept
    {
        m_Length = other.m_Length;
        m_pBuffer = other.m_pBuffer;

        other.m_Length = 0;
        other.m_pBuffer = nullptr;
    }

    auto String::operator=(const String& other) -> String&
    {
        Assign(other);
        return *this;
    }

    auto String::operator=(String&& other) noexcept -> String&
    {
        if (this != &other)
        {
            delete[] m_pBuffer;
            m_Length = other.m_Length;
            m_pBuffer = other.m_pBuffer;

            other.m_Length = 0;
            other.m_pBuffer = nullptr;
        }
        return *this;
    }

    auto String::GetLength() const -> size_t
    {
        return m_Length;
    }

    auto String::GetString() const -> const char*
    {
        return m_pBuffer;
    }

    auto String::Assign(const char* pstr) -> void
    {
        delete[] m_pBuffer;
        Allocate(pstr);
    }

    void String::Assign(const String& other)
    {
        if (this != &other)
        {
            Assign(other.m_pBuffer);
        }
    }

    String::~String()
    {
        delete[] m_pBuffer;
    }
}
