#include <iostream>
#include <filesystem>
#include <vector>
#include "./src/headers/menu.h"
#include "./src/headers/configs.h"


int main() {

    system("clear");

    std::filesystem::path configs_path("configs/");
    std::vector<std::string> configs = get_configs(configs_path);
    int choice = -1;

    // Main loop
    while(true) {
        print_options();
        std::cin >> choice;
        int choice_2;

        switch(choice) {
            case 1:
                print_install_menu(configs);
                std::cin >> choice_2;
                break;
            default:
                std::cout << "Please Enter a Valid Choice" << std::endl;
                break;
        }

    }
    return 0;
}
