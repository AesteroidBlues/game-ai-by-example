#pragma once

#include "miner.h"
#include "../core/util.h"

namespace GameAi
{

namespace Ch2
{

class Sim
{
public:
    Sim();
    virtual ~Sim() {};

    void Update();

private:
    SharedPtr<Miner> m_miner;

};

}

}
