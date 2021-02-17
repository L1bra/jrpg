#include "entity.h"
#include "resource_manager.h"


bool Entity::operator== (const Entity& rhs) const    // am i need this ?
{
    return (m_Sprite.getTexture() == rhs.m_Sprite.getTexture());
}


void Entity::move(sf::Keyboard::Key key_code)
{
    m_Alive_state = Alive_state::Walking;
    direction = key_code;
}  


void Entity::stop()
{
    m_Alive_state = Alive_state::Stand;
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
                    switch(direction)
                    {
                        case sf::Keyboard::Right:
                        {
                            m_Sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
                            m_Position.x += m_Speed * dt;
                        } break;

                        case sf::Keyboard::Left:
                        {
                            m_Sprite.setTextureRect(sf::IntRect(24, 0, 24, 24));
                            m_Position.x -= m_Speed * dt;
                        } break;

                        case sf::Keyboard::Up:
                        {
                            m_Sprite.setTextureRect(sf::IntRect(0, 21, 24, 21));
                            m_Position.y -= m_Speed * dt;
                        } break;

                        case sf::Keyboard::Down:
                        {
                            m_Sprite.setTextureRect(sf::IntRect(24, 21, 24, 21));
                            m_Position.y += m_Speed * dt;
                        } break;
                    }
                } break;

                case Alive_state::Stand: {} break;  // TODO
            }
        } break;

        case Entity_state::Dead: {} break;  // TODO
    }

    m_Sprite.setScale(32 / m_Sprite.getLocalBounds().width, 32 / m_Sprite.getLocalBounds().height);
    m_Sprite.setPosition(m_Position);
}


void Entity::draw(sf::RenderWindow& window) const
{
    window.draw(m_Sprite);
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
    entity.m_Sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
    entity.m_Sprite.setScale(scaleTarget.x / entity.m_Sprite.getLocalBounds().width,
                        scaleTarget.y / entity.m_Sprite.getLocalBounds().height);

    return entity;
}