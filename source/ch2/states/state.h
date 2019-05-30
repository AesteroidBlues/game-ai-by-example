#pragma once

#include "../miner.h"
#include "../../core/util.h"

using namespace GameAi::Core;

namespace GameAi
{

namespace Ch2
{

class State
{
public:
    virtual ~State() {}

    virtual void Enter(Miner*) = 0;
    virtual void Execute(Miner*) = 0;
    virtual void Exit(Miner*) = 0;
};

}

}
