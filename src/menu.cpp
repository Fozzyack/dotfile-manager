#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

/*
 * Holds all the ui for the menu
 */


void print_divider() {
    std::cout << "=================================================================" << std::endl;
}
void print_title() {
    std::cout << "\n"
" ██████╗  ██████╗ ████████╗███████╗██╗██╗     ███████╗\n"
" ██╔══██╗██╔═══██╗╚══██╔══╝██╔════╝██║██║     ██╔════╝\n"
" ██║  ██║██║   ██║   ██║   █████╗  ██║██║     █████╗\n"
" ██║  ██║██║   ██║   ██║   ██╔══╝  ██║██║     ██╔══╝\n"
" ██████╔╝╚██████╔╝   ██║   ██║     ██║███████╗███████╗\n"
" ╚═════╝  ╚═════╝    ╚═╝   ╚═╝     ╚═╝╚══════╝╚══════╝\n"
" \n"
" ███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗ ███████╗██████╗\n"
" ████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝ ██╔════╝██╔══██╗\n"
" ██╔████╔██║███████║██╔██╗ ██║███████║██║  ███╗█████╗  ██████╔╝\n"
" ██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ██╔══██╗\n"
" ██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╔╝███████╗██║  ██║\n"
" ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝\n"
<< std::endl;
}

void print_options() {
    system("clear");
    print_title();
    print_divider();
    std::cout << "[1] Install dotfiles" << std::endl;
    std::cout << "[2] Remove Dotfiles" << std::endl;
    std::cout << "[3] Install Tools (Bash)" << std::endl;
    std::cout << "[4] Install Tools (Fish)" << std::endl;
    std::cout << "[5] Update dotfiles (just a git pull)" << std::endl;
    std::cout << "[6] Exit" << std::endl;
    print_divider();
    std::cout << "Enter Choice: ";
}


void print_install_menu(std::vector<std::string> &configs) {
    system("clear");
    print_title();
    print_divider();
    std::cout << "[default] Install all dotfiles" << std::endl; 
    std::cout << "[num] Install a specific dotfile" << std::endl; 
    print_divider();
    std::cout << "Configs Found (in configs file): " << std::endl;
    for (size_t i = 0; i < configs.size(); i++ ){
        std::cout << "[" << i + 1 << "] " << configs[i] << std::endl;
    }
    print_divider();
    std::cout << "Enter Choice: ";
}

void print_remove_menu(std::vector<std::string> &config_paths) {
    system("clear");
    print_title();
    print_divider();
    std::cout << "[a] Remove all Dotfiles" << std::endl;
    std::cout << "[num] Remove a specific dotfile" << std::endl;
    print_divider();
    for(size_t i = 0; i < config_paths.size(); i++) {
        if (std::filesystem::is_directory(config_paths[i]) || std::filesystem::is_regular_file(config_paths[i])) {
            std::cout << "[" << i + 1 << "] " << config_paths[i] << std::endl;
        }
    }
    print_divider();
    std::cout << "Enter Choice (blank for none): ";
}

