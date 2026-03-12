#include <iostream> // for input and output
#include <vector> //for using vectors
#include <string> // for using strings
#include <limits> // for input validation
#include <thread> // for using sleep function
#include <chrono> // for using sleep function
#include <cstdlib> // for using rand function
#include <ctime> // for seeding random number generator
#include "../include/Utility.hpp" // for using slowPrint and pause functions
#include "../include/SharedState.hpp" // for using shared state variables across files
#include "../include/TrinketShop.hpp" // for using the trinket shop functions
#include "../include/Biergarten.hpp" // for using the Biergarten functions
#include "../include/PettingZoo.hpp" // for using the petting zoo functions
#include "../include/CupGame.hpp" // for using the cup game functions
#include "../include/FreakShow.hpp"
#include "../include/ChickenRodeo.hpp"
#include "../include/FortuneTeller.hpp"
#include "FortuneTeller.cpp"
#include "ChickenRodeo.cpp"
#include "TrinketShop.cpp" // for using the trinket shop functions
#include "Biergarten.cpp" // for using the Biergarten functions
#include "PettingZoo.cpp" // for using the petting zoo functions
#include "CupGame.cpp" // for using the cup game functions
#include "FreakShow.cpp"

// Create the actual variables here
bool acceptedShadyDeal = false;
bool possessesStolenItem = false;
bool itemIsHidden = false;

int main() {
    int choice;
    int stuffed = 0; // Track how stuffed the player is from eating at the Biergarten
    int drunkenness = 0; // Track how drunk the player is from drinking at the Biergarten

    // Greeting and introduction to the carnival
    slowPrint("Welcome to The Questionable Carnival!", 50); 
    slowPrint("Thank you for signing your waiver ahead of time. We hope you enjoy your day at the fair!", 50);
    slowPrint("Where would you like to go first?:" , 50);

    do {    
        // SHADY DEAL CONSEQUENCE CHECK
        if (possessesStolenItem) {
            if (itemIsHidden) {
                slowPrint("\n[!] In the distance, you hear the trinket vendor screaming for the guards about a stolen watch.", 50);
                slowPrint("You smile quietly and blend into the carnival crowd. You got away with it.", 50);
                possessesStolenItem = false; // Resolved safely
            } else {
                slowPrint("\n[!] A carnival guard spots you holding the Golden Pocket Watch!", 50);
                slowPrint("\"Halt! The trinket vendor reported that stolen!\" he yells, grabbing your arm.", 50);
                slowPrint("The guards confiscate the watch and kick you out of the carnival.", 50);
                possessesStolenItem = false; 
                choice = 8; // Automatically triggers the exit condition
                continue; // Skips printing the directory and exits the loop
            }
        }
        // ------------------------------------

        // Directory of attractions
        slowPrint(" \nDirectory:\n", 50);
        pause(1000);
        slowPrint("1 The Trinket Shop", 20);
        slowPrint("2 Biergarten", 20);
        slowPrint("3 The Petting Zoo", 20);
        slowPrint("4 Cup Ball Game", 20);
        slowPrint("5 Chicken Rodeo", 20);
        slowPrint("6 Fortune Teller", 20);
        slowPrint("7 The Freak Show", 20);
        slowPrint("8 Exit Carnival", 20);
        slowPrint("Please enter the number of your choice:", 30);

        // check for correct response from user
        if (!(std::cin >> choice)) {
            std::cout << "Input not recognised. A curious individual you are, we're happy you're here." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        // move user to correct file after input
        switch (choice){
        case 1:
            slowPrint("You walk into the trinket shop and see many curious objects of questionable origin. ", 50);
            trinketShop(); // Added the function call to run the shop
            break;
        case 2:
            slowPrint("You enter the Biergarten, where the smell of fresh pretzels and the sound of laughter fills the air. ", 50);
            // Output based on player's stats after visiting the Biergarten. If they are too drunk or too stuffed, they will be escorted out of the carnival and the game will end.
            if (visitBiergarten(&stuffed, &drunkenness) == false) {
                if (drunkenness >= 100) {
                    slowPrint(" #MEDICAL ESCORT INITIATED# You are being escorted to the nearest hospital due to excessive intoxication. ", 50);
                } else if (stuffed >= 100) {
                    slowPrint(" #MEDICAL ESCORT INITIATED# You are being escorted to the nearest hospital due to overconsumption of food. ", 50);
                }
                choice = 8;} // Exit the carnival
            break;
        case 3:
            slowPrint("You step into the Petting Zoo, greeted by friendly animals eager for attention. ", 50);
            if (startPettingZoo() == false) {
                slowPrint( " #MEDICAL ESCORT INITIATED# You are being escorted to the nearest hospital. ", 50);
                choice = 8; // Exit the carnival
            }
            break;
        case 4:
            slowPrint("You approach the Cup Ball Game, eyeing the colorful cups and the challenge ahead. ", 50);
            playCupGame();
            break;
        case 5:
            slowPrint("You find yourself at the Chicken Rodeo, where brave souls attempt to wrangle the feathery beasts. ", 50);
            ChickenRodeo();
            break;
        case 6:
            slowPrint("You enter the Fortune Teller's tent, where mystical energies seem to swirl around you. ", 50);
            FortuneTeller();
            break;
        case 7:
            slowPrint("You step into The Freak Show, a place where curious individuals showcase themselves.", 50);
            FreakShow();
            break;
        case 8:
            slowPrint("We hope you made good decisions at 'The. Questionable. Carnival!' ", 50);
            break;
        default:
            slowPrint("Invalid choice. Please try again.", 50);
        }
    } while (choice != 8);

    return 0;
}