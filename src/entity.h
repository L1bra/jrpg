#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>
#include <memory>


enum class Entity_state
{
    Dead = 0,
    Alive
};


enum class Alive_state
{
    Stand = 0,
    Walking
};


struct Entity
{
    enum Direction
    {
        Right,
        Left
    };

    Entity_state m_State;
    Alive_state m_Alive_state;
    Direction walking_direction;

    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;
    std::shared_ptr<sf::Texture> m_Texture_ptr;

    int hp;
    float m_Speed;
};

#endif  // ENTITY_H_