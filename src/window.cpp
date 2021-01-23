#include "window.h"

Window::Window()
{
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    m_Window.create(sf::VideoMode(resolution.x, resolution.y), "Hello world", sf::Style::Fullscreen);
    m_BackgroundTexture.loadFromFile("src/res/background.jpg");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

Window::~Window()
{

}


void Window::start()
{
    sf::Clock clock;

    while(m_Window.isOpen())
    {
        sf::Time dt = clock.restart();
        float dt_sec = dt.asSeconds();

        input();
        update(dt_sec);
        draw();
    }
}


void Window::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) m_Window.close();
    
    // player move
}


void Window::update(float dt)
{
    // player update
}

void Window::draw()
{
    m_Window.clear(sf::Color::White);
    m_Window.draw(m_BackgroundSprite);
    // draw player sprite
    m_Window.display();
}