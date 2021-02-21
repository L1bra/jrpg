#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include "resource_manager.h"

#include <algorithm>
#include <map>
#include <list>

// #include <initializer_list>
// #include <numeric>

#include <SFML/Graphics.hpp>


class State
{
public:
    virtual ~State() {};

    virtual void Input(sf::Keyboard::Key key_code);
    virtual void Update(float elapsedTime);
    virtual void Render(sf::RenderWindow& window);
    virtual void OnEnter();
    virtual void OnExit();
};


class EmptyState : public State
{
public:
    EmptyState();
    ~EmptyState();

    void Input(sf::Keyboard::Key key_code);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
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

    void Input(sf::Keyboard::Key key_code);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
    void Change(const std::string& stateName); // std::initializer_list<std::string> params);  // Note: template?
    void Add(std::string name, State* state);
    std::string GetCurrentStateName();
};


StateMachine& gameMode();

#if 0
class StateStack    // future
{
private:
    std::map<std::string, State*> m_States;
    std::list<State*> m_Stack;
    State* m_CurrentState;
    State* top;
public:
    StateStack();
    ~StateStack();

    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);
    void Push(std::string name);
    void Pop();
};

#endif

#endif  // STATE_MACHINE_H_