#include "base_game_entity.h"

#include "enums.h"

namespace GameAi
{

namespace Ch2
{

BaseGameEntity::BaseGameEntity(int id)
: m_Id{ id }
{
}

int BaseGameEntity::Id() const
{
    return m_Id;
}

String BaseGameEntity::Name() const
{
    auto entityType = static_cast<entity_t>(m_Id);
    switch (entityType)
    {
    case entity_t::miner_irene:
        return "Miner Irene";
    case entity_t::husband_doug:
        return "Doug";
    default:
        return "Mysterious Stranger";
    }
}

}

}
