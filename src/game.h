#ifndef GAME_H_
#define GAME_H_


#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "entity.h"

// TODO: 
const size_t PLAYER_ENTITY_INDEX = 2;
const size_t ENEMY_ENTITY_OFFSET = 3;
const size_t ARROW_ENTITY_OFFSET = 5;
const size_t MAX_ENTITIES = 6;


enum class Game_state : uint8_t
{
    explore = 0,
    battle
};

enum class Arrow_Direction : uint8_t
{
    Right = 0,
    Left
};

enum class Choose_state : uint8_t
{
    None,
    Friend = 0,
    Enemy
};


class Game
{
private:
    void input();
    void update(float dt);
    void draw();

    void init_party_entities();
    void kill_entity(Entity *entity);   // TODO

    void spawn_enemy();
    void spawn_arrow(sf::Vector2f party_member_pos);

    void move_arrow(Arrow_Direction direction);
public:
    Game();
    ~Game();

    void start();
private:
    sf::RenderWindow m_Window;
    sf::Sprite m_BackgroundSprite;
    std::shared_ptr<sf::Texture> m_BackgroundTexture;
    
    sf::Sprite m_ArrowSprite;
    std::shared_ptr<sf::Texture> m_ArrowTexture;

    sf::Text text;
    std::shared_ptr<sf::Font> m_Font;

    Game_state m_Game_state;
    Choose_state m_Choose_state;
    
    bool arrow_spawned = false;
    bool enemy_spawned = false;

    Entity entities[MAX_ENTITIES];
};

#endif  // GAME_H_