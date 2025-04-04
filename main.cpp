#include <iostream>
#include "./src/headers/menu.h"


int main() {

    system("clear");

    int choice = -1;

    // Main loop
    while(true) {
        print_options();
        std::cin >> choice;
        system("clear");

    }
    return 0;
}
