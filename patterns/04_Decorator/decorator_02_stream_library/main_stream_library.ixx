//
// Created by kyle on 2024/08/02.
//

module;

#include <iostream>
#include <string>

export module decorator.stream_library.main;

import decorator.stream_library.OutputStream;
import decorator.stream_library.OutputStreamDecorator;

import decorator.stream_library.FileInputStream;
import decorator.stream_library.FileOutputStream;

import decorator.stream_library.BufferedInputStream;
import decorator.stream_library.BufferedOutputStream;

import decorator.stream_library.EncryptedOutputStream;
import decorator.stream_library.DecryptedInputStream;




namespace decorator::stream_library
{

    auto Read() -> void
    {
        FileInputStream fs{"test.txt"};
        BufferedInputStream input{&fs};
        std::string text{};
        while (input.Read(text))
        {
            std::cout << text << std::endl;
        }
    }

    auto Write() -> void
    {
        FileOutputStream fs{"test.txt"};
        BufferedOutputStream output{&fs};
        output.Write("First line");
        output.Write("Second line");
        output.Write("Third line");
    }

    auto Encrypt() -> void
    {
        FileOutputStream fs{"encryption.txt"};
        EncryptedOutputStream output{&fs};
        output.Write("First line");
        output.Write("Second line");
        output.Write("Third line");
        output.Close();
    }

    auto Decrypt() -> void
    {
        FileInputStream fs{"encryption.txt"};
        DecryptedInputStream input{&fs};
        std::string text{};
        while (input.Read(text))
        {
            std::cout << text << std::endl;
        }
    }

    auto Operate(OutputStream* pOS) -> void
    {
        pOS->Write("Some text");
        pOS->Close();
    }

    export auto main_stream_library() -> void
    {
        FileOutputStream fs{"mix.txt"};
        BufferedOutputStream bs{&fs};
        EncryptedOutputStream en{&bs};

        en.Write("Some text");
        en.Close();

        FileInputStream fis{"mix.txt"};
        BufferedInputStream bis{&fis};
        DecryptedInputStream di{&bis};

        std::string text{};
        di.Read(text);
        std::cout << text << std::endl;
        di.Close();
    }
}
