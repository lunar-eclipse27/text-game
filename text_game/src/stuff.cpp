#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include"global.h"

void show_text_slowly(std::string text,int delay_in_milliseconds){
    for (size_t i = 0; i < text.length(); i++)
    {
        std::cout << text[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_in_milliseconds));
    }
    std::cout << '\n';

}