#include "Menu.h"

extern int menuChoice = 0; //extern example to share data with menu and gameSource

void Menu::Run() 
{
    bool valid = false;
    int choice;
    do { //do while
        system("cls"); // clear the screen
        std::cout << "Start Screen:" << '\n';
        std::cout << "1. Quit" << '\n';
        std::cout << "2. Play Space Invaders" << '\n';
        std::cout << "3. Play Frogger" << '\n';
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            menuChoice = 1;
            valid = true;
            system("cls"); // clear the screen
            break;
        case 2:
            menuChoice = 2;
            valid = true;
            system("cls"); // clear the screen
            break;
        case 3:
            menuChoice = 3;
            valid = true;
            system("cls"); // clear the screen
            break;
        default:
            std::cout << "Invalid choice. Please try again." << '\n';
            break;
        }

        if (!valid) {
            std::cout << "Press any key to continue..." << '\n';
            _getch(); // wait for user to press any key
        }
    } while (!valid);

}