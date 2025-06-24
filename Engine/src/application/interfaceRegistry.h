#ifndef INTERFACE_REGISTRY_H
#define INTERFACE_REGISTRY_H

#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include "Interface.h"

class InterfaceRegistry {
public:
    void Register(const std::string& name, std::unique_ptr<Interface> iface) {
        m_Entries.emplace_back(name, std::move(iface));
    }

    bool Exists(const std::string& name) const {
        return std::any_of(m_Entries.begin(), m_Entries.end(), [&](const auto& e) { return e.first == name; });
    }

    void EnableOnly(const std::string& name) {
        for (auto& [n, i] : m_Entries)
            i->SetActive(n == name);
    }

    void UpdateAll(float dt) {
        for (auto& [_, iface] : m_Entries)
            if (iface->IsActive()) iface->OnUpdate(dt);
    }

    void RenderAll() {
        for (auto& [_, iface] : m_Entries)
            if (iface->IsActive()) iface->OnRender();
    }

    void OnAttachAll() {
        for (auto& [_, iface] : m_Entries)
            iface->OnAttach();
    }

    void OnDetachAll() {
        for (auto& [_, iface] : m_Entries)
            iface->OnDetach();
    }

    void RenderUI() {
    for (auto& [name, iface] : m_Entries)
        iface->UIRender();
    }

    void MoveToTop(const std::string& name) {
        auto it = std::find_if(m_Entries.begin(), m_Entries.end(), [&](auto& e) { return e.first == name; });
        if (it != m_Entries.end()) {
            auto entry = std::move(*it);
            m_Entries.erase(it);
            m_Entries.push_back(std::move(entry));
        }
    }

private:
    std::vector<std::pair<std::string, std::unique_ptr<Interface>>> m_Entries;
};

#endif