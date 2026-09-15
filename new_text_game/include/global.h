#include<string>
#include<vector>

#if !defined(global_stuff)
#define global_stuff

#define amount_of_skills 2


struct world_time{

    int seconds;
    int minutes;
    int hours;
    int days;
    int weeks;
    int months;
    int years;

    //("minutes",70)used so that u can do hours += 50 and have 2 days and two hours go by 
    int pass_time(std::string type_of_time,int amount){

        if (type_of_time == "seconds"){seconds += amount;}
        else if (type_of_time == "minute"){minutes += amount;}
        else if (type_of_time == "hour"){hours += amount;}
        else if (type_of_time == "day"){days += amount;}
        else if (type_of_time == "week"){weeks += amount;}
        else if (type_of_time == "month"){months += amount;}
        else if (type_of_time == "year"){years += amount;}

        while (seconds >= 60){seconds -= 60;minutes++;}
        while (minutes >= 60){minutes -= 60;hours++;}
        while (hours >= 24){hours -= 24;days++;}
        while (days >= 7){days -= 7;weeks++;}
        while (weeks >= 4){weeks -= 4;months++;}
        while (months >= 12){months -= 12;years++;}
        
        return 0;
    }

};

struct skill
{
    int level;//no skill 0 interested 1-19 novice 20-39, intermediate 40-59, knowledgable 60-79 expert 80-100
    int proficiency;//0 - 100 could be decreased or even lost with injurys to hands or whatevers needed
    int rate_of_decay = 1;//per week how much the skill is lost could increase with head injurys
};

struct item
{
    const int type_id;
    std::string name;
    int cost;
    int amount;
};

//VERY IMPORTANT TO SET VALUES BEFORE USING
struct simple_menu
{
    size_t selected = 0;// only using size_t to avoid the warning with -Wall for comparsions with int
    std::string selected_markers[2] = {" ",">"};
    std::string statment;
    std::vector<std::string> options;
    int menu_options_offset;
};



struct character{

    std::string name;
    int age;
    
    skill archery;
    skill cooking;
    //std::vector<skill> skills


    std::vector<item> inventory;



};

struct shop_menu
{
    size_t selected = 0;// only using size_t to avoid the warning with -Wall for comparsions with int
    std::string selected_markers[2] = {"< >","<0>"};
    std::vector<std::string> options;
    std::vector<item> stocks;
    shop_menu(size_t length) : options(length){}//remember this the constructor doesnt limit the size
    //menu.options.size() 
    int x = 1;
    int y = 1;
};

struct shop
{
    shop_menu menu;
    
};

struct locations
{
    std::string name;
    
};

struct settlement
{
    std::vector<locations> locations_available;
    int population;
    int money;
};

struct worlds
{
    std::string name;
    std::vector<settlement> all_discovered_settlements;
    world_time time;
};


int intro(character player,worlds world);

void show_text_slowly(std::string text[],int lines,int delay_in_milliseconds);

void moveCursor(int x, int y);

int use_simple_menu(simple_menu menu);

int print_stats(character player);

int how_much_to_take_or_put(int amount_had,int amount_there);

struct bunker
{

    std::vector<item> storage;

    void look_at_storage(character player){

    };

    void kitchen(){
        simple_menu menu;
        menu.statment = "what would you like to cook";
        menu.options = {
            "sandwich",
            "stuff",
            "something food",
            };
        menu.menu_options_offset = 3;
        system("cls");
        use_simple_menu(menu);
    };

    void bunker_actions(character player){
        simple_menu menu;
        menu.statment = "what would you like to do";
        menu.options = {
            "get something from storage",
            "cook something",
            "leave for an expedition",
        };
        menu.menu_options_offset = 3;
        int answer = use_simple_menu(menu);
        if (answer == 0){look_at_storage(player);}
        if (answer == 1){kitchen();}
        // if (answer == 2){expedition;}

    }
};

#endif