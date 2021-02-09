#include "state_machine.h"


// EmptyState definition

EmptyState::EmptyState()
{

}

EmptyState::~EmptyState()
{

}


void EmptyState::Update(float elapsedTime)
{

}

void EmptyState::Render()
{
    
}

void EmptyState::OnEnter()
{
    
}

void EmptyState::OnExit()
{
    
}


StateMachine::StateMachine()
{
    EmptyState* emptyState = new EmptyState();
    this->m_CurrentState = emptyState;
}

StateMachine::~StateMachine()
{
    // delete this->m_CurrentState; // seg fault
}

void StateMachine::Update(float elapsedTime)
{
    this->m_CurrentState->Update(elapsedTime);
}

void StateMachine::Render()
{
    this->m_CurrentState->Render();
}

void StateMachine::Change(std::string stateName) // std::initializer_list<std::string> params)
{
    this->m_CurrentState->OnExit();
    this->m_CurrentState = m_States[stateName];
    this->m_CurrentState->OnEnter(); // accumulate(params.begin(), params.end(), 0.0) as a param
}

void StateMachine::Add(std::string name, State* state)
{
    this->m_States[name] = state;
}