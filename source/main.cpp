#include <chrono>
#include <iostream>
#include <thread>

#include <SFML/Graphics.hpp>

#include "core/resource_manager.h"
#include "ch2/sim.h"

int main()
{
    std::cout << "Starting" << std::endl;
    
    GameAi::Ch2::Sim sim;
    while (true) {
        sim.Update();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
