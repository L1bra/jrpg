#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>

struct Magic
{
    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;
};


class Player
{
public:
    Player();
    ~Player();

    sf::Sprite getSprite(); // TODO: Resource manager


    void moveLeft();
    void moveRight();

    void stopLeft();
    void stopRight();

    void update(float elapsed_time);
private:
    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;

    bool m_LeftKeyPressed;
    bool m_RightKeyPressed;

    float m_Speed;
};


#endif  // PLAYER_H_