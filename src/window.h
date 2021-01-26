#ifndef WINDOW_H_
#define WINDOW_H_

#include "player.h"
#include <vector>


class Window
{
private:
    void input();
    void update(float dt);
    void draw();
public:
    Window();
    ~Window();

    void start();

private:
    sf::RenderWindow m_Window;
    sf::Sprite m_BackgroundSprite;
    std::shared_ptr<sf::Texture> m_BackgroundTexture;

    Player m_Player;
    ResourceManager m_ResourceManager;
};

#endif  // WINDOW_H_