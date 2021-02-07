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

std::shared_ptr<sf::Font> ResourceManager::loadFont(Fonts id, const sf::String& file)
{
    sf::Font font;
    font.loadFromFile(file);

    std::shared_ptr<sf::Font> font_ptr = std::make_shared<sf::Font>(font);
    m_Fonts.insert(std::pair<Fonts, std::shared_ptr<sf::Font>>(id, font_ptr));

    return font_ptr;
}

std::shared_ptr<sf::Font> ResourceManager::getFont(Fonts id)
{
    auto font = m_Fonts.find(id);
    return font->second;
}

void ResourceManager::free_pointers()   // TODO: free fonts pointers
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
std::map<Fonts, std::shared_ptr<sf::Font>> ResourceManager::m_Fonts;