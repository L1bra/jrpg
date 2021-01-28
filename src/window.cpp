#include "window.h"

Window::Window()
{    
    std::vector<sf::VideoMode> VModes = sf::VideoMode::getFullscreenModes();
    m_Window.create(VModes.at(0), "Title", sf::Style::Default | sf::Style::Fullscreen);
    m_BackgroundTexture = ResourceManager::loadTexture(Textures::Background, "src/res/background/background0.png");
    m_BackgroundSprite.setTexture(*m_BackgroundTexture);

    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    m_BackgroundSprite.setScale(targetSize.x / m_BackgroundSprite.getLocalBounds().width,
                                targetSize.y / m_BackgroundSprite.getLocalBounds().height);
}

Window::~Window()
{

}


void Window::start()
{
    sf::Clock clock;

    while(m_Window.isOpen())
    {
        sf::Event event;
        while(m_Window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                m_Window.close();
        }

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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_Player.move(Entity::Direction::Right);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_Player.move(Entity::Direction::Left);
    }
    else
    {
        m_Player.stop();
    }
}


void Window::update(float dts)
{
    m_Player.update(dts);   // update all entities 
}

void Window::draw()
{
    m_Window.clear(sf::Color::White);
    m_Window.draw(m_BackgroundSprite);
    m_Player.draw(m_Window);
    m_Window.display();
}