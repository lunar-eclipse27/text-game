#include<iostream>
#include<conio.h>
#include<string>
#include"ansi.h"
#include"global.h"
#include<chrono>
#include<thread>
#include<ios>
#include<limits>

std::string get_player_name(){

    std::string name;
    std::cout << "what is the heros name? ";
    std::cin >> name;
    std::cout << '\n';

    return name;
};

int get_player_age(std::string name){
    
    int age;
    std::cout << "how old is " << name << "? ";
    while(!(std::cin >> age)){
        // printf("must be an integer");
        std::cin.clear();
        std::cin.ignore();
    }
    std::cout << '\n';

    return age;
};

int get_player_details(character player){


    player.name = get_player_name();
    player.age = get_player_age(player.name);

    return 0;
}

std::string get_world_name(worlds world){

    std::string name;
    std::cout << "whats the name of this world? ";
    std::cin >> name;
    std::cout << '\n';

    return name;
}
int get_world_details(worlds world){

    world.name = get_world_name(world);
    

    return 0;
}

int intro(character player,worlds world){
    
    int intro_length = 5;
    std::string intro_text[intro_length] = {
        "intro text",
        "imagine this is very cinimatic",
        "this games gonna be good",
        "lore stuff here",
        "great lore",
    };

    show_text_slowly(intro_text,intro_length,35);

    // std::cout << '\n' << "press enter to contiue" << '\n';
    std::cout << '\n' << "enter some text to contiue" << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // std::cin.get();
    // std::string enter_to_continue;
    // std::cin >> enter_to_continue;
    // for (size_t i = 0; i < 100; i++)
    // {
    //     std::cout << '\b' << " " << '\b' ;
    // }


    std::cout << '\n';

    get_world_details(world);

    get_player_details(player);

    return 0;
};