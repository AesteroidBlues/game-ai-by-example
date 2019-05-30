#pragma once

#include "state.h"

namespace GameAi
{

namespace Ch2
{

class EnterMineAndDig : public State
{
public:
    static EnterMineAndDig* Instance();

    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);

private:
    EnterMineAndDig() {}
};

}

}
