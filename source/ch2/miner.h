#pragma once

#include "base_game_entity.h"
#include "enums.h"

namespace GameAi
{

namespace Ch2
{

class State; // Forward declare state

class Miner : public BaseGameEntity
{
public:
    Miner(int id);

    void Update();

    void ChangeState(State* newState);

    location_t Location();
    void ChangeLocation(location_t newLocation);

    void AddToGoldCarried(int newGold);
    void IncreaseFatigue();
    
    bool Thirsty();
    bool PocketsFull();

private:
    State* m_currentState;
    location_t m_location;
    int const MAX_GOLD = 4;
    int m_goldCarried;

    int m_moneyInBank;

    int const MAX_THIRST = 3;
    int m_thirst;

    int const MAX_FATIGUE = 3;
    int m_fatigue;
};

}

}
