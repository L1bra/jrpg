#include "entity.h"
#include "resource_manager.h"


void Entity::move(Direction direction)
{
    m_Alive_state = Alive_state::Walking;
    walking_direction = direction;
}  


void Entity::stop()
{
    m_Alive_state = Alive_state::Stand;
}


void Entity::draw(sf::RenderWindow& window) const
{
    window.draw(m_Sprite);  // getSprite ?
}


void Entity::update(float dt)
{
    switch(m_State)
    {
        case Entity_state::Alive:
        {
            switch(m_Alive_state)
            {
                case Alive_state::Walking:
                {
                    switch(walking_direction)
                    {
                        case Right: {
                            m_Position.x += m_Speed * dt;
                        } break;

                        case Left: {
                            m_Position.x -= m_Speed * dt;
                        } break;                        
                    }
                } break;

                case Alive_state::Stand: {} break;  // TODO
            }
        } break;

        case Entity_state::Dead: {} break;  // TODO
    }

    m_Sprite.setPosition(m_Position);
}


Entity first_character_entity()
{
    sf::Vector2f scaleTarget(32, 32);
    
    Entity entity = {};
    entity.hp = 100;
    entity.m_Speed = 400;

    entity.m_State = Entity_state::Alive;
    entity.m_Alive_state = Alive_state::Stand;
    entity.m_Position = {32, 850};
    entity.m_Texture_ptr = ResourceManager::loadTexture(Textures::Magic, "src/res/sprites/magic0.png");
    entity.m_Sprite.setTexture(*entity.m_Texture_ptr);
    entity.m_Sprite.setScale(scaleTarget.x / entity.m_Sprite.getLocalBounds().width,
                        scaleTarget.y / entity.m_Sprite.getLocalBounds().height);

    return entity;
}

Entity second_character_entity()
{
    sf::Vector2f scaleTarget(32, 32);
    
    Entity entity = {};
    entity.hp = 100;
    entity.m_Speed = 400;

    entity.m_State = Entity_state::Alive;
    entity.m_Alive_state = Alive_state::Stand;
    entity.m_Position = {72, 850};
    entity.m_Texture_ptr = ResourceManager::loadTexture(Textures::Magic, "src/res/sprites/magic1.png");
    entity.m_Sprite.setTexture(*entity.m_Texture_ptr);
    entity.m_Sprite.setScale(scaleTarget.x / entity.m_Sprite.getLocalBounds().width,
                        scaleTarget.y / entity.m_Sprite.getLocalBounds().height);

    return entity;
}

Entity third_character_entity()
{
    sf::Vector2f scaleTarget(32, 32);
    
    Entity entity = {};
    entity.hp = 100;
    entity.m_Speed = 400;

    entity.m_State = Entity_state::Alive;
    entity.m_Alive_state = Alive_state::Stand;
    entity.m_Position = {112, 850};
    entity.m_Texture_ptr = ResourceManager::loadTexture(Textures::Magic, "src/res/sprites/magic2.png");
    entity.m_Sprite.setTexture(*entity.m_Texture_ptr);
    entity.m_Sprite.setScale(scaleTarget.x / entity.m_Sprite.getLocalBounds().width,
                        scaleTarget.y / entity.m_Sprite.getLocalBounds().height);

    return entity;
}


Entity enemy_entity()
{
    sf::Vector2f scaleTarget(32.0f, 32.0f);

    Entity entity = {};
    entity.hp = 100;

    entity.m_Speed = 400;
    entity.m_State = Entity_state::Alive;
    entity.m_Alive_state = Alive_state::Stand;
    entity.m_Position = {800, 850};
    entity.m_Texture_ptr = ResourceManager::loadTexture(Textures::Enemy, "src/res/sprites/enemy.png");
    entity.m_Sprite.setTexture(*entity.m_Texture_ptr);
    entity.m_Sprite.setScale(scaleTarget.x / entity.m_Sprite.getLocalBounds().width,
                        scaleTarget.y / entity.m_Sprite.getLocalBounds().height);

    return entity;
}