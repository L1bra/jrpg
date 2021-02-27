#include "battle_state.h"

BattleState::BattleState()
{
    m_BattleTexture = ResourceManager::loadTexture(Textures::BattleBackground, "src/res/background/battle_state.png");
    m_BattleSprite.setTexture(*m_BattleTexture);

    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    m_BattleSprite.setScale(targetSize.x / m_BattleSprite.getLocalBounds().width,
                                targetSize.y / m_BattleSprite.getLocalBounds().height);
}

BattleState::~BattleState() {}

void BattleState::OnEnter()
{
    init_party_entities();
    init_enemy_entities();
}

void BattleState::OnExit()
{
    // on exit params
}

void BattleState::Input(sf::Keyboard::Key key_code)
{
    switch(key_code)
    {
        case sf::Keyboard::Escape:
        {    
            gameMode().Push("mainmenu");
        } break;
    }
}


// sleep

// #include <chrono>
// #include <thread>
// std::this_thread::sleep_for(std::chrono::milliseconds(x));

void BattleState::Update(float elapsedTime)
{
    for(auto& entity : entities)
    {
        entity.update(elapsedTime);
    }
}


void BattleState::Render(sf::RenderWindow& window)
{
    window.draw(m_BattleSprite);

    for(auto& entity : entities)
    {
        entity.draw(window);
    }
}


void BattleState::init_party_entities()
{
    entities[PLAYER_ENTITY_INDEX - 2] = init_entity({1300, 700}, "src/res/sprites/magic0.png");
    entities[PLAYER_ENTITY_INDEX - 2].m_Sprite.setTextureRect(sf::IntRect(24, 0, 24, 24));
    
    entities[PLAYER_ENTITY_INDEX - 1] = init_entity({1250, 650}, "src/res/sprites/magic1.png");
    entities[PLAYER_ENTITY_INDEX - 1].m_Sprite.setTextureRect(sf::IntRect(24, 0, 24, 24));
    
    entities[PLAYER_ENTITY_INDEX - 0] = init_entity({1200, 600}, "src/res/sprites/magic2.png");
    entities[PLAYER_ENTITY_INDEX - 0].m_Sprite.setTextureRect(sf::IntRect(24, 0, 24, 24));

}


void BattleState::init_enemy_entities()
{
    entities[PLAYER_ENTITY_INDEX + 1] = init_entity({400, 700}, "src/res/sprites/enemy.png");
    entities[PLAYER_ENTITY_INDEX + 2] = init_entity({450, 650}, "src/res/sprites/enemy.png");
    entities[PLAYER_ENTITY_INDEX + 3] = init_entity({500, 600}, "src/res/sprites/enemy.png");
}