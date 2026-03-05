#include "../include/TrinketShop.hpp"
#include <iostream>
#include <limits> // For clearing input
#include "../include/SharedState.hpp" // Gives access to the deal variables
#include "../include/Utility.hpp" // For slowPrint and pause functions

using namespace std;

// Shop sections
void shopJewelry();
void shopAntiques();
void shopArt();
void shopCostumes();
void shopMagic();

// Trinket Shop main function
void trinketShop() {
    int choice = 0;

    // This only prints once when you first enter the tent
    slowPrint("\nGRAND TRINKET TENT", 50);
    slowPrint("The area is large and cluttered.", 50);

    while (choice != 6) {
        // SHOP DIRECTORY
        slowPrint("\nTENT DIRECTORY", 50);
        slowPrint("Which section do you visit?", 50);
        slowPrint("1. The Jewelry Counter", 50);
        slowPrint("2. The Antique Corner", 50);
        slowPrint("3. The Art Gallery", 50);
        slowPrint("4. The Wardrobe (Costumes & Hats)", 50);
        slowPrint("5. The Prank Shelf (Magic Tricks & Gags)", 50);
        slowPrint("6. Leave the Shop", 50);
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            // Error handling for non-integer input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: shopJewelry(); break;
            case 2: shopAntiques(); break;
            case 3: shopArt(); break;
            case 4: shopCostumes(); break;
            case 5: shopMagic(); break;
            case 6: slowPrint("You step out of the shop back into the carnival noise.\n", 50); break;
            default: slowPrint("That section doesn't seem to exist.\n", 50); break;
        }
    }
}

// Tent sections with potential for shady character interactions

void shopJewelry() {
    slowPrint("\nJEWELRY SECTION", 50);
    slowPrint("Glass cases display rings, necklaces, and strange amulets.", 50);
    slowPrint("One item catches your eye: A heavy Golden Pocket Watch.", 50);
    slowPrint("1. Examine the Silver Ring", 50);
    slowPrint("2. Examine the Golden Pocket Watch", 50);
    slowPrint("3. Go back", 50);
    
    int subChoice;
    cout << "Choice: ";
    cin >> subChoice;
   
    if (subChoice == 2) {
        slowPrint("It's magnificent. The craftsmanship is immaculate.", 50);
        
        // Only trigger if the deal hasn't happened yet
        if (!acceptedShadyDeal && !possessesStolenItem) {
            slowPrint("\nAs you admire the watch, a cloaked figure approaches.", 50);
            slowPrint("\"I can get you that exact watch half off. Meet me at the Biergarten...\" he whispers.", 50);
            slowPrint("Do you agree to meet him? (Y/N): ", 50);

            char dealChoice;
            cin >> dealChoice;

            if (dealChoice == 'Y' || dealChoice == 'y') {
                acceptedShadyDeal = true;
                slowPrint("He nods and slips away into the crowd. You should head to the Biergarten.", 50);
            } else {
                slowPrint("You shake your head, and he vanishes back into the crowd.", 50);
            }
        }
    } else if (subChoice == 1) {
        slowPrint("A simple silver band. Nice, but nothing special.", 50);
    }
}

void shopAntiques() {
    slowPrint("\nANTIQUES SECTION", 50);
    slowPrint("The air smells of dust.", 50);
    slowPrint("1. Inspect the painted vase", 50);
    slowPrint("2. Inspect the engraved sword", 50);
    slowPrint("3. Go back", 50);
    
    int subChoice;
    cout << "Choice: ";
    if (!(cin >> subChoice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return; }

    if (subChoice == 1) {
        slowPrint("It looks like it might shatter if you breathe on it too hard.", 50);
    } else if (subChoice == 2) {
        slowPrint("The blade is dull and covered in rust. Not very useful.", 50);
    }
}

void shopArt() {
    slowPrint("\nART GALLERY", 50);
    slowPrint("Strange paintings seem to watch you as you move.", 50);
    slowPrint("1. Look at the portrait of the Sad Clown", 50);
    slowPrint("2. Look at the sculpture of a Hydra", 50);
    slowPrint("3. Go back", 50);
    
    int subChoice;
    cout << "Choice: ";
    if (!(cin >> subChoice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return; }

    if (subChoice == 1) {
        slowPrint("The clown's eyes seem to follow you...", 50);
    } else if (subChoice == 2) {
        slowPrint("A beautiful bronze sculpture with seven terrifying heads.", 50);
    }
}

void shopCostumes() {
    slowPrint("\nCOSTUME WARDROBE", 50);
    slowPrint("Racks of colorful fabric block your path.", 50);
    slowPrint("1. Try on the Jester's Hat", 50);
    slowPrint("2. Try on the Lion Mask", 50);
    slowPrint("3. Go back", 50);
    
    int subChoice;
    cout << "Choice: ";
    if (!(cin >> subChoice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return; }

    if (subChoice == 1) {
        slowPrint("The bells jingle loudly as you place it on your head.", 50);
    } else if (subChoice == 2) {
        slowPrint("It smells a little musty, but it looks fierce.", 50);
    }
}

void shopMagic() {
    slowPrint("\nMAGIC & PRANKS", 50);
    slowPrint("This section is filled with whoopee cushions and fake wands.", 50);
    slowPrint("1. Pick up the Deck of Cards", 50);
    slowPrint("2. Shake the Mystery Box", 50);
    slowPrint("3. Go back", 50);
    
    int subChoice;
    cout << "Choice: ";
    if (!(cin >> subChoice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return; }

    if (subChoice == 1) {
        slowPrint("Every single card in the deck is the Ace of Spades.", 50);
    } else if (subChoice == 2) {
        slowPrint("Something inside rattles, followed by a faint giggling sound.", 50);
    }
}