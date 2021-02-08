#include "game.h"
#include "resource_manager.h"


Game::Game()
{    
    std::vector<sf::VideoMode> VModes = sf::VideoMode::getFullscreenModes();
    m_Window.create(VModes.at(0), "Title", sf::Style::Default | sf::Style::Close);
    m_BackgroundTexture = ResourceManager::loadTexture(Textures::Background, "src/res/background/background0.png");
    m_BackgroundSprite.setTexture(*m_BackgroundTexture);

    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    m_BackgroundSprite.setScale(targetSize.x / m_BackgroundSprite.getLocalBounds().width,
                                targetSize.y / m_BackgroundSprite.getLocalBounds().height);

    m_Font = ResourceManager::loadFont(Fonts::Arial, "src/res/fonts/arial.ttf");
    text.setFont(*m_Font);
    text.setString("Choose the character with LEFT and RIGHT keys\n\t\t\t\t\t and press ENTER");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition({650, 650});
    
    m_Game_state = Game_state::explore;
    m_Choose_state = Choose_state::Friend;
}

Game::~Game()
{

}


void Game::start()
{
    sf::Clock clock;
    init_party_entities();
    // m_Window.setKeyRepeatEnabled(false);

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

                case sf::Event::KeyPressed:
                {
                    if(m_Game_state == Game_state::battle)
                    {
                        if(event.key.code == sf::Keyboard::Enter)
                        {
                            // printf("%s\n", friend_chosen ? "true" : "false");

                            if(!text_drawn)
                                text_drawn = true;  // TODO: draw second string

                            switch(m_Choose_state)
                            {
                                case Choose_state::Enemy :
                                {
                                    auto entity = get_current_entity();
                                    damage_entity(&entity, 100);
                                    entities[ARROW_ENTITY_OFFSET].m_Position = {entities[PLAYER_ENTITY_INDEX - 2].m_Position.x, entities[PLAYER_ENTITY_INDEX - 2].m_Position.y - 40};
                                    m_Choose_state = Choose_state::Friend;
                                } break;

                                case Choose_state::Friend :
                                {
                                    auto entity = get_current_entity();
                                    damage_entity(&entity, 100);
                                    entities[ARROW_ENTITY_OFFSET].m_Position = {entities[ENEMY_ENTITY_OFFSET].m_Position.x, entities[ENEMY_ENTITY_OFFSET].m_Position.y - 40};
                                    m_Choose_state = Choose_state::Enemy;
                                } break;
                            }                         
                        }
                        else if(event.key.code == sf::Keyboard::Left)
                        {
                            move_arrow(Arrow_Direction::Left);
                        }
                        else if(event.key.code == sf::Keyboard::Right)
                        {
                            move_arrow(Arrow_Direction::Right);
                        }
                    }
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) m_Window.close();

    switch(m_Game_state)
    {
        case Game_state::battle:
        {   
            // TODO:
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
        if(entity.m_State == Entity_state::Alive)
            entity.update(dt);
        
        if(entity.m_Position.x >= 700.0f && !enemy_spawned) // ???
        {
            m_Game_state = Game_state::battle;
            spawn_enemy();
            enemy_spawned = true;
        }
    }

    if(m_Game_state == Game_state::battle)
    {
        for(size_t i = 0; i <= PLAYER_ENTITY_INDEX; i++)
            entities[i].stop();
        
        if(!arrow_spawned)
        {
            spawn_arrow({entities[PLAYER_ENTITY_INDEX - 1].m_Position.x, entities[PLAYER_ENTITY_INDEX - 2].m_Position.y - 36});
            arrow_spawned = true;
        }
    }
}


void Game::draw()
{
    m_Window.clear(sf::Color::White);
    m_Window.draw(m_BackgroundSprite);

    for(auto &entity : entities)
    {
        if(entity.m_State == Entity_state::Alive)
        {
            entity.draw(m_Window);
        }        
    }

    if(m_Game_state == Game_state::battle && !text_drawn)
    {
        m_Window.draw(text);
    }

    m_Window.display();
}


void Game::init_party_entities()
{
    entities[PLAYER_ENTITY_INDEX - 2] = init_entity({32, 850}, "src/res/sprites/magic0.png");
    entities[PLAYER_ENTITY_INDEX - 1] = init_entity({72, 850}, "src/res/sprites/magic1.png");
    entities[PLAYER_ENTITY_INDEX - 0] = init_entity({112, 850}, "src/res/sprites/magic2.png");
}


void Game::kill_entity(Entity* entity)
{
    if(entity->m_State == Entity_state::Alive)
    {
        entity->m_State = Entity_state::Dead;
    }
}


void Game::damage_entity(Entity *entity, int amount)
{
    entity->hp -= amount;
    if(entity->hp <= 0)
    {
        kill_entity(entity);
    }
}


void Game::spawn_enemy()
{
    if(m_Game_state == Game_state::battle)
    {
        entities[ENEMY_ENTITY_OFFSET] = init_entity({1200, 850}, "src/res/sprites/enemy.png");
        entities[ENEMY_ENTITY_OFFSET + 1] = init_entity({1240, 850}, "src/res/sprites/enemy.png");
    }
}

void Game::spawn_arrow(sf::Vector2f party_member_pos)
{
    if(m_Game_state == Game_state::battle)
    {
        entities[ARROW_ENTITY_OFFSET] = init_entity(party_member_pos, "src/res/sprites/arrow.png");
    }
}


void Game::move_arrow(Arrow_Direction direction)
{
    if(m_Game_state == Game_state::battle)
    {
        switch(direction) 
        {
            case Arrow_Direction::Left:
            {
                sf::Vector2f current_arrow_pos = entities[ARROW_ENTITY_OFFSET].m_Position;
                switch(m_Choose_state)
                {
                    case Choose_state::Friend:
                    {
                        if(current_arrow_pos.x == entities[PLAYER_ENTITY_INDEX - 1].m_Position.x)
                        {
                            entities[ARROW_ENTITY_OFFSET].m_Position = {entities[PLAYER_ENTITY_INDEX - 2].m_Position.x, entities[PLAYER_ENTITY_INDEX - 2].m_Position.y - 40};
                        }
                        else if(current_arrow_pos.x == entities[PLAYER_ENTITY_INDEX - 0].m_Position.x)
                        {
                            entities[ARROW_ENTITY_OFFSET].m_Position = {entities[PLAYER_ENTITY_INDEX - 1].m_Position.x, entities[PLAYER_ENTITY_INDEX - 1].m_Position.y - 40};
                        }
                    } break;

                    case Choose_state::Enemy:
                    {
                        if(current_arrow_pos.x == entities[ENEMY_ENTITY_OFFSET + 1].m_Position.x)
                        {
                            entities[ARROW_ENTITY_OFFSET].m_Position = {entities[ENEMY_ENTITY_OFFSET].m_Position.x, entities[ENEMY_ENTITY_OFFSET].m_Position.y - 40};
                        }
                    } break;
                };
            } break;

            case Arrow_Direction::Right:
            {
                sf::Vector2f current_arrow_pos = entities[ARROW_ENTITY_OFFSET].m_Position;
                switch(m_Choose_state)
                {
                    case Choose_state::Friend:
                    {
                        if(current_arrow_pos.x == entities[PLAYER_ENTITY_INDEX - 2].m_Position.x)
                        {
                            entities[ARROW_ENTITY_OFFSET].m_Position = {entities[PLAYER_ENTITY_INDEX - 1].m_Position.x, entities[PLAYER_ENTITY_INDEX - 1].m_Position.y - 40};
                        }
                        else if(current_arrow_pos.x == entities[PLAYER_ENTITY_INDEX - 1].m_Position.x)
                        {
                            entities[ARROW_ENTITY_OFFSET].m_Position = {entities[PLAYER_ENTITY_INDEX].m_Position.x, entities[PLAYER_ENTITY_INDEX].m_Position.y - 40};
                        }
                    } break;

                    case Choose_state::Enemy:
                    {
                        if(current_arrow_pos.x == entities[ENEMY_ENTITY_OFFSET].m_Position.x)
                        {
                            entities[ARROW_ENTITY_OFFSET].m_Position = {entities[ENEMY_ENTITY_OFFSET + 1].m_Position.x, entities[ENEMY_ENTITY_OFFSET + 1].m_Position.y - 40};
                        }
                    } break;
                };
            } break;
        }
    }
}

Entity Game::get_current_entity()
{
    sf::Vector2f arrow_pos = get_current_arrow_pos();
    for(size_t i = 0; i <= (ENEMY_ENTITY_OFFSET + 1); i++)
    {
        if(arrow_pos == entities[i].m_Position)
        {
            return entities[i];
        }
    }
}

sf::Vector2f Game::get_current_arrow_pos()
{
    return entities[ARROW_ENTITY_OFFSET].m_Position;
}