#include "main_menu_state.h"


MainMenuState::MainMenuState(){}

MainMenuState::~MainMenuState() {}


void MainMenuState::OnEnter()
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
    isClosing = false;
}


void MainMenuState::OnExit()
{
    // on exit params
}


// play:     810 288
// settings: 654 468
// exit      834 648

void MainMenuState::Input(sf::Keyboard::Key key_code)   // pass StateMachine ?
{
    switch(key_code)
    {
        case sf::Keyboard::Up:
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
        
        case sf::Keyboard::Down:
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
        
        case sf::Keyboard::Left:
        {
            //
        } break;

        case sf::Keyboard::Right:
        {
            //
        } break;

        case sf::Keyboard::Enter:
        {
            if(m_MenuCursorSprite.getPosition().y == 288.f)  // play button
            {
                gameMode().Change("worldmap");
            }
            else if(m_MenuCursorSprite.getPosition().y == 468.f)
            {
                // TODO: settings
            }
            else
            {
                isClosing = true;
            }
            
        } break;

        case sf::Keyboard::Escape:
        {
            // to the last state
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
    if(isClosing) // ???
        window.close();
        
    window.draw(m_MainMenuSprite);
    window.draw(m_MenuCursorSprite);
}