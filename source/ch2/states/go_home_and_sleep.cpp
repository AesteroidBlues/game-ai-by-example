#include "go_home_and_sleep.h"

#include <iostream>

#include "go_to_work_and_code.h"

namespace GameAi
{

namespace Ch2
{

/* static */ GoHomeAndSleep* GoHomeAndSleep::Instance()
{
    static GoHomeAndSleep instance;
    return &instance;
}

void GoHomeAndSleep::Enter(Miner* miner)
{
    if (miner->Location() != location_t::small_apartment)
    {
        std::cout << miner->Name() << ": Woohoo! Fixed that bug. Back home "
        "to mah li'l hubby" << std::endl;
    }

    miner->ChangeLocation(location_t::small_apartment);
}

void GoHomeAndSleep::Execute(Miner* miner)
{
    miner->DecreaseFatigue();
    miner->ClearThirst();
    std::cout << miner->Name() << ": ZZZZ...." << std::endl;

    if (miner->Rested())
    {
        miner->FSM()->ChangeState(GoToWorkAndCode::Instance());
    }
}

void GoHomeAndSleep::Exit(Miner* miner)
{
    std::cout << miner->Name() << ": What a gosh-darn fantastic nap "
        "Time to write more code" << std::endl;
}

}

}
