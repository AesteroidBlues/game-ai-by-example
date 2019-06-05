#pragma once

#include "../miner.h"
#include "state.h"

namespace GameAi
{

namespace Ch2
{

class QuenchThirst : public State<Miner>
{
public:
    static QuenchThirst* Instance();

    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);

private:
    QuenchThirst() {}
};

}

}
