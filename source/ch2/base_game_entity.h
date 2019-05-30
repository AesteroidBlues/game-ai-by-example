#pragma once

#include "../core/util.h"

using namespace GameAi::Core;

namespace GameAi
{

namespace Ch2
{

class BaseGameEntity
{
public:
    BaseGameEntity(int id);
    virtual ~BaseGameEntity() {}

    virtual void Update() = 0;

    int Id() const;
    String Name() const;

private:
    int m_Id;
};

}

}
