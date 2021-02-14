#include "world_map_state.h"

WorldMapState::WorldMapState(StateMachine& state)
{
    this->smp = &state;
}

WorldMapState::~WorldMapState()
{
    // destructor
}


void WorldMapState::OnEnter()
{
    m_WorldMapTexture = ResourceManager::loadTexture(Textures::WorldBackground, "src/res/background/background0.png");
    m_WorldMapSprite.setTexture(*m_WorldMapTexture);

    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    m_WorldMapSprite.setScale(targetSize.x / m_WorldMapSprite.getLocalBounds().width,
                                targetSize.y / m_WorldMapSprite.getLocalBounds().height);
}


void WorldMapState::OnExit()
{
    // on exit
}


void WorldMapState::Update(float elapsedTime)
{
    // update world map
}


void WorldMapState::Input(sf::Keyboard::Key key_code)
{
    switch(key_code)
    {
        case sf::Keyboard::Escape:
        {
            this->smp->Change("mainmenu");  // TODO: change to local menu ?
        } break;
    }   
}


void WorldMapState::Render(sf::RenderWindow& window)
{    
    window.draw(m_WorldMapSprite);
}