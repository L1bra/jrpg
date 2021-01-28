#include "resource_manager.h"

std::shared_ptr<sf::Texture> ResourceManager::loadTexture(Textures id, const sf::String& file)
{
    sf::Texture texture;
    texture.loadFromFile(file);

    std::shared_ptr<sf::Texture> texture_ptr = std::make_shared<sf::Texture>(texture);
    m_Textures.insert(std::pair<Textures, std::shared_ptr<sf::Texture>>(id, texture_ptr));
        
    return texture_ptr;
    // else ?
}

std::shared_ptr<sf::Texture> ResourceManager::getTexture(Textures id)
{
    auto texture = m_Textures.find(id);
    return texture->second; // TODO
}


void ResourceManager::free_pointers()
{
    for (auto iter = m_Textures.begin(); iter != m_Textures.end();)
    {
        if(iter->second.unique())
        {
            iter = m_Textures.erase(iter);
        }
        else
        {
            ++iter;
        }
        
    }
}

std::map<Textures, std::shared_ptr<sf::Texture>> ResourceManager::m_Textures;