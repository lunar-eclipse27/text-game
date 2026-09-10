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

int intro(character player){
    
    int intro_length = 5;
    std::string intro_text[intro_length] = {
        "intro text",
        "imagine this is very cinimatic",
        "this games gonna be good",
        "lore stuff here",
        "great lore",
    };

    for (int l = 0; l < intro_length; l++)
    {
        for (size_t i = 0; i < intro_text[l].length(); i++)
        {
            std::cout << intro_text[l][i];
            std::this_thread::sleep_for(std::chrono::milliseconds(35));
        }
        std::cout << '\n';
        
    }
    std::cout << '\n' << "press enter to contiue" << '\n';
    std::string enter_to_continue;
    std::cin >> enter_to_continue;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // for (size_t i = 0; i < 100; i++)
    // {
    //     std::cout << '\b' << " " << '\b' ;
    // }


    std::cout << '\n';

    get_player_details(player);

    return 0;
};