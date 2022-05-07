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
    bool radioactive_mutant_vampire_bunny;
    bool is_dead = false;

public:

    Bunny();
    explicit Bunny(const std::string &col);
    void display_bunny_values();
    void advance_age();
    void check_adult();
    int get_age();
    bool is_radioactive();
    std::string get_name();
    char get_sex();
    std::string get_colour();
    void death();

    bool operator < (const std::shared_ptr<Bunny> b1) const;
};