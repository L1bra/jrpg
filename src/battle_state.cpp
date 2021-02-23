#include "battle_state.h"

BattleState::BattleState() {}

BattleState::~BattleState() {}

void BattleState::OnEnter()
{
    m_BattleTexture = ResourceManager::loadTexture(Textures::BattleBackground, "src/res/background/battle_state.png");
    m_BattleSprite.setTexture(*m_BattleTexture);

    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    m_BattleSprite.setScale(targetSize.x / m_BattleSprite.getLocalBounds().width,
                                targetSize.y / m_BattleSprite.getLocalBounds().height);
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

void BattleState::Update(float elapsedTime)
{
    // update local map
}

void BattleState::Render(sf::RenderWindow& window)
{
    window.draw(m_BattleSprite);
}
