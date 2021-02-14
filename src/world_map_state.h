#ifndef WORLD_MAP_STATE_H_
#define WORLD_MAP_STATE_H_

#include "state_machine.h"
#include "entity.h"


// TODO: 
const size_t PLAYER_ENTITY_INDEX = 2;
const size_t ENEMY_ENTITY_OFFSET = 3;
const size_t ARROW_ENTITY_OFFSET = 5;
const size_t MAX_ENTITIES = 6;


enum class Choose_state : uint8_t
{
    None,
    Friend = 0,
    Enemy
};


class WorldMapState : public State
{
private:
    void kill_entity(Entity* entity);   // TODO
    void damage_entity(Entity* entity, int amount);
    Entity get_current_entity();

    void spawn_enemy();
    void spawn_arrow(sf::Vector2f party_member_pos);

    void move_arrow(sf::Keyboard::Key key_code);
    sf::Vector2f get_current_arrow_pos();
    void init_party_entities();

public:
    WorldMapState(StateMachine& state);
    ~WorldMapState();

    void Input(sf::Keyboard::Key key_code);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
    void OnEnter();
    void OnExit();

private:
    std::shared_ptr<sf::Texture> m_WorldMapTexture;
    sf::Sprite m_WorldMapSprite;

    sf::Sprite m_ArrowSprite;
    std::shared_ptr<sf::Texture> m_ArrowTexture;

    sf::Text text;
    std::shared_ptr<sf::Font> m_Font;

    Choose_state m_Choose_state;

    bool arrow_spawned; // create better solution
    bool enemy_spawned;
    bool text_drawn;

    Entity entities[MAX_ENTITIES];  // TODO: vector ?
    
    StateMachine* smp;
};

#endif  // WORLD_MAP_STATE_H_