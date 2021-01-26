#include "resource_manager.h"

std::shared_ptr<sf::Texture> ResourceManager::loadTexture(Textures id, const sf::String& file)
{
    sf::Texture texture;
    if(texture.loadFromFile(file))
    {   
        std::shared_ptr<sf::Texture> texture_ptr = std::make_shared<sf::Texture>(texture);
        this->m_Textures.insert(std::pair<Textures, std::shared_ptr<sf::Texture>>(id, texture_ptr));
        
        return texture_ptr;
    }
    // else ?
}


std::shared_ptr<sf::Texture> ResourceManager::getTexture(Textures id) const
{
    auto texture = m_Textures.find(id);
    if(texture != m_Textures.end())
    {
        return texture->second;
    }
    else
    {
        // TODO:
    }
}