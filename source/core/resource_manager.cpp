#include "resource_manager.h"

#include <iostream>

namespace GameAi
{

namespace Core
{

namespace
{

const String ResourceDir = "resources";

}

ResourceManager::ResourceManager()
{
    
}

Texture ResourceManager::GetTextureByName(String name)
{
    auto cachedTex = m_textureCache.find(name);
    if (cachedTex != m_textureCache.end())
    {
        return cachedTex->second;
    }

    sf::Texture texture{};
    String texturePath = ResourceDir + "/" + name + ".png";
    if (texture.loadFromFile(texturePath))
    {
        m_textureCache.insert(std::pair<String, Texture>(name, texture));
    }
    else
    {
        std::cout << "Unable to locate texture " << texturePath << std::endl;
    }

    return texture;
}

}

}
