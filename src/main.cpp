#include "../include/Bunny.h"
#include "../include/BunnyManager.h"
#include "../include/Util.h"
#include <unistd.h>
#include <iostream>
#include <memory>
#include <list>
#include <thread>

BunnyManager bunnies;
bool userInput;

// CIN-THREAD

void run()
{
    do
    {
        userInput = false;
        bunnies.food_shortage();
        bunnies.display_screen();
        userInput = true;
        sleep(2);

    } while (bunnies.end_condition());
}


int main ()
{
    system("clear");
    bunnies.sort_bunnies();
    bunnies.display_start_screen("Bunny simulation has begun");

    std::thread prg(run);

    while (bunnies.end_condition())
    {
        {
            char test;
            std::cin >> test;

            if ((test == 'k' || test == 'K') && userInput)
            {
                bunnies.remove_half();
                std::cin.clear();
            }
        }
    }
    prg.join();

    system("clear");
    std::cout << "GAME OVER" << std::endl;
    sleep(2);
}