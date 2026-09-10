#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>






int load_save() {
    // 1. Open the file
    std::ifstream inputFile("save_files/save1.txt");

    // 2. Check if the file opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    std::string line;
    // 3. Read line by line
    while (std::getline(inputFile, line)) {
        std::cout << line << '\n';
    }
    

    // 4. Close the file (Optional: Destructor handles this automatically)
    inputFile.close(); 
    return 0;
}

int save_game(){

    return 0;
};


int list_saves(){

    std::filesystem::directory_iterator iterator;

    std::vector<std::string> save_files;




    

    return 0;
}

int get_which_save(){

    // int which_save;

    list_saves();

    
    return 0;
}

