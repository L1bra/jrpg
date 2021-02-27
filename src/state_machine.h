#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include "resource_manager.h"

#include <map>

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


class StateStack
{
private:
    std::map<std::string, State*> m_States;
    std::vector<State*> m_Stack;
    State* state;
    State* top;
public:
    StateStack();
    ~StateStack();

    void Add(std::string, State* state);
    void Input(sf::Keyboard::Key key_code);
    void Update(float elapsedTime);
    void Render(sf::RenderWindow& window);

    void Push(std::string name);
    void Pop();

    bool isEmpty();
    std::size_t size();
};

StateStack& gameMode();

#endif  // STATE_MACHINE_H_