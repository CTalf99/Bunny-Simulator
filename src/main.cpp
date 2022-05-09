#include "../include/Bunny.h"
#include "../include/BunnyManager.h"
#include "../include/Util.h"
#include <unistd.h>
#include <iostream>
#include <memory>
#include <list>
#include <thread>

// CIN-THREAD

BunnyManager bunnies;

void run()
{
    do
    {
        bunnies.food_shortage();
        bunnies.display_screen();

    } while (bunnies.end_condition());
}


int main ()
{
    system("clear");
    bunnies.sort_bunnies();
    bunnies.display_start_screen("Bunny simulation has begun");

    do { 
    std::thread prg(run);

    char test;
    std::cin >> test;
    while (bunnies.end_condition())
    {
    if (test == 'k' || test == 'K')
    {
        bunnies.remove_half();
        std::cin.clear();
    }
    }
    prg.join();

    } while (bunnies.end_condition());

    system("clear");
    std::cout << "GAME OVER" << std::endl;
    sleep(2);
}