#pragma once

#include "miner.h"

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
    Miner m_miner;

};

}

}
