//
// Created by Kyle on 2024/07/09.
//

module;

export module proxy.smart_proxy.Pointer;

namespace proxy::smart_proxy
{
    export template <typename T>
    class Pointer
    {
        T* m_ptr;
    public:
        Pointer(T* m_ptr)
            : m_ptr(m_ptr) {}
        ~Pointer() {
            delete m_ptr;
        }

        T* Get() {
            return m_ptr;
        }

        T* operator->() {
            return m_ptr;
        }

        T& operator *() {
            return *m_ptr;
        }
    };
}