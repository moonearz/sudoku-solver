#include <iostream>
#include <cstdlib>
#include "square.h"
#include "grid.h"

int main() {
    void printMenu();
    //TEST GRIDS
    std::string mepham_diabolical = "295700860031865020806000000007050006000387000500016700000500109020600350054008672";
    std::string mepham_solution = "295743861431865927876192543387459216612387495549216738763524189928671354154938672";

    std::string option = "";

    while(option != "4") {
        printMenu();
        std::cin >> option;
        std::cout << std::endl;
        while(option != "1" && option != "2" && option != "3" && option != "4") {
            std::cout << "Error: invalid input. Returning to menu..." << std::endl;
            printMenu();
            std::cin >> option;
        }
        if(option == "1") {
            Grid grid = Grid();
            std::string proceed = "";
            while(proceed != "y" && proceed != "Y") {
                std::string userGrid = grid.getGrid();
                grid.setGrid(userGrid);
                std::cout << "Printing entered grid: " << std::endl;
                grid.printGrid();
                std::cout << "Is this the correct grid? (y/n): ";
                std::cin >> proceed;
                std::cout << std::endl;
            }
            if(grid.solve_pp()) {
                std::cout << std::endl << "The puzzle was solved! Press enter to see the solution: " << std::endl;
                std::cin.ignore();
                grid.printGrid();
                std::cout << "Press enter to return to the menu." << std::endl << std::endl;
                std::cin.ignore();
            }
            else {
                std::cout << "Could not solve the puzzle! Returning to the menu..." << std::endl <<std::endl;
            }
        }
        else if(option == "2") {

        }
        else if(option == "3") {
            Grid grid = Grid(mepham_diabolical);
            std::cout << "This is a very challenging puzzle: " << std::endl;
            grid.printGrid();
            std::cout << "Press enter to see the solution!" << std::endl;
            std::cin.ignore();
            grid.solve_pp();
            grid.printGrid();
            std::cout << std::endl;
            std::cout << "Press enter to return to the menu." << std::endl << std::endl;
            std::cin.ignore();
        }
        else {
            break;
        }
    }
    
    return 0;
}

void printMenu() {
    std::cout << std::endl << std::endl;
    std::cout << "###################### SUDOKU SOLVER ######################" << std::endl << std::endl << std::endl;
    std::cout << "Choose an option from the menu: " << std::endl;
    std::cout << "1. Enter in a grid to solve" << std::endl;
    std::cout << "2. Run the test cases" << std::endl;
    std::cout << "3. Demo a very challenging puzzle" << std::endl;
    std::cout << "4. Quit" << std::endl;
}