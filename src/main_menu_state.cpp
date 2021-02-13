#include "main_menu_state.h"


MainMenuState::MainMenuState(const StateMachine& state)
{
    m_MainMenuTexture = ResourceManager::loadTexture(Textures::MenuBackground, "src/res/background/menu_state.png");
    m_MainMenuSprite.setTexture(*m_MainMenuTexture);

    m_MenuCursorTexture = ResourceManager::loadTexture(Textures::MenuSettings, "src/res/background/menu_cursor.png");
    m_MenuCursorSprite.setTexture(*m_MenuCursorTexture);
    m_MenuCursorSprite.setTextureRect(sf::IntRect(0, 0, 51, 1));    // play button
    m_MenuCursorSprite.setScale(6.f, 6.f);                          // scale to native
    m_MenuCursorSprite.setPosition(810.f, 288.f);                   // play button coords

    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    m_MainMenuSprite.setScale(targetSize.x / m_MainMenuSprite.getLocalBounds().width, 
                            targetSize.y / m_MainMenuSprite.getLocalBounds().height);
}

MainMenuState::~MainMenuState()
{
    // destructor
}


    // play:     810 288
    // settings: 654 468
    // exit      834 648

void MainMenuState::Input(Direction direction)
{

    switch(direction)
    {
        case Up:
        {
            if(m_MenuCursorSprite.getPosition().y == 648.f)
            {
                m_MenuCursorSprite.setPosition({654.f, 468.f});
            }
            else if(m_MenuCursorSprite.getPosition().y == 468.f)
            {
                m_MenuCursorSprite.setPosition({810.f, 288.f});
            }
        } break;
        
        case Down:
        {
            if(m_MenuCursorSprite.getPosition().y == 288.f)
            {
                m_MenuCursorSprite.setPosition({654.f, 468.f});
            }
            else if(m_MenuCursorSprite.getPosition().y == 468.f)
            {
                m_MenuCursorSprite.setPosition({834.f, 648.f});
            }
        } break;
        
        case Left:
        {
            //
        } break;

        case Right:
        {
            //
        } break;
    }
}


void MainMenuState::Update(float elapsedTime)
{
    if(m_MenuCursorSprite.getPosition().y == 288.f)
    {
        m_MenuCursorSprite.setTextureRect(sf::IntRect(0, 0, 51, 1));
    }
    else if(m_MenuCursorSprite.getPosition().y == 468.f)
    {
        m_MenuCursorSprite.setTextureRect(sf::IntRect(0, 0, 102, 1));
    }
    else if(m_MenuCursorSprite.getPosition().y == 648.f)
    {
        m_MenuCursorSprite.setTextureRect(sf::IntRect(0, 0, 42, 1));
    }
}


void MainMenuState::Render(sf::RenderWindow& window)
{
    window.draw(m_MainMenuSprite);
    window.draw(m_MenuCursorSprite);
}

void MainMenuState::OnEnter()
{
    // on enter params
}

void MainMenuState::OnExit()
{
    // on exit params
}