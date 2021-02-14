#ifndef WORLD_MAP_STATE_H_
#define WORLD_MAP_STATE_H_

#include "state_machine.h"

class WorldMapState : public State
{
private:
    // private menu methods
    std::shared_ptr<sf::Texture> m_WorldMapTexture;
    sf::Sprite m_WorldMapSprite;

    StateMachine* smp;
public:
    // public methods

    WorldMapState(StateMachine& state);
    ~WorldMapState();

    void Input(sf::Keyboard::Key key_code);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
    void OnEnter();
    void OnExit();
};

#endif  // WORLD_MAP_STATE_H_