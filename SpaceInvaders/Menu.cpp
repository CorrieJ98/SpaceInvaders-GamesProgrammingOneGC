#include "Menu.h"

extern int menu_choice = 0; //extern example to share data with menu and gameSource

void Menu::Run() 
{
    bool valid = false;
    int choice;

    do { //do while
        system("cls"); // clear the screen
        std::cout << "Start Screen:" << std::endl;
        std::cout << "1. Quit" << std::endl;
        std::cout << "2. Play Space Invaders" << std::endl;
        std::cout << "3. Play Frogger" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        
        case 1:
            menu_choice = 1;
            valid = true;
            system("cls"); // clear the screen
            break;
        case 2:
            menu_choice = 2;
            valid = true;
            system("cls"); // clear the screen
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }

        if (!valid) {
            std::cout << "Press any key to continue..." << std::endl;
            _getch(); // wait for user to press any key
        }
    } while (!valid);

}