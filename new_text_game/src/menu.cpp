#include<iostream>
#include<string>
#include<conio.h>
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

        if (answer == 'w' || answer == 'W')
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
        else if (answer == 's' || answer == 'S')
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
        else if (answer == 'e' || answer == 'e')
        {
            menu_in_use = true;
        }
    }
    return menu.selected;
};

int use_new_menu(){


    simple_menu menu;
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

        if (answer == 'w' || answer == 'W')
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
        else if (answer == 's' || answer == 'S')
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
        else if (answer == 'e' || answer == 'e')
        {
            menu_in_use = true;
        }
    }
    return menu.selected;
    

    return 0;
}








int print_stats(character player){
    simple_menu menu;
    menu.statment = "what would you like to check";
    menu.options = {"inventory ", "stats "};

    menu.menu_options_offset = 3;

    int answer = use_simple_menu(menu);

    
    if (answer == 0){
        for (size_t i = 0; i < player.inventory.size(); i++){
            std::cout << player.inventory[i].name << '\n';
        };

    }


    getch();
    


    return 0;
}



int how_much_to_take_or_put(int amount_had,int amount_there){

    simple_menu menu;

    std::cout << "how much will you take" << '\n' << '\n';

    if (menu.selected == 0){std::cout << menu.selected_markers[1];}
    else{std::cout << menu.selected_markers[0];}
    
    std::cout << amount_had << "/" << amount_there << '\n';

    if (menu.selected == 1){std::cout << menu.selected_markers[1];}
    else{std::cout << menu.selected_markers[0];}
    
    std::cout << "all" << '\n';

    bool done = false;

    menu.menu_options_offset = 3;


    while (done == false)
    {
        char answer = getch();

        if (answer == 'w' || answer == 'S')
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
        else if (answer == 's' || answer == 'S')
        {
            if (menu.selected < 1)
            {
                moveCursor(0,menu.selected + menu.menu_options_offset);
                std::cout << menu.selected_markers[0];
                menu.selected++;
                moveCursor(0,menu.selected + menu.menu_options_offset);
                std::cout << menu.selected_markers[1];
            }
        }

        if (menu.selected == 0)
        {

            if (answer == 'a' || answer == 'A')
            {
                if (amount_had > 0)
                {
                    moveCursor(2,menu.selected + menu.menu_options_offset);
                    std::cout << "            ";
                    amount_had--;
                    moveCursor(2,menu.selected + menu.menu_options_offset);
                    std::cout << amount_had << "/" << amount_there << '\n';
                }
            }
            else if (answer == 'd' || answer == 'D')
            {
                if (amount_had < amount_there)
                {
                    moveCursor(2,menu.selected + menu.menu_options_offset);
                    std::cout << "            ";
                    amount_had++;
                    moveCursor(2,menu.selected + menu.menu_options_offset);
                    std::cout << amount_had << "/" << amount_there << '\n';
                }
            }

        }




        else if (answer == 'e' || answer == 'e')
        {
            done = true;

            if (menu.selected == 1)
            {
                amount_had = amount_there;
            }
            
        }
    }
    

    return 0;
}




