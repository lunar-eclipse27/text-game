#include<iostream>
#include<string>
#include<conio.h>
#include<vector>
#include"global.h"



void moveCursor(int x, int y){
std::cout << "\033[" << y << ";" << x << "H";
}

int use_simple_menu(simple_menu menu){

    
    std::cout << menu.statment;
    for (size_t i = 0; i < menu.options.size(); i++)
    {
        moveCursor(0,i + menu.menu_options_offset);
        if (menu.selected == i)
        {
            std::cout << menu.selected_markers[1];
        }
        else{
            std::cout << menu.selected_markers[0];
        }
        std::cout << menu.options[i];
    }
    
    bool menu_in_use= false;

    while (menu_in_use == false)
    {
        char answer = getch();

        /*
        left arrow: 37
        up arrow: 38
        right arrow: 39
        down arrow: 40
        */
        /*
        The ascii values of the:

        Up key - 224 72
        Down key - 224 80
        Left key - 224 75
        Right key - 224 77
        */
       
        if (answer == 'w' || answer == 'W' || answer == 72)
        {
            if (menu.selected > 0)
            {
                moveCursor(0,menu.selected + menu.menu_options_offset);
                std::cout << menu.selected_markers[0];
                menu.selected--;
                moveCursor(0,menu.selected + menu.menu_options_offset);
                std::cout << menu.selected_markers[1];
            }
        }
        else if (answer == 's' || answer == 'S' || answer == 80)
        {
            if (menu.selected < menu.options.size() - 1)
            {
                moveCursor(0,menu.selected + menu.menu_options_offset);
                std::cout << menu.selected_markers[0];
                menu.selected++;
                moveCursor(0,menu.selected + menu.menu_options_offset);
                std::cout << menu.selected_markers[1];
            }
        }
        else if (answer == 'e' || answer == 'e' || answer == 13)
        {
            menu_in_use = true;
        }
    }
    return menu.selected;
};