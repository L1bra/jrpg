#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

enum Textures
{
    Background,
    Magic,
    Enemy,

    // ?
    Arrow
};

enum Fonts
{
    Arial
};


class ResourceManager
{
public:
    static std::shared_ptr<sf::Texture> loadTexture(Textures id, const sf::String& file);
    static std::shared_ptr<sf::Texture> getTexture(Textures id);
    
    static std::shared_ptr<sf::Font> loadFont(Fonts id, const sf::String& file);
    static std::shared_ptr<sf::Font> getFont(Fonts id);

    static void free_pointers();
private:
    static std::map<Textures, std::shared_ptr<sf::Texture>> m_Textures;
    static std::map<Fonts, std::shared_ptr<sf::Font>> m_Fonts;
    ResourceManager() {};
};

#endif  // RECOURCES_MANAGER_H_