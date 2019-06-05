#include "miner.h"

#include <cassert>
#include <iostream>

#include "states/go_to_work_and_code.h"

namespace GameAi
{

namespace Ch2
{

Miner::Miner(int id)
: BaseGameEntity(id),
  m_location{ location_t::none }
{ }

void Miner::Init()
{
    m_stateMachine.SetOwner(shared_from_this());
}

void Miner::Update()
{
    if (m_stateMachine.CurrentState() == nullptr)
    {
        m_stateMachine.ChangeState(GoToWorkAndCode::Instance());
    }

    m_thirst += 1;

    m_stateMachine.Update();
}

location_t Miner::Location()
{
    return m_location;
}

void Miner::ChangeLocation(location_t newLocation)
{
    m_location = newLocation;
}

void Miner::AddToSprintPoints(int newGold)
{
    m_sprintPoints++;
}

void Miner::ClearSprintPoints()
{
    m_completedSprintPoints += m_sprintPoints;
    m_sprintPoints = 0;
}

void Miner::ClearThirst()
{
    m_thirst = 0;
}

void Miner::IncreaseFatigue()
{
    m_fatigue++;
}

void Miner::DecreaseFatigue()
{
    m_fatigue -= MAX_FATIGUE / 4;
}

int Miner::StoryPoints()
{
    return m_completedSprintPoints;
}

bool Miner::Thirsty()
{
    return m_thirst > MAX_THIRST;
}

bool Miner::Rested()
{
    return m_fatigue <= 0;
}

bool Miner::PocketsFull()
{
    return m_sprintPoints > MAX_SPRINT_POINTS;
}

StateMachine<Miner>* Miner::FSM()
{
    return &m_stateMachine;
}

}

}
