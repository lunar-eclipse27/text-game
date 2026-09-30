#include<iostream>
#include<vector>
#include<conio.h>
#include<string>


void clear();

void show_text_slowly(std::string text,int delay_in_milliseconds);

//VERY IMPORTANT TO SET VALUES BEFORE USING
struct simple_menu
{
    size_t selected = 0;// only using size_t to avoid the warning with -Wall for comparsions with int
    std::string selected_markers[2] = {"  ",">>"};
    std::string statment;
    std::vector<std::string> options;
    int menu_options_offset;
};

struct item_component
{
    std::string name;

    bool is_edible;
    bool is_drinkable;
    bool is_liquid;
    int calories;//later after a long time i want different vitamins and detailed nutrients
    int amount_of_liquid;//foods can have liquid in them
    bool is_flamable;
};


// not in use now
struct item
{
    std::string name_test;

    bool is_edible;
};


item get_item_id(int id);


// not in use now
struct inventory
{
    std::vector<item> items;
};

//values being set for me is temporary
struct character
{
    std::string first_name = "lunar";//values being set for me is temporary
    std::string last_name = "eclipse";//values being set for me is temporary
    int age = 16;//values being set for me is temporary
    int tiredness;
    int calories;//7700 in 1KG of fat and 2000-2200 for average adult 
    int thirst;//im thinking simple 0-100
};

struct world_time{

    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    int days = 0;
    int weeks = 0;
    int months = 0;
    int years = 0;

    //("minutes",70)used so that u can do hours += 50 and have 2 days and two hours go by 
    int pass_time(std::string type_of_time,int amount){

        if (type_of_time == "seconds"){seconds += amount;}
        else if (type_of_time == "minutes"){minutes += amount;}
        else if (type_of_time == "hours"){hours += amount;}
        else if (type_of_time == "days"){days += amount;}
        else if (type_of_time == "weeks"){weeks += amount;}
        else if (type_of_time == "months"){months += amount;}
        else if (type_of_time == "years"){years += amount;}

        // while (seconds >= 60){seconds -= 60;minutes++;}
        // while (minutes >= 60){minutes -= 60;hours++;}
        // while (hours >= 24){hours -= 24;days++;}
        // while (days >= 7){days -= 7;weeks++;}
        // while (weeks >= 4){weeks -= 4;months++;}
        // while (months >= 12){months -= 12;years++;}

        while (seconds > 59){seconds -= 60;minutes++;}
        while (minutes > 59){minutes -= 60;hours++;}
        while (hours > 23){hours -= 24;days++;}
        while (days > 6){days -= 7;weeks++;}
        while (weeks > 3){weeks -= 4;months++;}
        while (months > 11){months -= 12;years++;}
        
        return 0;
        
        /*
        time.pass_time("hours",9);
        time.print_time();
        time.print_date();
        */
    }

    std::string day_names[7] = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday",};
    std::string month_names[12] = {"january","febuary","march","april","may","june","july","august","september","october","november","december",};

    std::string week_prefix[4] = {"first ","second ","third ","fourth ",};

    std::string short_day_names[7] = {"mon","tue","wed","thu","fri","sat","sun",};
    std::string short_month_names[12] = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec",};

    int print_time(bool twelve_hour_clock_time){

        // std::cout << seconds << '\n';
        
        if (twelve_hour_clock_time == true)
        {
            std::cout << hours % 12;            
        }
        else{
            std::cout << hours;
        }
        
        std::cout << ":";

        if (minutes > 9)
        {
            std::cout << minutes;
        }
        else{
            std::cout << "0" << minutes;
        }
        

        if (twelve_hour_clock_time == true)
        {
            if (hours > 12)
            {
                std::cout << " PM";
            }
            else{
                std::cout << " AM";
            }
        }
                
        std::cout << '\n';

        return 0;
    }

    int print_date(bool days_as_numbers){

        if (days_as_numbers == true)
        {
            std::cout << day_names[days] << "/";
        }
        else
        {
            std::cout << days << "/";
        }
        
        std::cout << months << "/";
        std::cout << years << "/";
        std::cout << '\n';

        return 0;
    }

    int print_long_date(){

        std::cout << week_prefix[weeks] << day_names[days] << " of " << month_names[months] << " " << years << '\n';

        return 0;
    }

    /*
    world_time time;
    time.print_date();
    time.pass_time("days",170);
    time.print_date();
    // */

};

struct bunker
{
    
};

int use_simple_menu(simple_menu menu);

void hidecursor();

int random_num_gen(int limit);

int set_character_values(character player);

struct game
{
    

    //idk why tf i wrote this like this
    std::string choose_action(character player,world_time time,bunker home_base){
        // std::string answer;
        // std::cin >> answer;
        // return answer;

        simple_menu home_menu;
        home_menu.statment = "what would you like to do";
        home_menu.selected_markers[0] = "  ";
        home_menu.selected_markers[1] = ">>";
        home_menu.menu_options_offset = 3;
        home_menu.options = {"use item","sleep","cook","see stats","go explore"};
        int option_selected = use_simple_menu(home_menu);

        return home_menu.options[option_selected];

    }


    void play_game(character player,world_time time,bunker home_base){
        bool running = true;

        simple_menu sleep_menu;
        sleep_menu.menu_options_offset = 3;
        sleep_menu.statment = "how long will " + player.first_name + " sleep";
        sleep_menu.options = {"0  hours","1  hour","2  hours","3  hours","4  hours","5  hours","6  hours","7  hours","8  hours","9  hours","10 hours","11 hours","12 hours",};

        
        while (running == true)
        {
            clear();
            std::string answer = choose_action(player,time,home_base);
            if(answer == "sleep"){
                
                clear();
                time.pass_time("minutes",((use_simple_menu(sleep_menu)) * 60) + (random_num_gen(30) - 15));
                clear();
                time.print_time(true);
                // time.print_date(1);
                time.print_long_date();
                getch();
            }

        }
        
    }

};
