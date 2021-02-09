#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include <initializer_list>
#include <map>
// #include <numeric>


class State
{
public:
    virtual ~State() {};

    virtual void Update(float elapsedTime);
    virtual void Render();
    virtual void OnEnter();
    virtual void OnExit();
};


class EmptyState : public State
{
public:
    EmptyState();
    ~EmptyState();

    void Update(float elapsedTime);
    void Render();
    void OnEnter();
    void OnExit();
};


class StateMachine
{
private:
    std::map<std::string, State*> m_States;
    State* m_CurrentState;
public:
    StateMachine();
    ~StateMachine();

    void Update(float elapsedTime);
    void Render();
    void Change(std::string stateName); // std::initializer_list<std::string> params);  // Note: template?
    void Add(std::string name, State* state);
};

#endif  // STATE_MACHINE_H_