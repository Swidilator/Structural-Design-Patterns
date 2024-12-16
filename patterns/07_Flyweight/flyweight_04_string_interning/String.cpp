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
        std::cout << "[StringInfo] Instances:" << count << std::endl;
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

    auto String::ShowCount() -> void
    {
        std::cout << "[String] Instances:" << count << std::endl;
    }

    String::String(const char* pstr)
    {
        ++count;
        if (auto pInfo = Find(pstr); pInfo != nullptr)
        {
            AddRef(pInfo);
        }
        else
        {
            CreateNew(pstr);
        }
    }

    String::String(const String& other)
    {
        ++count;
        m_pCurrent = other.m_pCurrent;
        ++m_pCurrent->m_Count;
    }

    String::String(String&& other) noexcept
    {
        ++count;
        m_pCurrent = other.m_pCurrent;
        other.m_pCurrent = nullptr;
    }

    auto String::operator=(const String& other) -> String&
    {
        if (this != &other)
        {
            Release();
            m_pCurrent = other.m_pCurrent;
            if (m_pCurrent)
            {
                ++m_pCurrent->m_Count;
            }
        }
        return *this;
    }

    auto String::operator=(String&& other) noexcept -> String&
    {
        if (this != &other)
        {
            Release();
            m_pCurrent = other.m_pCurrent;
            other.m_pCurrent = nullptr;
        }
        return *this;
    }

    auto String::GetLength() const -> size_t
    {
        if (m_pCurrent == nullptr)
        {
            return 0;
        }
        return m_pCurrent->m_Length;
    }

    auto String::GetString() const -> const char*
    {
        if (m_pCurrent == nullptr)
        {
            return "";
        }
        return m_pCurrent->m_pBuffer;
    }

    auto String::Assign(const char* pstr) -> void
    {
        if (strcmp(pstr, m_pCurrent->m_pBuffer) == 0)
        {
            return;
        }
        if (auto pInfo = Find(pstr); pInfo != nullptr)
        {
            Release();
            AddRef(pInfo);
        }
        else
        {
            CreateNew(pstr);
        }
    }

    void String::Assign(const String& other)
    {
        if (this == &other)
        {
            return;
        }
        Release();
        m_pCurrent = other.m_pCurrent;
        if (m_pCurrent)
        {
            ++m_pCurrent->m_Count;
        }
    }

    String::~String()
    {
        --count;
        Release();
    }
}
