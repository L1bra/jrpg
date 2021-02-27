#ifndef BATTLE_STATE_H_
#define BATTLE_STATE_H_

#include "state_machine.h"
#include "entity.h"


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

    void init_party_entities();
    void init_enemy_entities();
private:
    Entity entities[MAX_ENTITIES];
};


#if 0

class BattleTick : public State
{
private:
    void Input(sf::Keyboard::Key key_code);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
    void OnEnter();
    void OnExit();
};


class BattleExecute : public State
{
private:
    void Input(sf::Keyboard::Key key_code);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
    void OnEnter();
    void OnExit();
};

#endif  // if 0

#endif  // BATTLE_STATE_H_