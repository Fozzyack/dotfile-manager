#include <climits>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include "./src/headers/menu.h"
#include "./src/headers/configs.h"



int main() {

    system("clear");

    std::filesystem::path configs_path("configs/");
    std::vector<std::string> configs = get_configs(configs_path);
    std::vector<std::string> config_paths = get_install_locations(configs);
    std::string choice = "-1";
    std::string tmp;


    // Main loop
    while(true) {
        print_options();
        std::cin >> choice;
        std::string choice_2;

        try {
            std::stoi(choice);
        } catch (std::invalid_argument e) {
            choice = "-1";
        }

        switch(std::stoi(choice)) {
            case 1:
                print_install_menu(configs);
                std::getline(std::cin, tmp);
                std::getline(std::cin, choice_2);
                if (choice_2 == "" || choice_2 == "0") install_all_dots(configs, config_paths);
                else {
                    int status = install_individual(choice_2, configs, config_paths);
                    if (status == 1) {
                        std::cout << "Invalid Dotfile Selected [blank or 0 for all] or a [number] to select individual" << std::endl;
                        std::cout << "Press ENTER to continue..." << std::endl;
                    }

                }
                std::getline(std::cin, tmp);
                break;
                
            case 2:
                print_remove_menu(config_paths);
                std::getline(std::cin, tmp);
                std::getline(std::cin, choice_2);
                if (choice_2 == "a") remove_all_dots(config_paths);
                else {
                    int status = remove_individual(choice_2, config_paths);
                    if (status == 1) {
                        std::cout << "Invalid Dotfile Selected [a for all] or a [number] to select individual" << std::endl;
                        std::cout << "Press ENTER to continue..." << std::endl;
                    }
                }

                std::getline(std::cin, tmp);
                break;
            
            case 3:
                system("git pull");
                std::getline(std::cin, tmp);
                break;

            case 4:
                exit(0);
                break;
            default:
                std::cout << "Please Enter a Valid Choice" << std::endl;
                std::cout << "Press ENTER to continue..." << std::endl;
                std::getline(std::cin, tmp);
                std::getline(std::cin, tmp);
                break;
        }

    }
    return 0;
}
