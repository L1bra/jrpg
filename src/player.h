#ifndef PLAYER_H_
#define PLAYER_H_

#include "resource_manager.h"
#include "entity.h"

class Player : public Entity
{
public:
    Player();
    ~Player() {};

    void move(Entity::Direction direction);
    void stop();
    
    void draw(sf::RenderWindow& window) const;
    void update(float elapsed_time);
};


#endif  // PLAYER_H_