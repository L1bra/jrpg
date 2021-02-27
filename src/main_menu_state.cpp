#include "main_menu_state.h"


MainMenuState::MainMenuState()
{
    m_MainMenuTexture = ResourceManager::loadTexture(Textures::MenuBackground, "src/res/background/menu_resume_state.png");
    m_MainMenuSprite.setTexture(*m_MainMenuTexture);

    m_MenuCursorTexture = ResourceManager::loadTexture(Textures::MenuSettings, "src/res/background/menu_cursor.png");
    m_MenuCursorSprite.setTexture(*m_MenuCursorTexture);
    m_MenuCursorSprite.setTextureRect(sf::IntRect(0, 0, button_coord.new_game_cursor, 1));
    m_MenuCursorSprite.setScale(6.f, 6.f);                                                                    // scale to native
    m_MenuCursorSprite.setPosition({button_coord.new_game.x, button_coord.new_game.y + BUTTON_OFFSET});       // New game button coords

    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    m_MainMenuSprite.setScale(targetSize.x / m_MainMenuSprite.getLocalBounds().width, 
                            targetSize.y / m_MainMenuSprite.getLocalBounds().height);
}

MainMenuState::~MainMenuState() {}


void MainMenuState::OnEnter()
{
    isClosing = false;
}


void MainMenuState::OnExit()
{
    // on exit params
}


void MainMenuState::Input(sf::Keyboard::Key key_code)
{
    switch(key_code)
    {
        case sf::Keyboard::Escape:
        {
            if(gameMode().size() >= 2)
                gameMode().Pop();   // to the last state
        } break;

        case sf::Keyboard::Up:  // TODO: "+ BUTTON_OFFSET" idea is awful 
        {
            if(m_MenuCursorSprite.getPosition().y == button_coord.new_game.y + BUTTON_OFFSET)
            {
                m_MenuCursorSprite.setPosition({button_coord.resume.x, button_coord.resume.y + BUTTON_OFFSET});
            }
            else if(m_MenuCursorSprite.getPosition().y == button_coord.save_load.y + BUTTON_OFFSET)
            {
                m_MenuCursorSprite.setPosition({button_coord.new_game.x, button_coord.new_game.y + BUTTON_OFFSET});
            }
            else if(m_MenuCursorSprite.getPosition().y == button_coord.settings.y + BUTTON_OFFSET)
            {
                m_MenuCursorSprite.setPosition({button_coord.save_load.x, button_coord.save_load.y + BUTTON_OFFSET});
            }
            else if(m_MenuCursorSprite.getPosition().y == button_coord.exit.y + BUTTON_OFFSET)
            {
                m_MenuCursorSprite.setPosition({button_coord.settings.x, button_coord.settings.y + BUTTON_OFFSET});
            }
        } break;
        
        case sf::Keyboard::Down:
        {
            if(m_MenuCursorSprite.getPosition().y == button_coord.resume.y + BUTTON_OFFSET)
            {
                m_MenuCursorSprite.setPosition({button_coord.new_game.x, button_coord.new_game.y + BUTTON_OFFSET});
            }
            else if(m_MenuCursorSprite.getPosition().y == button_coord.new_game.y + BUTTON_OFFSET)
            {
                m_MenuCursorSprite.setPosition({button_coord.save_load.x, button_coord.save_load.y + BUTTON_OFFSET});
            }
            else if(m_MenuCursorSprite.getPosition().y == button_coord.save_load.y + BUTTON_OFFSET)
            {
                m_MenuCursorSprite.setPosition({button_coord.settings.x, button_coord.settings.y + BUTTON_OFFSET});
            }
            else if(m_MenuCursorSprite.getPosition().y == button_coord.settings.y + BUTTON_OFFSET)
            {
                m_MenuCursorSprite.setPosition({button_coord.exit.x, button_coord.exit.y + BUTTON_OFFSET});
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

        case sf::Keyboard::Enter:   // TODO: add another buttons
        {
            if(m_MenuCursorSprite.getPosition().y == button_coord.resume.y + BUTTON_OFFSET)
            {
                // TODO: Hide resume button or print something like "there is no to resume u idiot..."
                if(gameMode().size() >= 2)
                    gameMode().Pop();   // to the last state
                
                // gameMode().Push("worldmap");
            }
            else if(m_MenuCursorSprite.getPosition().y == button_coord.new_game.y + BUTTON_OFFSET)
            {
                gameMode().Push("worldmap");
            }
            else if(m_MenuCursorSprite.getPosition().y == button_coord.save_load.y + BUTTON_OFFSET)
            {
                // TODO: save/load
            }
            else if(m_MenuCursorSprite.getPosition().y == button_coord.settings.y + BUTTON_OFFSET)
            {
                // TODO: settings
            }
            else if(m_MenuCursorSprite.getPosition().y == button_coord.exit.y + BUTTON_OFFSET)
            {
                isClosing = true;
            }
        } break;

    }
}


void MainMenuState::Update(float elapsedTime)
{
    if(m_MenuCursorSprite.getPosition().y == button_coord.resume.y + BUTTON_OFFSET)
    {
        m_MenuCursorSprite.setTextureRect(sf::IntRect(0, 0, button_coord.resume_cursor, 1));
    }
    else if(m_MenuCursorSprite.getPosition().y == button_coord.new_game.y + BUTTON_OFFSET)
    {
        m_MenuCursorSprite.setTextureRect(sf::IntRect(0, 0, button_coord.new_game_cursor, 1));
    }
    else if(m_MenuCursorSprite.getPosition().y == button_coord.save_load.y + BUTTON_OFFSET)
    {
        m_MenuCursorSprite.setTextureRect(sf::IntRect(0, 0, button_coord.save_load_cursor, 1));
    }
    else if(m_MenuCursorSprite.getPosition().y == button_coord.settings.y + BUTTON_OFFSET)
    {
        m_MenuCursorSprite.setTextureRect(sf::IntRect(0, 0, button_coord.settings_cursor, 1));
    }
    else if(m_MenuCursorSprite.getPosition().y == button_coord.exit.y + BUTTON_OFFSET)
    {
        m_MenuCursorSprite.setTextureRect(sf::IntRect(0, 0, button_coord.exit_cursor, 1));
    }
}


void MainMenuState::Render(sf::RenderWindow& window)
{
    if(isClosing) // ???
        window.close();
        
    window.draw(m_MainMenuSprite);
    window.draw(m_MenuCursorSprite);
}