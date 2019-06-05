#include "go_to_work_and_code.h"

#include <iostream>

#include "go_home_and_sleep.h"
#include "quench_thirst.h"
#include "sprint_review.h"

namespace GameAi
{

namespace Ch2
{

/* static */ GoToWorkAndCode* GoToWorkAndCode::Instance()
{
    static GoToWorkAndCode instance;
    return &instance;
}

void GoToWorkAndCode::Enter(Miner* miner)
{
    if (miner->Location() != location_t::goldmine)
    {
        std::cout << miner->Name() << ": Walkin' to the cubicle" << std::endl;
    }

    miner->ChangeLocation(location_t::goldmine);
}

void GoToWorkAndCode::Execute(Miner* miner)
{
    miner->AddToSprintPoints(1);
    miner->IncreaseFatigue();

    std::cout << miner->Name() << ": Typin' out some code" << std::endl;

    if (miner->PocketsFull())
    {
        miner->FSM()->ChangeState(GoToSprintReview::Instance());
    }

    if (miner->Thirsty())
    {
        miner->FSM()->ChangeState(QuenchThirst::Instance());
    }
}

void GoToWorkAndCode::Exit(Miner* miner)
{
    std::cout << miner->Name() << ": Ah'm leavin' the cube with a "
        "burndown chart full o sweet story points" << std::endl;
}

}

}
