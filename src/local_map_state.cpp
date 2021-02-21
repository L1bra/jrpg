#include "local_map_state.h"
#include "resource_manager.h"

// forcing myself to write comments so ...

LocalMapState::LocalMapState() { /* constructor */ }

LocalMapState::~LocalMapState() { /* destructor lmao */ }

void LocalMapState::OnEnter()
{
    // on enter stuff
    m_LocalMapTexture = ResourceManager::loadTexture(Textures::LocalBackground, "src/res/background/localmap_state.png");
    m_LocalMapSprite.setTexture(*m_LocalMapTexture);

    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    m_LocalMapSprite.setScale(targetSize.x / m_LocalMapSprite.getLocalBounds().width,
                                targetSize.y / m_LocalMapSprite.getLocalBounds().height);

    init_party_entities();
}

void LocalMapState::OnExit() { /* on exit params */ }


void LocalMapState::Input(sf::Keyboard::Key key_code)
{
    switch(key_code)
    {
        case 0:
        {    
            //
        } break;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {   
        entities[PLAYER_ENTITY_INDEX].move(sf::Keyboard::Right);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        entities[PLAYER_ENTITY_INDEX].move(sf::Keyboard::Left);
    }
    else
    {
        entities[PLAYER_ENTITY_INDEX].stop();
    }
    
}

void LocalMapState::Update(float elapsedTime)
{
    for(auto& entity : entities)
    {
        if((entities[PLAYER_ENTITY_INDEX].m_Position.x - entities[PLAYER_ENTITY_INDEX - 1].m_Position.x) > 40.f)
        {
            entities[PLAYER_ENTITY_INDEX - 1].m_Sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
            entities[PLAYER_ENTITY_INDEX - 2].m_Sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));

            entities[PLAYER_ENTITY_INDEX - 1].m_Position.x += 400.f * elapsedTime;
            entities[PLAYER_ENTITY_INDEX - 2].m_Position.x += 400.f * elapsedTime;
        }
        else if((entities[PLAYER_ENTITY_INDEX].m_Position.x - entities[PLAYER_ENTITY_INDEX - 2].m_Position.x) < -40.f)
        {
            entities[PLAYER_ENTITY_INDEX - 1].m_Sprite.setTextureRect(sf::IntRect(24, 0, 24, 24));
            entities[PLAYER_ENTITY_INDEX - 2].m_Sprite.setTextureRect(sf::IntRect(24, 0, 24, 24));

            entities[PLAYER_ENTITY_INDEX - 1].m_Position.x -= 400.f * elapsedTime;
            entities[PLAYER_ENTITY_INDEX - 2].m_Position.x -= 400.f * elapsedTime;
        }

        entity.update(elapsedTime);
    }
}

void LocalMapState::Render(sf::RenderWindow& window)
{
    window.draw(m_LocalMapSprite);

    for(const auto& entity : entities)
    {
        entity.draw(window);
    }
}


void LocalMapState::init_party_entities()
{
    entities[PLAYER_ENTITY_INDEX - 2] = init_entity({32, 850}, "src/res/sprites/magic2.png");
    entities[PLAYER_ENTITY_INDEX - 1] = init_entity({72, 850}, "src/res/sprites/magic1.png");
    entities[PLAYER_ENTITY_INDEX - 0] = init_entity({112, 850}, "src/res/sprites/magic0.png");
}