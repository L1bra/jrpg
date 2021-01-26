#ifndef PLAYER_H_
#define PLAYER_H_

#include "resource_manager.h"
#include "animation.h"

class Player
{
public:
    Player();
    ~Player();

    sf::Sprite getSprite();

    void moveLeft();
    void moveRight();

    void stopLeft();
    void stopRight();

    void update(float elapsed_time);
private:
    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;
    std::shared_ptr<sf::Texture> m_Texture_ptr;

    bool m_LeftKeyPressed;
    bool m_RightKeyPressed;

    float m_Speed;

    ResourceManager m_ResourceManager;
};


#endif  // PLAYER_H_