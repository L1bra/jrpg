#include "player.h"

Player::Player()
{
    m_Speed = 400;
    sf::Vector2f scaleTarget(54, 54);

    m_Texture_ptr = m_ResourceManager.loadTexture(Textures::Magic, "src/res/sprites/magic.png");
    
    m_Sprite.setTexture(*m_Texture_ptr);
    m_Sprite.setTextureRect( {0, 0, 16, 16});
    m_Sprite.setScale(scaleTarget.x / m_Sprite.getLocalBounds().width,
                        scaleTarget.y / m_Sprite.getLocalBounds().height);

    m_Position.x = 960;
    m_Position.y = 850;
}

Player::~Player()
{

}


sf::Sprite Player::getSprite()
{
    return m_Sprite;
}

void Player::moveLeft()
{
    m_LeftKeyPressed = true;
}


void Player::moveRight()
{
    m_RightKeyPressed = true;
}

void Player::stopLeft()
{
    m_LeftKeyPressed = false;
}

void Player::stopRight()
{
    m_RightKeyPressed = false;
}


void Player::update(float elapsed_time)
{
    // m_Sprite.setTexture(m_Texture); ?
    
    if(m_RightKeyPressed)
    {
        m_Position.x += m_Speed * elapsed_time;
    }

    if(m_LeftKeyPressed)
    {
        m_Position.x -= m_Speed * elapsed_time;
    }
    
    m_Sprite.setPosition(m_Position);
}