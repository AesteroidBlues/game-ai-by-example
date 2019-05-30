#include "sim.h"

#include "enums.h"

namespace GameAi
{

namespace Ch2
{

Sim::Sim()
: m_miner{ static_cast<int>(entity_t::miner_irene) }
{

}

void Sim::Update()
{
    m_miner.Update();
}

}

}
