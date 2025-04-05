#include <iostream>
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
    std::cout << "[2] Update dotfiles (git)" << std::endl;
    std::cout << "[3] Remove Dotfiles" << std::endl;
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
    std::cout << "Enter Choice: " << std::endl;
}

