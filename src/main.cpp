#include "../include/Bunny.h"
#include "../include/BunnyManager.h"
#include "../include/Util.h"
#include <unistd.h>
#include <iostream>
#include <memory>
#include <list>
#include <thread>

BunnyManager bunnies;

int main ()
{
    system("clear");

    bunnies.sort_bunnies();
    bunnies.display_start_screen("Bunny simulation has begun");
    do
    {
        bunnies.food_shortage();
        bunnies.display_screen();

    } while(bunnies.end_condition());

    system("clear");
    std::cout << "GAME OVER" << std::endl;
    sleep(2);
}