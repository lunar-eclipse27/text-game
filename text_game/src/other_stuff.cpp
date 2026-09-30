#include<iostream>
#include<vector>
#include<conio.h>




#ifdef _WIN32
#include<windows.h>
#endif

std::string getOsName() {
#ifdef _WIN32
return "Windows 32-bit or 64-bit";
#elif _WIN64
return "Windows 64-bit";
#elif __APPLE__ || __MACH__
return "Mac OSX";
#elif __linux__
return "Linux";
#elif __FreeBSD__
return "FreeBSD";
#elif __unix || __unix__
return "Unix";
#else
return "Unknown OS";
#endif
}

void clear(){
	if (getOsName() == "Windows 32-bit or 64-bit" || getOsName() == "Windows 64-bit")
	{
		system("cls");
	}
	else
	{
		system("clear");
	}
};

void hidecursor()
{
	#ifdef _WIN32
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);

   #elif _WIN64
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
   #endif
   
}



#include <cstdlib>
#include <ctime>

int random_num_gen(int limit){
    
    std::srand(std::time(0));
    int number = (std::rand() % limit) + 1;

    return number;
}