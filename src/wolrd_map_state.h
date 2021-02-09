#ifndef WORLD_MAP_STATE_H_
#define WORLD_MAP_STATE_H_

#include "state_machine.h"

class WorldMapState : public State
{
private:
    // private menu methods
public:
    // public methods

    WorldMapState(const StateMachine& state);
    ~WorldMapState();

    void Update(float elapsedTime);
    void Render();
    void OnEnter();
    void OnExit();
};

#endif  // WORLD_MAP_STATE_H_