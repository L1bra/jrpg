#include "game.h"


Game::Game()
{    
    std::vector<sf::VideoMode> VModes = sf::VideoMode::getFullscreenModes();
    m_Window.create(VModes.at(0), "Title", sf::Style::Default | sf::Style::Close);
}

Game::~Game() {}


void Game::start()
{
    sf::Clock clock;

    MainMenuState menuState;
    LocalMapState localMapState;
    WorldMapState worldMapState;
    BattleState battleState;

    gameMode().Add("mainmenu", &menuState);
    gameMode().Add("worldmap", &worldMapState);
    gameMode().Add("localmap", &localMapState);
    gameMode().Add("battle", &battleState);

    gameMode().Change("mainmenu");

    while(m_Window.isOpen())
    {
        sf::Event event;
        while(m_Window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                {
                    m_Window.close();
                } break;

                case sf::Event::KeyPressed: //  Main menu and parts where single input required
                {
                    std::string mode = gameMode().GetCurrentStateName();
                    if(mode != "worldmap" || mode != "localmap")
                        gameMode().Input(event.key.code);
                } break;

                default: break;
            }
        }

        sf::Time dt = clock.restart();
        float dt_sec = dt.asSeconds();

        input();
        update(dt_sec);
        draw();
    }
}


void Game::input()
{
    gameMode().Input(sf::Keyboard::Unknown); // idk what im doing
}


void Game::update(float dt)
{
    gameMode().Update(dt);
}


void Game::draw()
{   
    m_Window.clear(sf::Color::White);
    gameMode().Render(m_Window);
    m_Window.display();
}