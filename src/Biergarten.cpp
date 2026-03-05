#include "../include/Biergarten.hpp"
#include <iostream>
#include <limits>
#include "../include/Utility.hpp" // For slowPrint and pause functions
#include "../include/SharedState.hpp" // Gives access to the deal variables

bool visitBiergarten(int* stuffedLevel, int* drunkLevel) {
    int choice;
    bool atBar = true;

    // SHADY DEAL HAND-OFF
    if (acceptedShadyDeal) {
        slowPrint("\n[!] The shady figure waves you over to a dark corner behind the kegs.", 50);
        slowPrint("you give him the money you agreed upon.", 50);
        slowPrint("He shoves the Golden Pocket Watch into your hands and quickly disappears into the crowd.", 50);
        
        acceptedShadyDeal = false; // Meetup is over
        possessesStolenItem = true; // Player has the item

        slowPrint("You now have the Golden Pocket Watch.", 50);
        slowPrint("Do you (1) Hold the watch proudly, or (2) Stash it out of sight in your pocket? ", 50);
        
        int stashChoice;
        if (std::cin >> stashChoice && stashChoice == 2) {
            itemIsHidden = true;
            slowPrint("You carefully hide the watch out of sight.", 50);
        } else {
            itemIsHidden = false;
            slowPrint("You hold the watch out in the open for everyone to see.", 50);
            // Clear buffer just in case they typed a letter instead of a 1
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        slowPrint("You step back out of the shadows into the main Biergarten area.", 50);
    }
    // ---------------------------

    slowPrint("\nYou push through the swinging doors of the Biergarten.", 50);
    slowPrint("'WILLKOMMEN TO THE BIERGARTEN!' a burly bartender shouts.", 50);
    slowPrint("'What're you having?'\n", 50);

    while (atBar) {
        // Show the player their current stats!
        std::cout << "\n[STATS] Drunk: " << *drunkLevel << "% | Stuffed: " << *stuffedLevel << "%\n" << std::endl;
        
        slowPrint("--- DRINK MENU ---", 20);
        slowPrint("1. Standard Lager (20oz.)", 40);
        slowPrint("2. The 'Swamp Water' Stout (10oz)", 40);
        slowPrint("3. Flaming Cinnamon Schnapps ", 40);
        slowPrint("4. Das Boot of Dunkelweizen (67oz.)", 40);
        slowPrint("5. 'Liquid Regret' Mystery Shot ", 40);
        
        slowPrint("\n--- FOOD MENU ---", 20);
        slowPrint("6. Giant Bavarian Pretzel ", 40);
        slowPrint("7. Traditional Bratwurst ", 40);
        slowPrint("8. Crispy Pork Schnitzel ", 40);
        slowPrint("9. Hendl (Half Roasted Chicken) ", 40);
        
        slowPrint("\n0. Leave the Biergarten", 40);
        slowPrint("\nEnter your choice: ", 40);

        bool validInput = false;
        while (!validInput) {
            if (!(std::cin >> choice)) {
                std::cout << "The bartender squints. 'Speak up, or get out.'\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                validInput = true;
            }
        }

        // MENU LOGIC
        switch (choice) {
            case 0:
                slowPrint("\nYou nod at the bartender and head back out to the carnival.", 40);
                return true; //How to exit the Biergarten without getting kicked out

            // DRINKS
            case 1:
                slowPrint("\nYou chug that lager down.", 40);
                *drunkLevel += 15;
                *stuffedLevel += 5;
                break; 

            case 2:
                slowPrint("\nYou chug the thick, green liquid. Your vision blurs instantly.", 40);
                *drunkLevel += 40;
                *stuffedLevel += 5;
                break;

            case 3:
                slowPrint("\nThe bartender lights a shot glass on fire. You blow it out and take the shot. It burns the whole way down.", 40);
                *drunkLevel += 25;
                break;

            case 4:
                slowPrint("\nYou are handed a glass boot the size of a boot. Good luck chugging this one.", 40);
                *drunkLevel += 20;
                *stuffedLevel += 15; // Liquid takes up stomach space too!
                break;

            case 5:
                slowPrint("\nThe bartender pours something from an unmarked jug. You instantly regret your choices.", 40);
                *drunkLevel += 50; // Super dangerous!
                break;

            // --- FOOD ---
            case 6:
                slowPrint("\nYou devour a pretzel the size of a steering wheel. It's heavily salted.", 40);
                *stuffedLevel += 35;
                break;

            case 7:
                slowPrint("\nYou eat a sizzling bratwurst loaded with spicy mustard.", 40);
                *stuffedLevel += 20;
                break;

            case 8:
                slowPrint("\nA plate-sized slab of fried pork is set before you. It's delicious and incredibly heavy.", 40);
                *stuffedLevel += 30;
                break;

            case 9:
                slowPrint("\nYou tear into half a roasted chicken. Grease covers your fingers. You are incredibly full.", 40);
                *stuffedLevel += 45; // Very dangerous!
                break;

            default:
                slowPrint("\n'I don't have that,' he growls. 'Pick something on the menu.'", 40);
                break;
        }

        // --- CHECK LIMITS AFTER EVERY ORDER ---
        if (*drunkLevel >= 100) {
            slowPrint("\nThe room spins aggressively. You hit the floor...", 40);
            return false; // Kicks them out!
        }
        
        if (*stuffedLevel >= 100) {
            slowPrint("\nYou ate too much. You turn pale, ruin the floor, and are thrown out!", 40);
            return false; // Kicks them out!
        }
    }
    return true;
}