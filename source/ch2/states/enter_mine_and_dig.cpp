#include "enter_mine_and_dig.h"

#include <iostream>

namespace GameAi
{

namespace Ch2
{

/* static */ EnterMineAndDig* EnterMineAndDig::Instance()
{
    static EnterMineAndDig instance;
    return &instance;
}

void EnterMineAndDig::Enter(Miner* miner)
{
    if (miner->Location() == location_t::goldmine)
    {
        std::cout << miner->Name() << ": Walkin' to the gold mine" << std::endl;
    }

    miner->ChangeLocation(location_t::goldmine);
}

void EnterMineAndDig::Execute(Miner* miner)
{
    miner->AddToGoldCarried(1);
    miner->IncreaseFatigue();

    std::cout << miner->Name() << ": Pickin up a nugget" << std::endl;

    if (miner->PocketsFull())
    {
        // miner->ChangeState()
    }

    if (miner->Thirsty())
    {
        // miner->ChangeState()
    }
}

void EnterMineAndDig::Exit(Miner* miner)
{
    std::cout << miner->Name() << ": Ah'm leavin' the gold mine with "
        "mah pockets full o' sweet gold" << std::endl;
}

}

}
