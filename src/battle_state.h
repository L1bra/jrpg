#ifndef BATTLE_STATE_H_
#define BATTLE_STATE_H_

#include "state_machine.h"


class BattleState : public State
{
private:
    // private menu methods
    std::shared_ptr<sf::Texture> m_BattleTexture;
    sf::Sprite m_BattleSprite;
public:
    // public methods

    BattleState();
    ~BattleState();

    void Input(sf::Keyboard::Key key_code);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
    void OnEnter();
    void OnExit();
};

#endif  // BATTLE_STATE_H_