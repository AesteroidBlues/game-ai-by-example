#pragma once

#include "../miner.h"
#include "state.h"

namespace GameAi
{

namespace Ch2
{

class GoHomeAndSleep : public State<Miner>
{
public:
    static GoHomeAndSleep* Instance();

    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);

private:
    GoHomeAndSleep() {}
};

}

}
