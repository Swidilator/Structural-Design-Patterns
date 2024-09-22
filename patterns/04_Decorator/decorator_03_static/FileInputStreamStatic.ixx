//
// Created by kyle on 2024/08/02.
//
module;

#include <fstream>
#include <string>

export module decorator.static_decorator.FileInputStreamStatic;

namespace decorator::static_decorator {
    export class FileInputStream {
        std::ifstream m_Reader;

    public:
        FileInputStream() = default;

        FileInputStream(const std::string &fileName) {
            m_Reader.open(fileName);

            if (!m_Reader) {
                throw std::runtime_error{"Could not open the file for reading"};
            }
        }

        auto Read(std::string &text) -> bool {
            text.clear();
            std::getline(m_Reader, text);
            return !text.empty();
        }

        auto Close() -> void {
            if (m_Reader.is_open()) {
                m_Reader.close();
            }
        }
    };
}
