#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include"global.h"

//this is for functions that ill need anywhere

void show_text_slowly(std::string text[],int lines,int delay_in_milliseconds){
    for (int l = 0; l < lines; l++)
    {
        for (size_t i = 0; i < text[l].length(); i++)
        {
            std::cout << text[l][i];
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_in_milliseconds));
        }
        std::cout << '\n';
        
    }
}
