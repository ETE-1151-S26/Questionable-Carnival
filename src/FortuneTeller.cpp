#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "../include/FreakShow.hpp"
#include "../include/Utility.hpp"

void FortuneTeller() {
    //seed for selecting a random fortune
    std::srand(static_cast<unsigned int>(time(0)));

    //array to store the fortunes. ADD MORE WHEN YOU THINK OF SOME. EACH FORTUNE SHOULD FOLLOW THE LINE "The fortune teller says"
    std::string fortunes[]{
        "that a mysterious stranger will offer you something of value. You should accept their offer.",
        "that you will conquer a great feathery beast.",
        "that she sees great dakness in your future.",
        "that you will encounter a bug that is actually a feature of the game.",
        "that you should take it easy on the drinks at the Biergarten.",
        "that you will be forced to take a class with a professor who has a terrible RateMyProfessor score.",
        ""

    };

    // this will calculate the number of fortunes automatically so we can keep adding more if needed
    int fortuneCount = sizeof(fortunes) / sizeof(fortunes[0]);

    char PlayAgain = 'y';

    slowPrint("WELCOME TO THE FORTUNE TELLER'S TENT", 30);
    slowPrint("The fortune teller bids you stare in to her crystal ball.", 30);
    pause(1000);

    while (PlayAgain == 'y'){
        slowPrint("Concentrate on your future.", 30);
        slowPrint("...", 100 );
        pause (500);

        int randomFortune = std::rand() % fortuneCount; //picks fortune from the array

        slowPrint("After peering in to your future, the fortune teller says: ", 10);
        slowPrint(fortunes[randomFortune], 30);

        slowPrint("Shall we keep looking in to your future? (y/n)", 10);
        std::cin>>PlayAgain;


    }

    slowPrint("Go, and heed the words I have given you.", 30);

    }
    