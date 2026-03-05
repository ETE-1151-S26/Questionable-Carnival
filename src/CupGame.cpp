#include "../include/CupGame.hpp"
#include <iostream>
#include <cstdlib> // For random number generation
#include <ctime> // For seeding random number generator
#include <limits> // For input validation
#include <ctime> // For seeding random number generator
#include "../include/Utility.hpp" // For slowPrint and pause functions

void playCupGame() {
    int CupChoice;
    int ballCup;
    char anotherRound;

    // This variable keeps track of which round the player is on, so we can adjust the shuffle and win conditions accordingly
    int roundNumber = 1; 

    std::srand(std::time(0)); 

    slowPrint("\nA shady character sits in front of you showing you a ball under a cup.", 50);
    
    do {
        // Shuffle Logic: We adjust the shuffle and win conditions based on which round the player is on. The first round is a guaranteed win, but as they keep playing, the chances of winning decrease significantly.
        if (roundNumber == 1) {
            // ROUND 1: Lure shuffle
            ballCup = (std::rand() % 3) + 1; 
            slowPrint("He shuffles the cups at a pace slow enough to follow", 50);
            slowPrint("but long enough that you're suspicious...", 50);
            pause(1000);
            slowPrint("you follow the ball to cup " + std::to_string(ballCup) + ".", 50);
            
        } else if (roundNumber == 2) {
            // ROUND 2: Veteran shuffle
            slowPrint("\nThe shady character says, 'Since you're a veteran now, let's speed things up.'", 40);
            pause(500);
            slowPrint("The cups are shuffled faster than you can follow...", 15); 
            pause(1000);
            slowPrint("...a guess still has a chance...", 50);
            
        } else {
            // ROUND 3+: Quick shuffle
            slowPrint("\nHe doesn't say a word. The cups are instantly shuffled into a blur...", 15);
            pause(1000);
            slowPrint("...make your guess.", 50);
        }
        pause(1000);
        
        slowPrint("\nWhich cup do you think the ball is under? (1, 2, or 3): ", 40);

        // Input validation for the cup choice, with a sarcastic remark for bad input
        bool validInput = false;
        while (!validInput) {
            if (!(std::cin >> CupChoice)) {
                slowPrint("Thats not even a number, what's wrong with you?\n", 50);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (CupChoice < 1 || CupChoice > 3) {
                slowPrint("Can you not count to three? How have you lived this long? ", 50);
            } else {
                validInput = true;
            }
        }
        
        // Scam Logic
        if (roundNumber == 1) { 
            // Guaranteed win!
        } else {
            // Rigged loss
            ballCup = (std::rand() % 3+1); 
            while (ballCup == CupChoice) {
                ballCup = (std::rand() % 3+1);
            }
        } 

        // Reveal the result of their guess with dramatic pauses for effect
        slowPrint("\nYour cup is slowly lifted and... ", 50);
        pause(1000);

        if (ballCup == CupChoice) {
            slowPrint("...", 50);
            pause(300);
            slowPrint("...", 50);
            pause(300);
            slowPrint("...the ball is under cup " + std::to_string(CupChoice) + "! You win! ", 50);
            slowPrint("Beginner's luck! \n", 50);
        } else {
            slowPrint("... ", 50);
            pause(300);
            slowPrint("... ", 50);
            pause(300);
            slowPrint("...the ball is not there! ", 20);
            pause(1000);
            slowPrint("The ball was actually under cup " + std::to_string(ballCup) + "!", 30);
            slowPrint("How unfortunate for you...\n", 50);
        }
        
        // Increase the round counter
        roundNumber++;

        // Ask if they want to play again, with input validation and a sarcastic remark for bad input
        bool validAnswer = false;
        while (!validAnswer) {
            slowPrint("Do you want to test your luck again? (y/n): ", 50);
            std::cin >> anotherRound;
            
            // This clears out any extra letters if they typed a full word like "yes" or "nope"
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Check if user typed a valid letter
            if (anotherRound == 'y' || anotherRound == 'Y' || anotherRound == 'n' || anotherRound == 'N') {
                validAnswer = true;
            } else {
                // The sarcastic remark for bad input
                slowPrint("'y' or 'n'. Type it right, I don't have all day.\n", 40);
            }
        }

    } while (anotherRound == 'y' || anotherRound == 'Y');
}
// Posssible future change, low chance at winning rather than no chance.