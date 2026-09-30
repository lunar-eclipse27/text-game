#include<iostream>
#include"global.h"

int main(){

    
    hidecursor();

    character player;
    world_time time;
    bunker base;
    
    item sandwich;
    
    set_character_values(player);

    game game;
    game.play_game(player,time,base);


    return 0;
}