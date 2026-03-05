#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "../include/ChickenRodeo.hpp"
#include "../include/Utility.hpp"

//RNG game. All luck no skill. 
//WORKING ON QUIT OPTION. FOR NOW JUST GUESS UNTIL YOU WIN AND CAN QUIT THE GAME.

void ChickenRodeo() {
    char PlayAgain = 'y';//input for this comes from line 62 after completing a round
    do {
    bool Won = false; // Sets the win condition to false at the start of each game loop
    slowPrint(" WELCOME TO THE CHICKEN RODEO!", 20 );
    slowPrint("Catch the chicken, and you win the rodeo. They're slippery ones!", 20);
    pause(1000);
    slowPrint(" The chicken is on the move! You need to guess it's move two times!", 20);
    
        while (!Won) {
        bool ChoiceCorrect = true;

        for (int Move = 1; Move <=2; Move++) { //TWO correct moves needed to win. Increments "move" by 1 after each choice
            int ChickenMove = rand() % 2 + 1; //Generates random number to determine the chicken's movement. Add one so number isn't zero
            int PlayerMove;

            std::cout<< "[Move " << Move << " / 2]" << std::endl;
            slowPrint("Which way will you move to catch the chicken?", 10);
            slowPrint("1. Left", 10);
            slowPrint("2. Straight", 10);
            slowPrint("3. Right", 10);
            //std::cin>> PlayerMove;

            if(!(std::cin>>PlayerMove) || PlayerMove < 1 || PlayerMove > 3) { //Checks for valid input. Thanks gemini
                slowPrint(" What's the matter with you? It's going to get away! enter a number between 1 and 3.", 10);
                std::cin.clear();
                std::cin.ignore(1000, '\n'); //it ignores up to 1000 characters in the input if invalid
                ChoiceCorrect = false;
                break;
            }

            if(PlayerMove != ChickenMove) {
                slowPrint(" You missed the Chicken.", 5);
                slowPrint(" Get up and try again, partner!", 5);
                ChoiceCorrect = false;
                break;
            } else {
                slowPrint(" You move to catch the chicken, and you are on it's tail! Keep it up!", 5);
            }
        
    }

            if (ChoiceCorrect) {
                slowPrint(" You successfully wrangled the chicken and won the rodeo! Congratulations!", 20);
                Won = true;
            }
        }

        //Play again prompt
        slowPrint(" Would you like to play again? (y/n)", 50);
        std::cin>> PlayAgain;
    } while (PlayAgain == 'y');

    slowPrint(" You're a quitter, then? Come back when you want to wrangle again.", 50);

}
