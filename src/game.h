#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "entity.h"


const size_t PLAYER_ENTITY_INDEX = 2;
const size_t ENEMY_ENTITY_OFFSET = 3;
const size_t MAX_ENTITIES = 4;


enum class Game_state
{
    explore = 0,
    battle
};

enum class Arrow_state
{
    stand = 0,
    move
};

enum class Arrow_Direction
{
    Right,
    Left
};


class Game
{
private:
    void input();
    void update(float dt);
    void draw();

    void init_entities();
    void kill_entity(Entity *entity);   // TODO

    void spawn_enemy();

    void spawn_arrow(sf::Vector2f position);    // TOOD
    void move_arrow(Arrow_Direction direction);
    void stop_arrow();

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
    bool enemy_spawned = false;

    Game_state m_Game_state;

    Arrow_state m_Arrow_state;  // struct Arrow ?
    Arrow_Direction arrow_move_direction;
    
    bool arrow_spawned;
    bool arrow_moved;
    float arrow_speed; 

    Entity entities[MAX_ENTITIES];


};

#endif  // GAME_H_