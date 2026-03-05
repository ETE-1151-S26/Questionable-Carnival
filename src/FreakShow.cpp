#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "../include/FreakShow.hpp"
#include "../include/Utility.hpp"

/*Premise of the game is you get mistaken for one of the freak show freaks and are pushed in to the performance.
You have to perform tricks while managing stam and keeping the audience entertained. */



//attempting to use class for player stam and crowd excitement. also has items you can use to restore stam or excite crowd

class Freak {
    private:
        int stamina;
        int crowd_excitement;
        int monsters;
        int beer;

    public:
        Freak(int s, int e, int m, int b) {
            stamina = s;
            crowd_excitement = e;
            monsters = m;
            beer = b;
        }

        bool do_trick(int stam_cost, int excitement_change, int failure_chance){
            bool success;

            int roll = rand() % 100; //chance to fail a trick
            if (roll < failure_chance){ //If your roll is lower than the failure_chance, the trick fails
                stamina -= (stam_cost * 2);
                crowd_excitement -= 10;
                success = false;

            }else { //success if roll succeeds
                stamina -= stam_cost;
                crowd_excitement += excitement_change;
                success = true;
            }

            //makes sure stam doesn't go above 100 or below 0, and excitement levels can't drop below 0
            if (stamina > 100) stamina = 100;
            if (stamina < 0) stamina = 0;
            if (crowd_excitement < 0) crowd_excitement = 0;

            return success;

        }
            // drink a white monster to gain some stam
            //adds 30 stam, subtracts monster from inventory
        void drink_monster(){
            if (monsters > 0) {
                stamina += 30;
                monsters -= 1;
                slowPrint("You down a white monster energy drink. Your stamina increases!",10);
            } else {
                slowPrint("You have no more monsters!", 10);

            }
        }

            // drink a beer to excite and intrigue the crowd
        void drink_beer(){
            if (beer > 0){
                crowd_excitement += 25;
                beer -= 1;
                slowPrint("You shotgun a can of beer. The crowd finds this very entertaining!", 10);
            } else {
                slowPrint("You are out of beers!", 10);
            }
        }

        //for use with pointers and retreving from private section of class
        int getStamina(){
            return stamina;
        }
        int getExcitement() {
            return crowd_excitement;
        }
        int getMonsters(){
            return monsters;
        }
        int getBeer(){
            return beer;
        }
};

// p-> tells code to go to pointer and look for the perameter (stamina, monsters, etc). LESSON 14 IN CLASS NOTES
//This will show the current stamina, crowd excitement, and inventory
void showStats(Freak * p) {
    std::cout<<"STAMINA: "<< p->getStamina()<<std::endl;
    std::cout<<"CROWD EXCITEMENT: " <<p->getExcitement()<<std::endl;
    std::cout<<"INVENTORY: Energy Drinks: "<<p->getMonsters()<<", Beers: "<<p->getBeer()<<std::endl;
}

void FreakShow() {
    srand(time(0)); //seed the rng 

    //player starts with 100 stam, 20 excitement, 2 monsters, and 1 beer
    Freak player(100, 20, 2, 1);

    bool showTime = true;

    slowPrint("As you enter the Freak Show tent, the ringmaster stops you. He is angry that you are not ready for the performance.", 30);
    slowPrint("He pushes you on to the stage...", 30);
    pause (1000);

    slowPrint("WELCOME TO THE FREAK SHOW, LADIES AND GENTELMEN", 30);
    slowPrint("Get the crowd excitement to 100 without losing all your stamina!", 30);
    pause(1000);

    while (showTime){
        showStats(&player);

        //Trickks/acts will be listed from lowest risk to highest risk
        slowPrint("1 Dislocate your shoulder (10 stam, 15 excitement, low risk)", 10);
        slowPrint("2 Walk on hot coals (20 stam, 30 excitement, medium risk)", 10);
        slowPrint("3 Spit fire (35 stam, 50 excitement, high risk)", 10);
        slowPrint("4 Drink a monster energy (Restores stam)", 10);
        slowPrint("5 Shotgun a beer (Excites crowd)", 10);
        slowPrint("6 Quit", 10);

        int choice;
        std::cin>>choice;

        bool success = true;

        switch(choice){ 
            case 1:
                slowPrint("You attempt to dislocate your shoulder.", 10);
                pause(1000);
                success = player.do_trick(10, 15, 5);//First number is stam cost, second is excitement gain, and last number is the percent chance of failure
                break;

            case 2:
                slowPrint("You walk across hot coals, barefoot", 10);
                pause(1000);
                success = player.do_trick(20, 30, 20);
                break;

            case 3:
                slowPrint("You blow fire from your mouth.", 10);
                pause(1000);
                success = player.do_trick(35, 50, 40);
                break;

            case 4:
                player.drink_monster();
                break;
            
            case 5:
                player.drink_beer();
                break;
            
            case 6:
                slowPrint("You run away as quickly as you can.", 10);
                showTime = false;
                continue;

            default:
                slowPrint("You stand there not knowing what to do. The crowd throws tomatoes.", 10);
                player.do_trick(0, -10, 0);
                continue;
                
        }

        //determines the response to the trick
        if (success) {
            slowPrint("SUCCES! THE CROWD ENJOYS THE TRICK!", 10);
        
        }else {
            slowPrint("YOU FAIL TO PERFORM THE TRICK! THE CROWD IS LOSING INTEREST!", 10);
        }
        
        //logic that determines win/loss
    if (player.getStamina() <= 0 || player.getExcitement() <= 0){
        slowPrint("The crowd boos you off the stage! You are a failure!", 30);
        showTime = false;

    } else if (player.getExcitement() >=100) {
        slowPrint("The crowd loved you! You are a HUGE freak!", 30);
        showTime = false;
    }
}

}