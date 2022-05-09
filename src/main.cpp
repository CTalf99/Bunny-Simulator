#include "../include/Bunny.h"
#include "../include/BunnyManager.h"
#include <unistd.h>
#include <iostream>
#include <memory>
#include <list>
#include <thread>

int main ()
{
    BunnyManager bunnies;
    bunnies.run();
}