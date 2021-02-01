#include "game.h"
#include "resource_manager.h"
#include <algorithm>
#include <vector>

Game::Game()
{    
    std::vector<sf::VideoMode> VModes = sf::VideoMode::getFullscreenModes();
    m_Window.create(VModes.at(0), "Title", sf::Style::Default | sf::Style::Close);
    m_BackgroundTexture = ResourceManager::loadTexture(Textures::Background, "src/res/background/background0.png");
    m_BackgroundSprite.setTexture(*m_BackgroundTexture);

    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    m_BackgroundSprite.setScale(targetSize.x / m_BackgroundSprite.getLocalBounds().width,
                                targetSize.y / m_BackgroundSprite.getLocalBounds().height);


    m_ArrowTexture = ResourceManager::loadTexture(Textures::Arrow, "src/res/sprites/arrow.png");
    m_ArrowSprite.setTexture(*m_ArrowTexture);
    
    m_Game_state = Game_state::explore;
    m_Arrow_state = Arrow_state::stand;

    arrow_spawned = false;
    arrow_moved = false;
    arrow_speed = 200.0f;
}

Game::~Game()
{

}


void Game::start()
{
    sf::Clock clock;
    init_entities();
    m_Window.setKeyRepeatEnabled(false);

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

                default:
                    break;       
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) m_Window.close();

    switch(m_Game_state)
    {
        case Game_state::battle:
        {
            for(size_t i = 0; i <= PLAYER_ENTITY_INDEX; i++)
                entities[i].stop();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                move_arrow(Arrow_Direction::Right);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                move_arrow(Arrow_Direction::Left);
            }
            else
            {
                stop_arrow();
            }

        } break;

        case Game_state::explore:
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {   
                for (size_t i = 0; i <= PLAYER_ENTITY_INDEX; i++)
                    entities[i].move(Entity::Direction::Right);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                for(size_t i = 0; i <= PLAYER_ENTITY_INDEX; i++)
                    entities[i].move(Entity::Direction::Left);
            }
            else
            {
                for(size_t i = 0; i <= PLAYER_ENTITY_INDEX; i++)
                    entities[i].stop();
            } 
        } break;
    };    
}


void Game::update(float dt)
{
    for(auto &entity : entities)
    {
        entity.update(dt);
        if(entity.m_Position.x >= 700.0f && enemy_spawned == false) // ???
        {
            m_Game_state = Game_state::battle;
            spawn_enemy();
            enemy_spawned = true;
        }
    }

    if(m_Game_state == Game_state::battle && !arrow_spawned)
    {
        m_ArrowSprite.setPosition({entities[0].m_Position.x, entities[0].m_Position.y - 36});
        arrow_spawned = true;
    }
    else
    {
        switch(m_Arrow_state)
        {
            case Arrow_state::move:
            {
                switch(arrow_move_direction)
                {

                    case Arrow_Direction::Left:
                    {
                        sf::Vector2f current_arrow_pos = m_ArrowSprite.getPosition();
                        if(current_arrow_pos.x >= entities[0].m_Position.x)
                        {
                            m_ArrowSprite.setPosition({current_arrow_pos.x -= arrow_speed * dt, current_arrow_pos.y});
                        }
                    } break;

                    case Arrow_Direction::Right:
                    {
                        sf::Vector2f current_arrow_pos = m_ArrowSprite.getPosition();
                        if(current_arrow_pos.x <= entities[2].m_Position.x)
                        {
                            m_ArrowSprite.setPosition({current_arrow_pos.x += arrow_speed * dt, current_arrow_pos.y});
                        }
                    } break;
                }
            } break;

            case Arrow_state::stand : {
            } break;
        }
    }
}


void Game::draw()
{
    m_Window.clear(sf::Color::White);
    m_Window.draw(m_BackgroundSprite);

    for(auto &entity : entities)
        entity.draw(m_Window);
    
    if(arrow_spawned)
        m_Window.draw(m_ArrowSprite);
    
    m_Window.display();
}


void Game::init_entities()
{
    entities[PLAYER_ENTITY_INDEX - 2] = first_character_entity();
    entities[PLAYER_ENTITY_INDEX - 1] = second_character_entity();
    entities[PLAYER_ENTITY_INDEX - 0] = third_character_entity();
}


void Game::spawn_enemy()
{
    if(m_Game_state == Game_state::battle)
        entities[ENEMY_ENTITY_OFFSET] = enemy_entity();
}


void Game::move_arrow(Arrow_Direction direction)
{
    m_Arrow_state = Arrow_state::move;
    arrow_move_direction = direction;
}

void Game::stop_arrow()
{
    m_Arrow_state = Arrow_state::stand;
}