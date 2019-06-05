#include "sim.h"

#include <iostream>
#include <memory>

#include "enums.h"

namespace GameAi
{

namespace Ch2
{

Sim::Sim()
: m_miner{ std::make_shared<Miner>(static_cast<int>(entity_t::programmer_irene)) }
{
    std::cout << "Sim ctor" << std::endl;
    m_miner->Init();
}

void Sim::Update()
{
    m_miner->Update();
}

}

}
