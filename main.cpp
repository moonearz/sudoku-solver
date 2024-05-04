#include <iostream>
#include <cstdlib>
#include <chrono>
#include "square.h"
#include "grid.h"

int main() {
    void printMenu();
    void perfTest(std::vector<std::string> test_grids);
    //TEST GRIDS
    std::string mepham_diabolical = "295700860031865020806000000007050006000387000500016700000500109020600350054008672";
    std::string mepham_solution = "295743861431865927876192543387459216612387495549216738763524189928671354154938672";

    std::string option = "";
    std::string temp = "";

    while(option != "4") {
        printMenu();
        std::cin >> option;
        std::cin.ignore();
        std::cout << std::endl;
        while(option != "1" && option != "2" && option != "3" && option != "4") {
            std::cout << "Error: invalid input. Returning to menu..." << std::endl;
            printMenu();
            std::cin >> option;
            std::cin.ignore();
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
                std::cin.ignore();
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
            std::vector<std::string> hard_puzzles;
            std::vector<std::string> hardest_puzzles;
            std::string line;
            std::ifstream file_hard("test_cases.txt");
            std::ifstream file_hardest("hardest.txt");
            while(getline(file_hard, line)) {
                hard_puzzles.push_back(line);
            }
            file_hard.close();
            while(getline(file_hardest, line)) {
                hardest_puzzles.push_back(line);
            }
            file_hardest.close();
            std::cout << "Running a performance test on 95 hard puzzles: " << std::endl;
            perfTest(hard_puzzles);
            std::cout << "Running a performance test on 11 extremely difficult puzzles: " << std::endl;
            perfTest(hardest_puzzles);
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

void perfTest(std::vector<std::string> test_grids) {
    Grid grid = Grid();
    double total_time = 0;
    int num_correct = 0;
    for(int i = 0; i < test_grids.size(); i++) {
        grid.setGrid(test_grids[i]);
        std::cout << "Solving this puzzle: " << std::endl;
        grid.printGrid();
        
        auto begin = std::chrono::high_resolution_clock::now();
        bool solved = grid.solve_pp();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms_double = end - begin;
        if(solved) {
            std::cout << "Solved the puzzle in " << ms_double.count() << " milliseconds" << std::endl;
            std::cout << "Solution: " << std::endl;
            grid.printGrid();
            num_correct++;
            total_time += ms_double.count();
            }
        else {
            std::cout << "Failed on puzzle " << i + 1 << std::endl;
        }
    }
    std::cout << "Solved " << num_correct << "/" << test_grids.size() << " puzzles correctly with an average speed of ";
    if(num_correct > 0) {
        std::cout << total_time / num_correct;
    }
    else {
        std::cout << "-";
    }
    std::cout << " milliseconds." << std::endl;
}