//
// Created by Kyle on 2024/06/23.
//

module;

#include <string>
#include <utility>

export module proxy.virtual_proxy.Image;

namespace proxy::virtual_proxy
{
    export class Image
    {
        std::string m_FileName;

    protected:
        void SetFileName(const std::string& fileName)
        {
            m_FileName = fileName;
        }

    public:
        Image() = default;

        Image(std::string fileName)
            : m_FileName{std::move(fileName)}
        {
        }

        [[nodiscard]] const std::string& GetFileName() const
        {
            return m_FileName;
        }

        virtual ~Image() = default;
        virtual void Display() = 0;
        virtual void Load() = 0;
        virtual void Load(const std::string& fileName) = 0;
    };
}
