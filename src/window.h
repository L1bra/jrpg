#include <SFML/Graphics.hpp>

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
    sf::Texture m_BackgroundTexture;
};