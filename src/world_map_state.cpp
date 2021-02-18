#include "world_map_state.h"
#include <iostream>


WorldMapState::WorldMapState() {}

WorldMapState::~WorldMapState() {}


void WorldMapState::OnEnter()
{
    m_WorldMapTexture = ResourceManager::loadTexture(Textures::WorldBackground, "src/res/background/background0.png");
    m_WorldMapSprite.setTexture(*m_WorldMapTexture);

    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    m_WorldMapSprite.setScale(targetSize.x / m_WorldMapSprite.getLocalBounds().width,
                                targetSize.y / m_WorldMapSprite.getLocalBounds().height);

    int s = *(&entities + 1) - entities;    // debug
    printf("size of entities: %d\n", s);

    init_player_entity();
}


void WorldMapState::OnExit() { /* on exit */ }


void WorldMapState::Input(sf::Keyboard::Key key_code)   // TODO: implement paravozik-style
{
    switch(key_code)    // for single input
    {
        case sf::Keyboard::Escape:
        {
            gameMode().Change("mainmenu");  // TODO: change to local menu ?
        } break;
    }

    //  real time input for smooth movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {   
        entities[PLAYER_ENTITY_INDEX].move(sf::Keyboard::Right);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        entities[PLAYER_ENTITY_INDEX].move(sf::Keyboard::Left);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        entities[PLAYER_ENTITY_INDEX].move(sf::Keyboard::Up);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        entities[PLAYER_ENTITY_INDEX].move(sf::Keyboard::Down);
    }
    else
    {
        entities[PLAYER_ENTITY_INDEX].stop();
    }
}


void WorldMapState::Update(float elapsedTime)
{    
    for(auto &entity : entities)
    {
        entity.update(elapsedTime);
    }
}


void WorldMapState::Render(sf::RenderWindow& window)
{       
    window.draw(m_WorldMapSprite);

    for(auto &entity : entities)
    {
        entity.draw(window);
    }
}


void WorldMapState::init_player_entity()
{
    entities[PLAYER_ENTITY_INDEX] = init_entity({32, 850}, "src/res/sprites/magic0_final.png");
}




// move to battle state 

void WorldMapState::kill_entity(Entity& entity)
{
    if(entity.m_State == Entity_state::Alive)
    {
        entity.m_State = Entity_state::Dead;
    }
}


void WorldMapState::damage_entity(Entity& entity, int amount)
{
    entity.hp -= amount;
    if(entity.hp <= 0)
    {
        kill_entity(entity);
    }
}


void WorldMapState::spawn_enemy()   // move a copy to battle state
{
    entities[ENEMY_ENTITY_OFFSET] = init_entity({1200, 850}, "src/res/sprites/enemy.png");
    entities[ENEMY_ENTITY_OFFSET + 1] = init_entity({1240, 850}, "src/res/sprites/enemy.png");
}

void WorldMapState::spawn_arrow(sf::Vector2f party_member_pos) // to battle state ?
{
    entities[ARROW_ENTITY_OFFSET] = init_entity(party_member_pos, "src/res/sprites/arrow.png");
}


void WorldMapState::move_arrow(sf::Keyboard::Key key_code)
{
    switch(key_code) 
    {
        case sf::Keyboard::Left:
        {
            sf::Vector2f current_arrow_pos = entities[ARROW_ENTITY_OFFSET].m_Position;
            switch(m_Choose_state)
            {
                case Choose_state::Friend:
                {
                    if(current_arrow_pos.x == entities[PLAYER_ENTITY_INDEX - 1].m_Position.x)
                    {
                        entities[ARROW_ENTITY_OFFSET].m_Position = {entities[PLAYER_ENTITY_INDEX - 2].m_Position.x, entities[PLAYER_ENTITY_INDEX - 2].m_Position.y - 40};
                    }
                    else if(current_arrow_pos.x == entities[PLAYER_ENTITY_INDEX - 0].m_Position.x)
                    {
                        entities[ARROW_ENTITY_OFFSET].m_Position = {entities[PLAYER_ENTITY_INDEX - 1].m_Position.x, entities[PLAYER_ENTITY_INDEX - 1].m_Position.y - 40};
                    }
                } break;

                case Choose_state::Enemy:
                {
                    if(current_arrow_pos.x == entities[ENEMY_ENTITY_OFFSET + 1].m_Position.x)
                    {
                        entities[ARROW_ENTITY_OFFSET].m_Position = {entities[ENEMY_ENTITY_OFFSET].m_Position.x, entities[ENEMY_ENTITY_OFFSET].m_Position.y - 40};
                    }
                } break;
            };
        } break;

        case sf::Keyboard::Right:
        {
            sf::Vector2f current_arrow_pos = entities[ARROW_ENTITY_OFFSET].m_Position;
            switch(m_Choose_state)
            {
                case Choose_state::Friend:
                {
                    if(current_arrow_pos.x == entities[PLAYER_ENTITY_INDEX - 2].m_Position.x)
                    {
                        entities[ARROW_ENTITY_OFFSET].m_Position = {entities[PLAYER_ENTITY_INDEX - 1].m_Position.x, entities[PLAYER_ENTITY_INDEX - 1].m_Position.y - 40};
                    }
                    else if(current_arrow_pos.x == entities[PLAYER_ENTITY_INDEX - 1].m_Position.x)
                    {
                        entities[ARROW_ENTITY_OFFSET].m_Position = {entities[PLAYER_ENTITY_INDEX].m_Position.x, entities[PLAYER_ENTITY_INDEX].m_Position.y - 40};
                    }
                } break;

                case Choose_state::Enemy:
                {
                    if(current_arrow_pos.x == entities[ENEMY_ENTITY_OFFSET].m_Position.x)
                    {
                        entities[ARROW_ENTITY_OFFSET].m_Position = {entities[ENEMY_ENTITY_OFFSET + 1].m_Position.x, entities[ENEMY_ENTITY_OFFSET + 1].m_Position.y - 40};
                    }
                } break;
            };
        } break;
    }
}

Entity WorldMapState::get_current_entity()
{
    sf::Vector2f arrow_pos = get_current_arrow_pos();
    for(size_t i = 0; i <= (ENEMY_ENTITY_OFFSET + 1); i++)
    {
        if(arrow_pos == entities[i].m_Position)
        {
            return entities[i];
        }
    }
}

sf::Vector2f WorldMapState::get_current_arrow_pos()
{
    return entities[ARROW_ENTITY_OFFSET].m_Position;
}