// File copied directly from course material as no written in lecture
// Edited to conform to project
//  Trailing return types
//  Namespace
//  Imports instead of includes for project files
module;
#include <algorithm>
#include <iostream>

module bridge.shared_implementation.SharedString;

import bridge.shared_implementation.String;

namespace bridge::shared_implementation {
    auto SharedString::RemoveString() -> void {
        auto found = m_Strings.find(m_pString);
        if (found != m_Strings.end()) {
            if (--(*found->second) == 0) {
                delete m_pString;
                auto pCount = found->second;
                delete pCount;
                m_Strings.erase(found);
            }
        }
    }


    SharedString::SharedString(const char *pstr) {
        auto found = std::find_if(begin(m_Strings), end(m_Strings), [pstr](auto p) {
            return *p.first == pstr;
        });
        if (found != m_Strings.end()) {
            ++(*found->second);
            m_pString = found->first;
        } else {
            String *pTemp = new String{pstr};
            m_Strings[pTemp] = new size_t{1};
            m_pString = pTemp;
        }
    }

    SharedString::SharedString(const SharedString &other) {
        if (!other.m_pString)
            return;
        auto found = m_Strings.find(other.m_pString);
        if (found != m_Strings.end()) {
            m_pString = other.m_pString;
            ++(*found->second);
        }
    }

    SharedString::SharedString(SharedString &&other) noexcept {
        m_pString = other.m_pString;
        other.m_pString = nullptr;
    }

    auto SharedString::operator=(const SharedString &other) -> SharedString & {
        if (this != &other) {
            if (m_pString) {
                RemoveString();
            }
            auto found = m_Strings.find(other.m_pString);
            if (found != m_Strings.end()) {
                m_pString = other.m_pString;
                ++(*found->second);
            }
        }
        return *this;
    }

    auto SharedString::operator=(SharedString &&other) noexcept -> SharedString & {
        if (this != &other) {
            if (m_pString) {
                RemoveString();
            }
            m_pString = other.m_pString;
            other.m_pString = nullptr;
        }
        for (auto x: m_Strings) {
            std::cout << x.first->GetString() << " : " << *(x.second) << std::endl;
        }
        return *this;
    }

    SharedString::~SharedString() {
        if (m_pString)
            RemoveString();
    }

    auto SharedString::GetLength() const -> size_t {
        if (!m_pString)
            return 0;
        return m_pString->GetLength();
    }

    auto SharedString::GetString() const -> const char * {
        if (!m_pString)
            return "";
        return m_pString->GetString();
    }

    auto SharedString::Assign(const char *pstr) -> void {
        if (m_pString) {
            RemoveString();
        }
        auto found = std::find_if(begin(m_Strings), end(m_Strings), [pstr](auto p) {
            return *p.first == pstr;
        });
        if (found != m_Strings.end()) {
            ++(*found->second);
            m_pString = found->first;
        } else {
            String *pTemp = new String{pstr};
            m_Strings[pTemp] = new size_t{1};
            m_pString = pTemp;
        }
    }
}
