#ifndef LOCAL_MAP_STATE_H_
#define LOCAL_MAP_STATE_H_

#include "state_machine.h"
#include "entity.h"


class LocalMapState : public State
{
private:
    void init_party_entities();
public:
    // public methods

    LocalMapState();
    ~LocalMapState();

    void Input(sf::Keyboard::Key key_code);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
    void OnEnter();
    void OnExit();
private:
    std::shared_ptr<sf::Texture> m_LocalMapTexture;
    sf::Sprite m_LocalMapSprite;

    Entity entities[MAX_ENTITIES];
};


#endif  // LOCAL_MAP_STATE_H_