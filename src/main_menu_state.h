#ifndef MAIN_MENU_STATE_H_
#define MAIN_MENU_STATE_H_

#include "state_machine.h"


class MainMenuState : public State
{
private:
    // private menu methods
    std::shared_ptr<sf::Texture> m_MainMenuTexture;
    sf::Sprite m_MainMenuSprite;

    std::shared_ptr<sf::Texture> m_MenuCursorTexture;
    sf::Sprite m_MenuCursorSprite;
public:
    // public methods

    MainMenuState(const StateMachine& state);
    ~MainMenuState();

    void Input(Direction direction);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
    void OnEnter();
    void OnExit();
};

#endif  // MAIN_MENU_STATE_H_