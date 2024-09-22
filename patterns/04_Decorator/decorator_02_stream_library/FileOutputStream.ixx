//
// Created by kyle on 2024/08/02.
//

module;
#include <string>
#include <fstream>


export module decorator.stream_library.FileOutputStream;

import decorator.stream_library.OutputStream;


namespace decorator::stream_library
{
    export class FileOutputStream
        : public OutputStream
    {
        std::ofstream m_Writer;

    public:
        FileOutputStream() = default;

        FileOutputStream(const std::string& fileName)
        {
            m_Writer.open(fileName);
            if (!m_Writer)
            {
                throw std::runtime_error("Could not open file for writing");
            }
        }


        auto Write(const std::string& text) -> void override
        {
            m_Writer << text << '\n';
        }

        auto Close() -> void override
        {
            if (m_Writer.is_open())
            {
                m_Writer.close();
            }
        }
    };
}
