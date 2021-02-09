#ifndef LOCAL_MAP_STATE_H_
#define LOCAL_MAP_STATE_H_

#include "state_machine.h"


class LocalMapState : public State
{
private:
    // private menu methods
public:
    // public methods

    LocalMapState(const StateMachine& state);
    ~LocalMapState();

    void Update(float elapsedTime);
    void Render();
    void OnEnter();
    void OnExit();
};


#endif  // LOCAL_MAP_STATE_H_