#include<iostream>
#include"global.h"


int set_character_values(character player){


    std::string first_name_ask = "what is the players first name\n";
    show_text_slowly(first_name_ask,10);
    std::cin >> player.first_name;

    
    std::string last_name_ask = "what is " + player.first_name +"'s last name\n";
    show_text_slowly(last_name_ask,10);
    std::cin >> player.last_name;
    

    return 0;
}