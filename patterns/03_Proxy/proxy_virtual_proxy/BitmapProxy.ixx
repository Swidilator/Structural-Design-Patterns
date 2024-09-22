//
// Created by Kyle on 2024/06/23.
//
module;

#include <iostream>
#include <string>
#include <chrono>


export module proxy.virtual_proxy.BitmapProxy;

import proxy.virtual_proxy.Image;
import proxy.virtual_proxy.Bitmap;

namespace proxy::virtual_proxy
{
    export class BitmapProxy : public Image
    {
        Bitmap* m_pBitmap{};
        std::string m_FileName;
        bool m_IsLoaded{false};

    public:
        BitmapProxy() : BitmapProxy{""}
        {
        }

        explicit BitmapProxy(const std::string& fileName)
        //: Image(fileName)
        {
            m_pBitmap = new Bitmap{fileName};
        }

        ~BitmapProxy()
        {
            delete m_pBitmap;
        }

        void Display() override
        {
            if (!m_IsLoaded)
            {
                std::cout << "[Proxy] Loading Bitmap\n";
                if (m_FileName.empty())
                {
                    m_pBitmap->Load();
                }
                else
                {
                    m_pBitmap->Load(m_FileName);
                }
                m_IsLoaded = true;
            }
            m_pBitmap->Display();
        }

        void Load() override
        {
            m_FileName.clear();
        }

        void Load(const std::string& fileName) override
        {
            m_FileName = fileName;
        }
    };
}
