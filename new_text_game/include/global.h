#include<string>
#include<vector>

#if !defined(global_stuff)
#define global_stuff

#define amount_of_skills 2

struct skill
{
    int level;//no skill 0 interested 1-19 novice 20-39, intermediate 40-59, knowledgable 60-79 expert 80-100
    int proficiency;//0 - 100 could be decreased or even lost with injurys to hands or whatevers needed
    int rate_of_decay = 1;//per week how much the skill is lost could increase with head injurys
};

struct character{

    std::string name;
    int age;
    
    skill archery;
    skill cooking;

};

struct settlement
{
    int population;
    int money;
};

struct world
{
    std::vector<settlement> all_discovered_settlements;
};

int intro(character player);

void show_text_slowly(std::string text[],int lines,int delay_in_milliseconds);

#endif