#include "../include/PettingZoo.hpp"
#include <iostream>
#include <limits> // For input validation
#include <thread> //
#include <chrono> //
#include <cstdlib> // For random number generation if needed
#include "../include/Utility.hpp" // For slowPrint and pause functions

// Returns true if the player exits the petting zoo safely, false if they get injured by an animal
bool startPettingZoo() {
    int choice;
    bool inPettingZoo = true;

    slowPrint("Welcome to the Questionable Petting Zoo!", 50);
    pause(500);
    slowPrint("We have plenty of 'reasonably tame' animals for you today!", 50);
    pause(500);
    slowPrint("Please select an animal to pet:", 50);
    std::cout << "1. Cute Fluffy Sheep" << std::endl;
    pause(500);
    std::cout << "2. Mangey Black Bear" << std::endl;
    pause(500);
    std::cout << "3. Cute Miniature Horse" << std::endl;
    pause(500);
    std::cout << "4. Poised King Cobra" << std::endl;
    pause(500);
    std::cout << "5. Miniature Highland Cow" << std::endl;
    pause(500);
    std::cout << "6. Clearly Feral Honey Badger" << std::endl;

    while (inPettingZoo) {
        slowPrint("Enter the number of the animal you want to pet (or 0 to exit): ", 50);
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 0 and 6." << std::endl;
            continue;
        }

        switch (choice) {
            case 0:
                slowPrint("Thank you for visiting the Questionable Petting Zoo! Goodbye!", 50);
                return true; // Exit the petting zoo
            case 1: // Cute Fluffy Sheep
                slowPrint("You pet the Cute Fluffy sheep...", 50);
                pause(500);
                slowPrint("It bleats happily!", 50);
                break;
            case 2: // Mangey Black Bear
                slowPrint("You attempt to pet the Mangey Black Bear... ", 50);
                pause(500);
                slowPrint("...", 50);
                pause(500);
                slowPrint("It growls and swipes at you!", 50);
                return false; // Exit the petting zoo due to injury
            case 3: // Cute Miniature Horse
                slowPrint("You pet the Cute Miniature Horse... ", 50);
                pause(500);
                slowPrint("It neighs and nuzzles you!", 50);
                break;
            case 4: // Poised King Cobra
                slowPrint("You pet the Poised King Cobra... ", 50);
                pause(500);
                slowPrint("...", 50);
                pause(500);
                slowPrint("It hisses and strikes at you!", 50);
                return false; // Exit the petting zoo due to injury
            case 5: // Miniature Highland Cow
                slowPrint("You pet the Miniature Highland Cow... ", 50);
                pause(500);
                slowPrint("It moos softly and licks your hand!", 50);
                break;
            case 6: // Clearly Feral Honey Badger
                slowPrint("You pet the Clearly Feral Honey Badger... ", 50);
                pause(500);
                slowPrint("...", 50);
                pause(500);
                slowPrint("It bites your hand off!", 50);
                return false; // Exit the petting zoo due to injury
            default:
                std::cout << "Please learn your basic numbers, then enter a number between 0 and 6." << std::endl;
                break;
        }
    }

    return true;
}
