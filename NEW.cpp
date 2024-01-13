/*Team Members
---------------------------------
20/ENG/139 - Sangeeth Tennakoon
21/ENG/053 - Raveen Shenuka
21/ENG/055 - Samadhi Prathibha*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Minesweeper.h"

using namespace std;

//Main function done by 21/ENG/053
int main() {
    MineSweeper game(0, 0, 0);  

    while (true) {
        int choice;
        std::cout << "1. 10-by-10 (12 mines)" << std::endl;
        std::cout << "2. 15-by-15 (18 mines)" << std::endl;
        std::cout << "3. 20-by-20 (24 mines)" << std::endl;
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

       
        int size, mines, flags;

        switch (choice) {
        case 1:
            size = 10;
            mines = 12;
            flags = 12;
            break;
        case 2:
            size = 15;
            mines = 18;
            flags = 18;
            break;
        case 3:
            size = 20;
            mines = 24;
            flags = 24;

            break;
        default:
            std::cerr << "Invalid choice. Exiting." << std::endl;
            return 1;
        }

        game = MineSweeper(size, mines, flags);

        game.displayBoard();

        while (true) 
        {
            char move[3];
            std::cout << "\nEnter your move (e.g., A1R or ABF): ";
            std::cin >> move;

            if (move[2] == 'R') {
                game.revealLocation(move[1] - 'A', move[0] - 'A');
            } else if (move[2] == 'F') {
                game.flagLocation(move[1] - 'A', move[0] - 'A');
            } else {
                std::cout << "Invalid command. Please enter 'R' for reveal or 'F' for flag." << std::endl;
                continue;
            }

            game.displayBoard();
        }
    }

    return 0;
}
