#include"../include/generator.h"
#include <random>

char generator::rand_sex()
{
    std::random_device dev1;
    std::mt19937 sexDev(dev1());
    std::uniform_int_distribution<std::mt19937::result_type> distSex(1, 2);

    if (distSex(sexDev) == 1) return 'f';
    else return 'm';
}

std::string generator::rand_colour()
{
    const std::string colourArray[4] = {"white", "brown", "black", "spotted"};
    std::random_device dev2;
    std::mt19937 colourDev(dev2());
    std::uniform_int_distribution<std::mt19937::result_type> distColour(0, 3);

    return colourArray[distColour(colourDev)];
}

int generator::rand_age()
{
    std::random_device dev3;
    std::mt19937 ageDev(dev3());
    std::uniform_int_distribution<std::mt19937::result_type> distAge(0, 10);

    return distAge(ageDev);
}

std::string generator::rand_name()
{
    const std::string nameArray[10] = {"Thumper", "Oreo", "Snowball", "Coco", "Bugs", "Midnight", "Pepper", "Hopper", "Stompy", "Floppy"};
    std::random_device dev4;
    std::mt19937 nameDev(dev4());
    std::uniform_int_distribution<std::mt19937::result_type> distName(0, 9);

    return nameArray[distName(nameDev)];
}

bool generator::rand_infected()
{
    std::random_device dev5;
    std::mt19937 infectedDev(dev5());
    std::uniform_int_distribution<std::mt19937::result_type> distInfected(1, 50);

    if (distInfected(infectedDev) == 1) return true;
    else return false;
}