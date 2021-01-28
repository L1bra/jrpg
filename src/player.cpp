#include "player.h"

Player::Player()
{
    hp = 100;
    m_Speed = 400;

    m_State = Entity_state::Alive;
    m_Alive_state = Alive_state::Walking;
    m_Position.x = 960;
    m_Position.y = 850;
    m_Texture_ptr = ResourceManager::loadTexture(Textures::Magic, "src/res/sprites/magic0.png");  // TODO
    sf::Vector2f scaleTarget(32, 32);
    m_Sprite.setTexture(*m_Texture_ptr);
    m_Sprite.setScale(scaleTarget.x / m_Sprite.getLocalBounds().width,
                        scaleTarget.y / m_Sprite.getLocalBounds().height);
}


void Player::move(Direction direction)
{
    m_Alive_state = Alive_state::Walking;
    walking_direction = direction;
}  


void Player::stop()
{
    m_Alive_state = Alive_state::Stand;
}


void Player::draw(sf::RenderWindow& window) const
{
    window.draw(m_Sprite);  // getSprite ?
}


void Player::update(float elapsed_time)
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
                            m_Position.x += m_Speed * elapsed_time;
                        } break;

                        case Left: {
                            m_Position.x -= m_Speed * elapsed_time;
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