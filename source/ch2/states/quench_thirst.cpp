#include "quench_thirst.h"

#include <iostream>

#include "go_to_work_and_code.h"

namespace GameAi
{

namespace Ch2
{

/* static */ QuenchThirst* QuenchThirst::Instance()
{
    static QuenchThirst instance;
    return &instance;
}

void QuenchThirst::Enter(Miner* miner)
{
    if (miner->Location() != location_t::hip_bar)
    {
        std::cout << miner->Name() << ": Boy. ah sure is thusty! "
            "Walkin' to that trendy saloon downtown"  << std::endl;
    }

    miner->ChangeLocation(location_t::hip_bar);
}

void QuenchThirst::Execute(Miner* miner)
{
    miner->ClearThirst();
    miner->IncreaseFatigue();

    std::cout << miner->Name() << ": That's a mighy fine $12 beer" << std::endl;

    miner->FSM()->ChangeState(GoToWorkAndCode::Instance());
}

void QuenchThirst::Exit(Miner* miner)
{
    std::cout << miner->Name() << ": Leavin' the saloon, "
        "feelin' relaxed" << std::endl;
}

}

}
