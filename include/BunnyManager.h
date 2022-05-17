#pragma once
#include <memory>
#include <list>
#include "Bunny.h"

class BunnyManager
{
private:

    std::list<std::shared_ptr<Bunny>> bunny_list;

public:

    BunnyManager();
    void run();                                            //function which is called in main, constant loop until end condition is reached.
    void bunny_attribute_header();
    void display_bunny_list();
    void advance_time();
    bool end_condition();
    void sort_bunnies();
    bool check_reproductive_male();
    void breed();
    static bool compare_function(const std::shared_ptr<Bunny> &b1, const std::shared_ptr<Bunny> &b2);       //for sorting list by object age;
    void kill_half();
    void remove_bunny(const std::shared_ptr<Bunny> b);
    void advance_all_age();
    void seperator();                                   

};