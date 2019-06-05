#pragma once

#include <iostream>
#include <memory>

#include "states/state.h"
#include "../core/util.h"

namespace GameAi
{

namespace Ch2
{

template<class entity_type>
class StateMachine
{
public:
    StateMachine()
    : m_owner{ nullptr },
    m_currentState{ nullptr },
    m_previousState{ nullptr },
    m_globalState{ nullptr }
    { }

    virtual ~StateMachine() {}

    void SetOwner(SharedPtr<entity_type> owner)
    {
        m_owner = owner;
    }

    void Update() const
    {
        if (m_globalState != nullptr)
        {
            m_globalState->Execute(m_owner.get());
        }

        assert(m_currentState);
        if (m_currentState != nullptr)
        {
            m_currentState->Execute(m_owner.get());
        }
    }

    void RevertToPreviousState()
    {
        ChangeState(m_previousState);
    }

private:
    SharedPtr<entity_type> m_owner;
    State<entity_type>* m_currentState;
    State<entity_type>* m_previousState;
    State<entity_type>* m_globalState;

// Template functions
public:
    void ChangeState(State<entity_type>* newState)
    {
        assert(newState);

        if (m_currentState == nullptr)
        {
            m_currentState = newState;
            m_currentState->Enter(m_owner.get());
            return;
        }
        else
        {
            m_previousState = m_currentState;
            m_currentState->Exit(m_owner.get());
            m_currentState = newState;
            m_currentState->Enter(m_owner.get());
        }
    }

    void SetCurrentState(State<entity_type>* s) { m_currentState = s; }
    void SetGlobalState(State<entity_type>* s) { m_globalState = s; }
    void SetPreviousState(State<entity_type>* s) { m_previousState = s; }


    State<entity_type>* CurrentState() const { return m_currentState; }
    State<entity_type>* GlobalState() const { return m_globalState; }
    State<entity_type>* PreviousState() const { return m_previousState; }

    bool IsInState(const State<entity_type>& st) const
    {
        return st == m_currentState || st == m_globalState;
    }
};

}

}
