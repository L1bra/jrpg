#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

enum class Textures
{
    Background,
    Magic
};


class ResourceManager
{
public:
    ResourceManager() {};
    ~ResourceManager() {};

    std::shared_ptr<sf::Texture> loadTexture(Textures id, const sf::String& file);
    std::shared_ptr<sf::Texture> getTexture(Textures id) const;

private:
    std::map<Textures, std::shared_ptr<sf::Texture>> m_Textures;
};


#endif  // RECOURCES_MANAGER_H_