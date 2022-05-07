#include "../include/Bunny.h"
#include "../include/BunnyManager.h"
#include "../include/Util.h"
#include <unistd.h>
#include <iostream>
#include <memory>
#include <list>

int main ()
{
    BunnyManager bunnies;
    bunnies.sort_bunnies();
    bunnies.display_screen();
    do
    {
        /*bunnies.sort_bunnies();
        bunnies.display_screen();*/
        bunnies.breed();
        bunnies.food_shortage();
        bunnies.advance_time();
        bunnies.sort_bunnies();
        bunnies.display_screen();
        //system("pause");
        sleep(2);

    } while(bunnies.end_condition());

    system("clear");
    std::cout << "GAME OVER" << std::endl;
    sleep(2);
}