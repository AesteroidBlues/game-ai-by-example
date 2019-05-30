#include "miner.h"

#include <cassert>

#include "states/enter_mine_and_dig.h"

namespace GameAi
{

namespace Ch2
{

Miner::Miner(int id)
: BaseGameEntity(id),
  m_location{ location_t::goldmine },
  m_currentState{ EnterMineAndDig::Instance() }
{
    ChangeState(EnterMineAndDig::Instance());
}

void Miner::Update()
{
    m_thirst += 1;

    if (m_currentState != nullptr)
    {
        m_currentState->Execute(this);
    }
}

void Miner::ChangeState(State* newState)
{
    assert(newState != nullptr);
    assert(m_currentState != nullptr);

    m_currentState->Exit(this);
    m_currentState = newState;
    m_currentState->Enter(this);
}

location_t Miner::Location()
{
    return m_location;
}

void Miner::ChangeLocation(location_t newLocation)
{
    m_location = newLocation;
}

void Miner::AddToGoldCarried(int newGold)
{
    m_goldCarried++;
}

void Miner::IncreaseFatigue()
{
    m_fatigue++;
}

bool Miner::Thirsty()
{
    return m_thirst > MAX_THIRST;
}

bool Miner::PocketsFull()
{
    return m_goldCarried > MAX_GOLD;
}

}

}
