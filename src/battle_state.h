#ifndef BATTLE_STATE_H_
#define BATTLE_STATE_H_

#include "state_machine.h"


class BattleState : public State
{
private:
    // private menu methods
public:
    // public methods

    BattleState(const StateMachine& state);
    ~BattleState();

    void Update(float elapsedTime);
    void Render();
    void OnEnter();
    void OnExit();
};

#endif  // BATTLE_STATE_H_