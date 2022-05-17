#include "../include/BunnyManager.h"
#include <memory>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <list>
#include <vector>
#include <random>
#include <algorithm>

BunnyManager::BunnyManager()
{
    for (int i = 0; i < 5; i++)
    {
        std::shared_ptr<Bunny> bunny = std::make_shared<Bunny>();
        bunny_list.push_back(bunny);
    }
    bunny_list.sort();
}

void BunnyManager::run()
{
    system("clear");
    display_bunny_list();

    do
    {
        kill_half();
        seperator();
        breed();
        seperator();
        advance_time();
        seperator();
        sort_bunnies();
        display_bunny_list();

    } while(end_condition());

    system("clear");
    std::cout << "GAME OVER" << std::endl;
    sleep(2);
}

bool BunnyManager::compare_function(const std::shared_ptr<Bunny> &b1, const std::shared_ptr<Bunny> &b2) 
{
    return b1->get_age() > b2->get_age();
}

void BunnyManager::bunny_attribute_header()
{
    std::cout << std::left << std::setw(10) << "Name: " << std::left << std::setw(10) << "Sex: " << std::left << std::setw(10) << "Colour: " << std::left << std::setw(5) << "Age: " << std::left << std::setw(10) << "Infected?" << std::endl << std::endl;
}

void BunnyManager::display_bunny_list()
{

    std::cout << "List of bunnies: " << std::endl << std::endl;
    bunny_attribute_header();

    for (auto& it: bunny_list)
    {
        it->display_bunny_values();
    }
    std::cout << std::endl;
    sleep(2);
}

void BunnyManager::advance_time()
{
    std::cout << "Bunnies who died of old age: " << std::string(2, '\n');
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
    std::cout << "Bunnies born from the previouse round: " << std::string(2, '\n');

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

//Simulates a food shortage by randomly removing half the bunnies from the list when the population exceeds 1000. 
void BunnyManager::kill_half()
{
    system("clear");
    if(bunny_list.size() > 1000)
    {
        seperator();
        std::cout << "Famine! Half of the bunnies die of starvation." << std::endl;
        sleep(3);
        system("clear");

        std::vector<std::shared_ptr<Bunny>> temp(bunny_list.begin(), bunny_list.end());
        std::random_shuffle(temp.begin(), temp.end());

        // copy the (shuffled) vector back into the list
        std::copy(temp.begin(), temp.end(), bunny_list.begin());

        bunny_list.resize((bunny_list.size() + 1)/2);

    }
    system("clear");
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
