#include "../include/Bunny.h"
#include "../include/generator.h"
#include <random>
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>

Bunny::Bunny() : sex(generator::rand_sex()), colour(generator::rand_colour()), age(generator::rand_age()), name(generator::rand_name()), infected_bunny(generator::rand_infected())
{
    if (age >= 2) {
        is_adult = true;
        sex = std::toupper(sex);
    }
    else is_adult = false;
}

Bunny::Bunny(const std::string &col) : sex(generator::rand_sex()), colour(col), age(-1), name(generator::rand_name()), infected_bunny(generator::rand_infected()), is_adult(false) {}

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

char Bunny::get_sex()
{
    return sex;
}

std::string Bunny::get_colour()
{
    return colour;
}
