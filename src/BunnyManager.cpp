#include "../include/BunnyManager.h"
#include <memory>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <list>
#include <vector>
#include <random>

bool BunnyManager::compare_function(const std::shared_ptr<Bunny> &b1, const std::shared_ptr<Bunny> &b2) 
{
    return b1->get_age() > b2->get_age();
}

BunnyManager::BunnyManager()
{
    for (int i = 0; i < 5; i++)
    {
        std::shared_ptr<Bunny> bunny = std::make_shared<Bunny>();
        bunny_list.push_back(bunny);
    }
    bunny_list.sort();
}

void BunnyManager::bunny_attribute_header()
{
    std::cout << std::left << std::setw(10) << "Name: " << std::left << std::setw(10) << "Sex: " << std::left << std::setw(10) << "Colour: " << std::left << std::setw(5) << "Age: " << std::left << std::setw(10) << "Vampire?" << std::endl << std::endl;
}

std::list<std::shared_ptr<Bunny>> BunnyManager::get_list()
{
    return bunny_list;
}


void BunnyManager::display_screen()
{
    system("clear");
    bunny_attribute_header();

    for (auto& it: bunny_list)
    {
        it->display_bunny_values();
    }
    std::cout << std::endl;
}

void BunnyManager::advance_time()
{
    advance_all_age();
    std::list<std::shared_ptr<Bunny>>::const_iterator itr = bunny_list.begin();
    
    while(itr != bunny_list.end())
    {
        while(itr != bunny_list.end())
        {
            if ((*itr)->get_age() > 10)
            {
                std::cout << "Bunny " << (*itr) -> get_name() << " has died :(" << std::endl;
                itr = bunny_list.erase(itr);
            }
            else ++itr;
        }
    }
    sleep(1);
}

bool BunnyManager::end_condition()
{
    if (bunny_list.size() == 0) return false;
    else return true;
}

bool BunnyManager::check_reproductive_male()
{
    bool repro = false;
    bool* reproductive = &repro;
    for (auto& it: bunny_list)
    {
        if (it->get_sex() == 'M' && !(it->is_radioactive()))
        {
        *reproductive = true;
        break;
        }
    }
    return repro;
}

void BunnyManager::breed()
{
    if (check_reproductive_male())
    {
        for (auto& it: bunny_list)
        {
            if (it->get_sex() == 'F' && !(it->is_radioactive()));
            {
                std::shared_ptr<Bunny> bunnyChild = std::make_shared<Bunny>(it->get_colour());
                bunny_list.push_front(bunnyChild);
                std::cout << bunnyChild->get_name() << " was born!" << std::endl;
            }
        }
    }
}

void BunnyManager::sort_bunnies()
{
    bunny_list.sort(compare_function);
}

void BunnyManager::food_shortage()
{
    if(bunny_list.size() > 20)
    {
        std::cout << "Bunny famine!" << std::endl;
        system("pause");
        system("clear");
        int a = bunny_list.size()/2;
        while (bunny_list.size() > a/2)
        {
            std::list<std::shared_ptr<Bunny>>::iterator itr = bunny_list.begin();

            while(itr != bunny_list.end())
            {
                std::random_device dev1;
                std::mt19937 sexDev(dev1());
                std::uniform_int_distribution<std::mt19937::result_type> distSex(1, 2);  

                if (distSex(sexDev) == 1) itr = bunny_list.erase(itr);
                else ++itr;

                if(bunny_list.size() == 6) break;
            }
        }
    }
}

void BunnyManager::advance_all_age()
{
    for (auto& i: bunny_list)
    {
        i->advance_age();
        i->check_adult();
    }

}