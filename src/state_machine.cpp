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


StateMachine::StateMachine()
{
    EmptyState* emptyState = new EmptyState();  // am i need really this?
    m_CurrentState = emptyState;
}

StateMachine::~StateMachine() {}

void StateMachine::Input(sf::Keyboard::Key key_code)
{
    m_CurrentState->Input(key_code);
}

void StateMachine::Update(float elapsedTime)
{
    m_CurrentState->Update(elapsedTime);
}

void StateMachine::Render(sf::RenderWindow& window)
{
    m_CurrentState->Render(window);
}

void StateMachine::Change(const std::string& stateName) // std::initializer_list<std::string> params)
{
    m_CurrentState->OnExit();
    
    if(m_States.find(stateName) != m_States.end())
    {
        m_CurrentState = m_States[stateName];
    }
    else
    {
        std::cout << "There is no key: " << stateName << " are u ok!?!?!?\n";
    }

    m_CurrentState->OnEnter(); // accumulate(params.begin(), params.end(), 0.0) as a param
}

void StateMachine::Add(std::string name, State* state)
{
        m_States[name] = state;
}

std::string StateMachine::GetCurrentStateName()
{
    if(m_States.size())
    {
        auto it = m_States.begin();
        
        while(it != m_States.end())
        {
            if(it->second == m_CurrentState)
            {
                return it->first;
            }

            ++it;
        }
    } 

    return "map is empty";  // ???
}




// Future

StateStack::StateStack() 
{

}

StateStack::~StateStack()
{

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
    this->m_CurrentState = m_States[name];
    m_Stack.push_back(this->m_CurrentState);
}

void StateStack::Pop()
{
    m_Stack.pop_back();
}