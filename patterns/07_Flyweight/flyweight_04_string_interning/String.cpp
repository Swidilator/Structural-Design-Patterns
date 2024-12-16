//
// Created by Kyle on 2024/10/01.
//
module;
#include <cstring>
#include <iostream>

module flyweight.string_interning.String;


namespace flyweight::string_interning
{
    StringInfo::StringInfo(const char* pstr)
    {
        m_Length = strlen(pstr);
        m_pBuffer = new char[m_Length + 1];
        strcpy_s(m_pBuffer, m_Length + 1, pstr);
        ++m_Count;
        ++count;
    }

    auto StringInfo::ShowCount() -> void
    {
        std::cout << "Instances:" << count << std::endl;
    }

    StringInfo::~StringInfo()
    {
        delete[] m_pBuffer;
        --count;
    }

    auto String::Find(const char* p) -> StringInfo*
    {
        if (auto pInfo = m_Strings.find(p); pInfo != end(m_Strings))
        {
            return pInfo->second;
        }
        return nullptr;
    }

    auto String::AddRef(StringInfo* pOther) -> void
    {
        m_pCurrent = pOther;
        ++m_pCurrent->m_Count;
    }

    auto String::CreateNew(const char* p) -> void
    {
        m_pCurrent = new StringInfo{p};
        m_Strings[p] = m_pCurrent;
    }

    auto String::Release() -> void
    {
        if (m_pCurrent == nullptr)
        {
            return;
        }
        auto pInfo = m_Strings.find(m_pCurrent->m_pBuffer);
        if (--pInfo->second->m_Count == 0)
        {
            delete m_pCurrent;
            m_Strings.erase(pInfo);
        }
        m_pCurrent = nullptr;
    }


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
