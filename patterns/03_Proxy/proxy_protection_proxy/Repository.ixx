//
// Created by Kyle on 2024/06/30.
//
module;
#include <filesystem>
#include <fstream>
#include <iostream>

export module proxy.protection_proxy.Repository;

import proxy.protection_proxy.Storage;
import proxy.protection_proxy.Employee;


namespace proxy::protection_proxy
{
    export class Repository
        : public Storage
    {
        Employee* m_pEmp;
        std::filesystem::path m_CurrentPath{};

    public:
        [[nodiscard]] Employee* GetUser() const {
            return m_pEmp;
        }

        void SetEmployee(Employee* p) {
            m_pEmp = p;
        }

        Repository(const std::string& repoPath)
            : m_CurrentPath{repoPath} {}

        auto CreateFile(const std::string& fileName) -> void override {
            auto path = m_CurrentPath;
            path /= fileName;
            std::ofstream out{path};
            if (!out.is_open()) {
                throw std::runtime_error{"Could not create file."};
            }
            std::cout << GetUser()->GetInfo() << "is creating a file\n";
            std::string fileData;
            std::cout << "[CREATE] Enter data:";
            getline(std::cin, fileData);
            out << fileData;
            std::cout << "File created successfully";
        }

        void DeleteFile(const std::string& fileName) override {
            auto path = m_CurrentPath;
            path /= fileName;
            if (!exists(path)) {
                throw std::runtime_error{"File does not exist."};
            }
            std::cout << GetUser()->GetInfo() << "is deleting a file\n";
            if (std::filesystem::remove(path)) {
                std::cout << "File deleted successfully\n";
            }
        }

        void UpdateFile(const std::string& fileName) override {
            auto path = m_CurrentPath;
            path /= fileName;
            std::ofstream out{path, out.app};
            if (!out.is_open()) {
                throw std::runtime_error{"Could not update file."};
            }
            std::cout << GetUser()->GetInfo() << "is updating a file\n";
            std::string fileData;
            std::cout << "[UPDATE] Enter data:";
            std::getline(std::cin, fileData);
            out << "\n##### UPDATE #####\n" << fileData;
            std::cout << "File updated successfully!\n";
        }

        void ViewFile(const std::string& fileName) override {
            auto path = m_CurrentPath;
            path /= fileName;
            std::ifstream in{path};
            if (!in.is_open()) {
                throw std::runtime_error{"Could not open file."};
            }
            std::cout << GetUser()->GetInfo() << "is viewing a file\n";
            std::string line;
            while (std::getline(in, line)) {
                std::cout << line << '\n';
            }
        }
    };
}
