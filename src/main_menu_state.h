#ifndef MAIN_MENU_STATE_H_
#define MAIN_MENU_STATE_H_


#include "state_machine.h"

class MainMenuState : public State
{
private:
    // private menu methods
public:
    // public methods

    MainMenuState(const StateMachine& state);
    ~MainMenuState();

    void Update(float elapsedTime);
    void Render();
    void OnEnter();
    void OnExit();
};

#endif  // MAIN_MENU_STATE_H_