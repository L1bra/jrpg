#ifndef GAME_H_
#define GAME_H_

#include "states.h"


class Game
{
private:
    void input();
    void update(float dt);
    void draw();
public:
    Game();
    ~Game();

    void start();
private:
    sf::RenderWindow m_Window;
    StateMachine gameMode;
};

#endif  // GAME_H_