//
// Created by Kyle on 2024/06/30.
//

module;
#include <string>

export module proxy.protection_proxy.Storage;


namespace proxy::protection_proxy
{
    export class Storage
    {
    public:
        virtual void CreateFile(const std::string& fileName) = 0;
        virtual void DeleteFile(const std::string& fileName) = 0;
        virtual void UpdateFile(const std::string& fileName) = 0;
        virtual void ViewFile(const std::string& fileName) = 0;
        virtual ~Storage() = default;
    };
}
