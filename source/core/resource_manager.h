#pragma once

#include <unordered_map>

#include <SFML/Graphics/Texture.hpp>

#include "util.h"

namespace GameAi
{

namespace Core
{

class ResourceManager 
{
public:
    ResourceManager();

    Texture GetTextureByName(String name);

private:
    Map<String, Texture> m_textureCache;

};

}

}
