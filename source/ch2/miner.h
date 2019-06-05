#pragma once

#include "base_game_entity.h"
#include "enums.h"
#include "state_machine.h"

namespace GameAi
{

namespace Ch2
{

class Miner : public BaseGameEntity, public std::enable_shared_from_this<Miner>
{
public:
    Miner(int id);

    void Init() override;

    void Update() override;

    void RevertToPreviousState();

    location_t Location();
    void ChangeLocation(location_t newLocation);

    void AddToSprintPoints(int newGold);
    void ClearSprintPoints();

    void ClearThirst();

    void IncreaseFatigue();
    void DecreaseFatigue();

    int StoryPoints();

    bool Thirsty();
    bool Rested();
    bool PocketsFull();

    StateMachine<Miner>* FSM();

private:
    StateMachine<Miner> m_stateMachine;

    location_t m_location;
    int const MAX_SPRINT_POINTS = 12;
    int m_sprintPoints;

    int m_completedSprintPoints;

    int const MAX_THIRST = 5;
    int m_thirst;

    int const MAX_FATIGUE = 12;
    int m_fatigue;
};

}

}
