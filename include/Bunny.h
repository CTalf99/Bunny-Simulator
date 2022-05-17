#pragma once
#include <string>
#include <memory>

class Bunny
{
private:

    std::string name;
    char sex;
    std::string colour;
    int age;
    bool is_adult;
    bool infected_bunny;
    //std::string names[10] = {"Thumper", "Oreo", "Snowball", "Coco", "Bugs", "Midnight", "Pepper", "Hopper", "Stompy", "Floppy"};

public:

    Bunny(); //for initial five bunnies
    explicit Bunny(const std::string &col);     //for when a bunny is born & takes mother's colour
    void display_bunny_values();
    void advance_age();
    void check_adult();
    int get_age();
    bool is_infected();
    std::string get_name();
    char get_sex();
    std::string get_colour();
};