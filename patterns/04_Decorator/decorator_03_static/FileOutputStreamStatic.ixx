//
// Created by kyle on 2024/08/02.
//

module;
#include <string>
#include <fstream>


export module decorator.static_decorator.FileOutputStreamStatic;


namespace decorator::static_decorator {
    export class FileOutputStream {
        std::ofstream m_Writer;

    public:
        FileOutputStream() = default;

        FileOutputStream(const std::string &fileName) {
            m_Writer.open(fileName);
            if (!m_Writer) {
                throw std::runtime_error("Could not open file for writing");
            }
        }


        auto Write(const std::string &text) -> void {
            m_Writer << text << '\n';
        }

        auto Close() -> void {
            if (m_Writer.is_open()) {
                m_Writer.close();
            }
        }
    };
}
