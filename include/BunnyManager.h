#pragma once
#include <memory>
#include <list>
#include "Bunny.h"

class BunnyManager
{
private:

    std::list<std::shared_ptr<Bunny>> bunny_list;
    
public:
    std::list<std::shared_ptr<Bunny>> bunny_list;

    BunnyManager();
    void bunny_attribute_header();
    std::list<std::shared_ptr<Bunny>> get_list();  
    void display_screen();
    void display_start_screen(const std::string &opening);
    void advance_time();
    bool end_condition();
    void sort_bunnies();
    bool check_reproductive_male();
    void breed();
    static bool compare_function(const std::shared_ptr<Bunny> &b1, const std::shared_ptr<Bunny> &b2);
    void food_shortage();
    void remove_bunny(const std::shared_ptr<Bunny> b);
    void advance_all_age();
    void seperator();
    void remove_half();

};