#include "state_machine.h"
#include <iostream>


// EmptyState definition

EmptyState::EmptyState() {}

EmptyState::~EmptyState() {}

void EmptyState::Input(sf::Keyboard::Key key_code) {}

void EmptyState::Update(float elapsedTime) {}

void EmptyState::Render(sf::RenderWindow& window) {}

void EmptyState::OnEnter() {}

void EmptyState::OnExit() {}


StateStack::StateStack()
:state(new EmptyState()), top(new EmptyState())
{}

StateStack::~StateStack() {}

void StateStack::Input(sf::Keyboard::Key key_code)
{
    if(m_Stack.size())
    {
        top = m_Stack.back();
        top->Input(key_code);
    }
}

void StateStack::Update(float elapsedTime)
{
    if(m_Stack.size())
    {
        top = m_Stack.back();
        top->Update(elapsedTime);
    }
}

void StateStack::Render(sf::RenderWindow& window)
{
    if(m_Stack.size())
    {
        top = m_Stack.back();
        top->Render(window);
    }
}

void StateStack::Push(std::string name)
{
    state = m_States[name];
    m_Stack.push_back(state);
}


void StateStack::Add(std::string name, State* state)
{
    m_States[name] = state;
}

void StateStack::Pop()
{
    m_Stack.pop_back();
}

bool StateStack::isEmpty()
{
    return m_Stack.size() ? 1 : 0;
}


StateStack& gameMode()
{
    static StateStack ss;
    return ss;
}