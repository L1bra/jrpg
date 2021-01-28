#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

enum Textures
{
    Background,
    Magic
};


class ResourceManager
{
public:
    static std::shared_ptr<sf::Texture> loadTexture(Textures id, const sf::String& file);
    static std::shared_ptr<sf::Texture> getTexture(Textures id) ;
    static void free_pointers();
private:
    static std::map<Textures, std::shared_ptr<sf::Texture>> m_Textures;
    ResourceManager() {};
};

#endif  // RECOURCES_MANAGER_H_