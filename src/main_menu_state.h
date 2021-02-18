#ifndef MAIN_MENU_STATE_H_
#define MAIN_MENU_STATE_H_

#include "state_machine.h"


class MainMenuState : public State
{
private:
    std::shared_ptr<sf::Texture> m_MainMenuTexture;
    sf::Sprite m_MainMenuSprite;

    std::shared_ptr<sf::Texture> m_MenuCursorTexture;
    sf::Sprite m_MenuCursorSprite;

    bool isClosing;
public:
    MainMenuState();
    ~MainMenuState();

    void Input(sf::Keyboard::Key key_code);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
    void OnEnter();
    void OnExit();
};

#endif  // MAIN_MENU_STATE_H_