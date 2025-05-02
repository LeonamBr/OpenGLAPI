#ifndef MATERIAL_LIBRARY_H
#define MATERIAL_LIBRARY_H

#include "material.h"
#include <unordered_map>
#include <string>
#include <memory>

class MaterialLibrary {
public:
    void Add(const std::string& name, const std::shared_ptr<Material>& material);
    std::shared_ptr<Material> Get(const std::string& name);
    bool Exists(const std::string& name) const;

private:
    std::unordered_map<std::string, std::shared_ptr<Material>> m_Materials;
};

#endif