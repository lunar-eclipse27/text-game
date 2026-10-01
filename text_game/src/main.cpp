#include<iostream>
#include"global.h"

int main(){

    
    hidecursor();

    character player;
    world_time time;
    bunker base;


    player.inventory.reserve(12);

    game game;
    game.init_items();
    game.play_game(player,time,base);


    return 0;
}