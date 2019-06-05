#include "sprint_review.h"

#include <iostream>

#include "go_home_and_sleep.h"

namespace GameAi
{

namespace Ch2
{

/* static */ GoToSprintReview* GoToSprintReview::Instance()
{
    static GoToSprintReview instance;
    return &instance;
}

void GoToSprintReview::Enter(Miner* miner)
{
    std::cout << miner->Name() << ": Ah finished all mah sprint tasks, "
        "ah'm a rockstar eng'neer!" << std::endl;

}

void GoToSprintReview::Execute(Miner* miner)
{
    miner->ClearSprintPoints();

    std::cout << miner->Name() << ": Tallyin' burndown chart, total story " 
        "points: " << miner->StoryPoints() << std::endl;

    miner->FSM()->ChangeState(GoHomeAndSleep::Instance());
}

void GoToSprintReview::Exit(Miner* miner)
{
    /* nop */
}

}

}
