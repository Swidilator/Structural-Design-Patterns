//
// Created by Kyle on 2024/07/05.
//

module;
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

export module proxy.protection_proxy.RepoProxy;

import proxy.protection_proxy.Storage;
import proxy.protection_proxy.Repository;
import proxy.protection_proxy.Employee;


namespace proxy::protection_proxy
{
    export class RepoProxy
        : public Storage
    {
        Repository* m_pRepo{};

        std::vector<std::string> m_AuthorisedRoles;

        [[nodiscard]] auto IsAuthorised() const -> bool {
            if (m_AuthorisedRoles.empty()) {
                throw std::runtime_error{"Authorised roles not set."};
            }
            return std::ranges::any_of(m_AuthorisedRoles,
                                       [this](const std::string& role) {
                                           return GetUser()->GetRole() == role;
                                       }
            );
        }

    public:
        RepoProxy(const std::string& path)
            : m_pRepo{new Repository{path}} {}

        [[nodiscard]] auto GetUser() const -> Employee* {
            return m_pRepo->GetUser();
        }

        auto SetEmployee(Employee* emp) -> void {
            m_pRepo->SetEmployee(emp);
        }

        auto SetAuthorisedRoles(std::initializer_list<std::string> authorisedRoles) -> void {
            m_AuthorisedRoles.assign(authorisedRoles);
        }

        auto CreateFile(const std::string& fileName) -> void override {
            if (IsAuthorised()) {
                m_pRepo->CreateFile(fileName);
            }
            else {
                std::cout << GetUser()->GetInfo() << " is not authorised to create a file.\n";
            }
        }

        auto DeleteFile(const std::string& fileName) -> void override {
            if (IsAuthorised()) {
                m_pRepo->DeleteFile(fileName);
            }
            else {
                std::cout << GetUser()->GetInfo() << " is not authorised to delete the file.\n";
            }
        }

        auto UpdateFile(const std::string& fileName) -> void override {
            if (IsAuthorised()) {
                m_pRepo->UpdateFile(fileName);
            }
            else {
                std::cout << GetUser()->GetInfo() << " is not authorised to update the file.\n";
            }
        }

        auto ViewFile(const std::string& fileName) -> void override {
            if (IsAuthorised()) {
                m_pRepo->ViewFile(fileName);
            }
            else {
                std::cout << GetUser()->GetInfo() << " is not authorised to view the file.\n";
            }
        }

        ~RepoProxy() override {
            delete m_pRepo;
        }
    };
}
