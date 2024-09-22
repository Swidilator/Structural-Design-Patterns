//
// Created by Kyle on 2024/06/23.
//

module;

#include <chrono>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include <thread>

export module proxy.smart_proxy.Bitmap;

import proxy.smart_proxy.Image;


namespace proxy::smart_proxy
{
    export class Bitmap : public Image
    {
        std::string m_Buffer{};

    public:
        using Image::Image;

        ~Bitmap() override {
            std::cout << __FUNCTION__ << std::endl;
        }

        void Display() override
        {
            std::cout << m_Buffer;
        }

        void Load() override
        {
            m_Buffer.clear();
            std::ifstream file{GetFileName()};
            if (!file)
            {
                throw std::runtime_error{"Failed to open file"};
            }
            using namespace std::chrono_literals;
            std::string line{};
            std::cout << "Loading bitmap[";
            while (std::getline(file, line))
            {
                m_Buffer += line + '\n';
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << '.';
            }
            std::cout << "] Done!\n";
        }

        void Load(const std::string& fileName) override
        {
            SetFileName(fileName);
            Load();
        }
    };
}
