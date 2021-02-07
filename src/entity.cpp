#include "entity.h"
#include "resource_manager.h"


bool Entity::operator== (const Entity& rhs) const    // ???
{
    return (m_Sprite.getTexture() == rhs.m_Sprite.getTexture());
}

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


Entity init_entity(sf::Vector2f position, sf::String sprite_path)
{
    sf::Vector2f scaleTarget(32, 32);
    
    Entity entity = {};
    entity.hp = 100;
    entity.m_Speed = 400.0f;

    entity.m_State = Entity_state::Alive;
    entity.m_Alive_state = Alive_state::Stand;
    entity.m_Position = position;
    entity.m_Texture_ptr = ResourceManager::loadTexture(Textures::Magic, sprite_path);
    entity.m_Sprite.setTexture(*entity.m_Texture_ptr);
    entity.m_Sprite.setScale(scaleTarget.x / entity.m_Sprite.getLocalBounds().width,
                        scaleTarget.y / entity.m_Sprite.getLocalBounds().height);

    return entity;
}