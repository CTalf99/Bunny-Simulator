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
    std::cout << std::left << std::setw(10) << "Name: " << std::left << std::setw(10) << "Sex: " << std::left << std::setw(10) << "Colour: " << std::left << std::setw(5) << "Age: " << std::left << std::setw(10) << "Infected?" << std::endl << std::endl;
}

std::list<std::shared_ptr<Bunny>> BunnyManager::get_list()
{
    return bunny_list;
}

void BunnyManager::display_screen()
{
    system("clear");
    std::cout << "Bunnies born from the previouse round: " << std::string(2, '\n');
    breed();
    seperator();
    std::cout << "Bunnies removed from the last round: " << std::string(2, '\n');
    advance_time();
    seperator();
    sort_bunnies();
    std::cout << "Updated bunny list: " << std::string(3, '\n');
    bunny_attribute_header();

    for (auto& it: bunny_list)
    {
        it->display_bunny_values();
    }
    std::cout << std::endl;
    //sleep(2);
}

//seperate display screen used at the start due to lack of breeding/dying before the list is displayed.

void BunnyManager::display_start_screen(const std::string &opening)
{
    std::cout << opening << std::endl << std::endl;
    bunny_attribute_header();
    std::cout << std::endl;

    for (auto& it: bunny_list)
    {
        it->display_bunny_values();
    }
    std::cout << std::endl;
    sleep(4);
}

void BunnyManager::advance_time()
{
    advance_all_age();
    std::list<std::shared_ptr<Bunny>>::const_iterator itr = bunny_list.begin();
    
    while(itr != bunny_list.end())
    {
        while(itr != bunny_list.end())
        {
            if ((*itr)->get_age() > 10 && (*itr)->is_infected() == false)
            {
                std::cout << "Bunny " << (*itr) -> get_name() << " has died" << std::endl;
                sleep(1);
                itr = bunny_list.erase(itr);
            }
            else if ((*itr)->get_age() > 50 && (*itr)->is_infected() == true)
            {
                std::cout << "Infected Bunny " << (*itr) -> get_name() << " has died" << std::endl;
                sleep(1);
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
        if (it->get_sex() == 'M' && !(it->is_infected()))
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
        std::list<std::shared_ptr<Bunny>>::const_iterator itr = bunny_list.begin();
        while(itr != bunny_list.end())
        {
            if (((*itr)->get_sex() == 'F') && !((*itr)->is_infected()))
            {
                std::shared_ptr<Bunny> bunnyChild = std::make_shared<Bunny>((*itr)->get_colour());
                bunny_list.push_front(bunnyChild);
                std::cout << bunnyChild->get_name() << " was born!" << std::endl;
                sleep(1);
            }
            ++itr;
        }
    }
    sleep(1);
}

void BunnyManager::sort_bunnies()
{
    bunny_list.sort(compare_function);
}

void BunnyManager::food_shortage()
{
    if(bunny_list.size() > 1000)
    {
        seperator();
        std::cout << "Bunny famine!" << std::endl;
        sleep(3);
        system("clear");
        int a = bunny_list.size()/2;
        
        std::list<std::shared_ptr<Bunny>>::iterator itr = bunny_list.begin();
        std::vector<std::string> deceased_names;

        while(itr != bunny_list.end())
        {
            std::random_device dev1;
            std::mt19937 sexDev(dev1());
            std::uniform_int_distribution<std::mt19937::result_type> distSex(1, 2);  

            if (distSex(sexDev) == 1) 
            {
                deceased_names.push_back((*itr)->get_name());
                itr = bunny_list.erase(itr);
            }
            else ++itr;

            if(bunny_list.size() == a) break;
        }
        
        std::cout << "Bunnies that died during food shortage: " << std::endl;
        for (int i = 0; i < deceased_names.size(); i++)
        {
            std::cout << deceased_names[i] << std::endl;
        }
        sleep(3);
        deceased_names.clear();
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


void BunnyManager::seperator()
{
    std::cout << std::endl;
    std::cout << std::string(60, '-');
    std::cout << std::endl;
}

void BunnyManager::remove_half()
{
    seperator();
    std::cout << "Half of bunnies removed" << std::endl;
    sleep(3);
    system("clear");
    int a = bunny_list.size()/2;
    
    std::list<std::shared_ptr<Bunny>>::iterator itr = bunny_list.begin();

    while(itr != bunny_list.end())
    {
        std::random_device dev1;
        std::mt19937 sexDev(dev1());
        std::uniform_int_distribution<std::mt19937::result_type> distSex(1, 2);  

        if (distSex(sexDev) == 1) itr = bunny_list.erase(itr);
        else ++itr;

        if(bunny_list.size() == a) break;
    }
        
}