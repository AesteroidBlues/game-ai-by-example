#pragma once

#include "../miner.h"
#include "state.h"

namespace GameAi
{

namespace Ch2
{

class GoToWorkAndCode : public State<Miner>
{
public:
    static GoToWorkAndCode* Instance();

    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);

private:
    GoToWorkAndCode() {}
};

}

}
