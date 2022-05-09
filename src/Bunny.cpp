#include "../include/Bunny.h"
#include <random>
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>

Bunny::Bunny()
{
    //random choose sex
    std::random_device dev1;
    std::mt19937 sexDev(dev1());
    std::uniform_int_distribution<std::mt19937::result_type> distSex(1, 2);

    if (distSex(sexDev) == 1) sex = 'f';
    else sex = 'm';

    //random choose colour
    std::random_device dev2;
    std::mt19937 colourDev(dev2());
    std::uniform_int_distribution<std::mt19937::result_type> distColour(1, 4);

    switch(distColour(colourDev))
    {
    case 1:
    colour = "white";
    break;

    case 2:
    colour = "brown";
    break;

    case 3:
    colour = "black";
    break;

    case 4:
    colour = "spotted";
    break;    
    }

    //random choose age
    std::random_device dev3;
    std::mt19937 ageDev(dev3());
    std::uniform_int_distribution<std::mt19937::result_type> distAge(0, 10);

    age = distAge(ageDev);

    //random choose radioactive vampire rabbit
    std::random_device dev4;
    std::mt19937 infectedDev(dev4());
    std::uniform_int_distribution<std::mt19937::result_type> distInfected(1, 100);

    if (distInfected(infectedDev) <= 2) infected_bunny = true;
    else infected_bunny = false;

    //random choose name
    std::random_device dev5;
    std::mt19937 nameDev(dev5());
    std::uniform_int_distribution<std::mt19937::result_type> distName(1, 10);

    switch(distName(nameDev))
    {
        case 1:
        name = "Thumper";
        break;

        case 2:
        name = "Oreo";
        break;
        
        case 3:
        name = "Snowball";
        break;

        case 4:
        name = "Coco";
        break;

        case 5:
        name = "Bugs";
        break;

        case 6:
        name = "Midnight";
        break;

        case 7:
        name = "Roger";
        break;

        case 8:
        name = "Hopper";
        break;

        case 9:
        name = "Stompy";
        break;

        case 10:
        name = "Floppy";
        break;
    }

    if (age >= 2) {
        is_adult = true;
        sex = std::toupper(sex);
    }
    else is_adult = false;
}

Bunny::Bunny(const std::string &col)
{
    //random choose sex
    std::random_device dev1;
    std::mt19937 sexDev(dev1());
    std::uniform_int_distribution<std::mt19937::result_type> distSex(1, 2);

    if (distSex(sexDev) == 1) sex = 'f';
    else sex = 'm';

    //random choose radioactive vampire rabbit
    std::random_device dev4;
    std::mt19937 vampireDev(dev4());
    std::uniform_int_distribution<std::mt19937::result_type> distVamp(1, 100);

    if (distVamp(vampireDev) <= 25) infected_bunny = true;
    else infected_bunny = false;  

    //random choose name
    std::random_device dev5;
    std::mt19937 nameDev(dev5());
    std::uniform_int_distribution<std::mt19937::result_type> distName(1, 10);

    switch(distName(nameDev))
    {
        case 1:
        name = "Thumper";
        break;

        case 2:
        name = "Oreo";
        break;
        
        case 3:
        name = "Snowball";
        break;

        case 4:
        name = "Coco";
        break;

        case 5:
        name = "Bugs";
        break;

        case 6:
        name = "Midnight";
        break;

        case 7:
        name = "Roger";
        break;

        case 8:
        name = "Hopper";
        break;

        case 9:
        name = "Stompy";
        break;

        case 10:
        name = "Floppy";
        break;
    }

    age = -1;
    colour = col;
    is_adult = false;
}

void Bunny::display_bunny_values()
{
    char vampire;
    if (infected_bunny == true) vampire = 'Y';
    else vampire = ' ';
    std::cout << std::left << std::setw(10) << name << std::left << std::setw(10) << sex << std::left << std::setw(10) << colour << std::left << std::setw(5) << age << std::left << std::setw(10) << vampire << std::endl;
}

void Bunny::advance_age()
{
    age += 1;
}

void Bunny::check_adult()
{
    if (age >= 2) {
        is_adult = true;
        sex = std::toupper(sex);
    }
    else is_adult = false;
}

int Bunny::get_age()
{
    return age;
}

bool Bunny::is_infected()
{
    return infected_bunny; 
}

std::string Bunny::get_name()
{
    return name;
}

//operator override for list sorting
/*bool Bunny::operator < (const std::shared_ptr<Bunny> b1) const
{
    std::cout << "Operator Working" << std::endl;
    return age < b1->age;
}*/

char Bunny::get_sex()
{
    return sex;
}

std::string Bunny::get_colour()
{
    return colour;
}

void Bunny::death()
{
    is_dead = true;
}