//
// Created by kyle on 2024/09/14.
//
module;

#include <iostream>

export module decorator.static_decorator.main;

import decorator.static_decorator.FileOutputStreamStatic;
import decorator.static_decorator.FileInputStreamStatic;


import decorator.static_decorator.EncryptedOutputStreamStatic;
import decorator.static_decorator.DecryptedInputStreamStatic;

import decorator.static_decorator.BufferedOutputStreamStatic;
import decorator.static_decorator.BufferedInputStreamStatic;


namespace decorator::static_decorator {
    auto Read() -> void {
        BufferedInputStream<DecryptedInputStream<FileInputStream>> in{"test.txt"};
        std::string text{};

        while (in.Read(text)) {
            std::cout << text << std::endl;
        }
    }

    auto Write() -> void {
        BufferedOutputStream<EncryptedOutputStream<FileOutputStream>> out{"test.txt"};
        out.Write("Using mixin to implement static decorator");
        out.Write("Decorators are chosen at compile-time");
    }

    export auto main_static() -> void {
        Write();
        Read();
    }
}
