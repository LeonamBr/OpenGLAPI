#include "materialLibrary.h"
#include "log.h"

void MaterialLibrary::Add(const std::string& name, const std::shared_ptr<Material>& material) {
    if (Exists(name)) {
        LOG_WARN("Material '{0}' já existe. Substituindo.", name);
    }
    m_Materials[name] = material;
}

std::shared_ptr<Material> MaterialLibrary::Get(const std::string& name) {
    if (!Exists(name)) {
        LOG_ERROR("Material '{0}' não encontrado na MaterialLibrary.", name);
        return nullptr;
    }
    return m_Materials[name];
}

bool MaterialLibrary::Exists(const std::string& name) const {
    return m_Materials.find(name) != m_Materials.end();
}