#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>
#include <memory>


enum class Entity_state : uint8_t
{
    Dead = 0,
    Alive
};


enum class Alive_state : uint8_t
{
    Stand = 0,
    Walking
};

const std::size_t PLAYER_ENTITY_INDEX = 2;
const std::size_t ENEMY_ENTITY_OFFSET = 3;
const std::size_t ARROW_ENTITY_OFFSET = 5;
const std::size_t MAX_ENTITIES = 6;


struct Entity
{
    Entity_state m_State;
    Alive_state m_Alive_state;
    sf::Keyboard::Key direction;

    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;
    std::shared_ptr<sf::Texture> m_Texture_ptr;

    int hp;
    float m_Speed;

    void move(sf::Keyboard::Key key_code);
    void stop();

    void draw(sf::RenderWindow& window) const;
    void update(float dt);

    bool operator== (const Entity& rhs) const;
};

Entity init_entity(sf::Vector2f position, sf::String sprite);

#endif  // ENTITY_H_