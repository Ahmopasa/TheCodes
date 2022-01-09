	#include "PickPocket.h"
	#include <time.h>
	#include <iostream>
	#include <stdlib.h>	
		PickPocketGame GamePlayer_2;
		LockPickingGame Guess_GamePlayer_2;
	
		int PickPocketGame::LastReachedLevel() const{ return CurrentLevel; }
				
		bool PickPocketGame::Reset(){
			
		std::cout << "Please press Q to exit, or any key to continue!: ";
		std::cin >> GameResetter;
			
		return (GameResetter[0] == 'Q');
		}
		
		int PickPocketGame::HealthPoints(){
			
		health_points = 30;
		
		return health_points;
		}
		
		bool PickPocketGame::IsGameWon(){ 
		
		bool GameStatus = Reset();
		
		if (GameStatus) {
			std::cout << "Thanks for playing!";
			return false;
		}
		else if (GameStatus) {
			std::cout << "Welcome Back!";
			return true;
		}
		else {
			std::cout << "Welcome Back!";
			return true;
		}
		}
		
		int PickPocketGame::PickPocketInstructions(){
			
			GamePlayer_2.UI();
			int HealthPoints = GamePlayer_2.HealthPoints();
			
	    	std::cout << "You're about to lockpick a case!\n";
	    	std::cout << "\nYou should really be careful\nSince there is a limited time!\n\n";
	
		    std::cout << HealthPoints << " is your health at the start!\n\n+ Every failed attempt will cause you to lose your health.\n";
		    std::cout << "+ The more you failed at the same level, the more you will cause health.\n";
	    	std::cout << "+ When a case opened, you will gain courage that will cause you to gain health points!\n\n";

		return HealthPoints;
		}
		
		void PickPocketGame::UI(){
			
			std::cout << "\n ------------------------------------\n";
			std::cout << "|                                    |\n";
			std::cout << "|                                    |\n";
			std::cout << "|            <<< CASE >>>            |\n";
			std::cout << "|                                    |\n";
			std::cout << "|                                    |\n";
			std::cout << "|                                    |\n";
			std::cout << "|                                    |\n";
			std::cout << "|                                    |\n";
			std::cout << "|                                    |\n";
			std::cout << "|    ___	___	  ___        |\n";
			std::cout << "|                                    |\n";
			std::cout << "|                                    |\n";
			std::cout << "|                                    |\n";
			std::cout << "|                                    |\n";
			std::cout << " ------------------------------------\n";
			return;
		}
		
		void PickPocketGame::PlayGameNow(int HP){
			
			int CurrentLevel = GamePlayer_2.LastReachedLevel();
		
			srand(time(NULL)); 
	
	    	int HintOne = CurrentLevel + rand() % CurrentLevel;
	    	int HintTwo = CurrentLevel + rand() % CurrentLevel;
	    	int HintThree = CurrentLevel + rand() % CurrentLevel;
	    	
		    while (HP > 0 ){
	
		    int HintFour = HintOne + HintTwo + HintThree;
		    int HintFive = HintOne * HintTwo * HintThree;
	
		    std::cout << "\n+ Sum of chosen numbers located on the case is " << HintFour;
		    std::cout << "\n+ Multiply of chosen numbers located on the case is " << HintFive;
		    std::cout << "\n+ So, please find these numbers to unlock the case!\n\n"; 
		
		    std::cout << "Please enter numbers: ";
		    
		   	std::cin >> Guess_GamePlayer_2.FirstChosenValue >> Guess_GamePlayer_2.SecondChosenValue >> Guess_GamePlayer_2.ThirdChosenValue;
			
			std::cin.clear();
			std::cin.ignore();
		
		    int SumChosenValue = Guess_GamePlayer_2.FirstChosenValue + Guess_GamePlayer_2.SecondChosenValue + Guess_GamePlayer_2.ThirdChosenValue;
		    int ProductChosenValue = Guess_GamePlayer_2.FirstChosenValue * Guess_GamePlayer_2.SecondChosenValue * Guess_GamePlayer_2.ThirdChosenValue;
		
		    if (HP == 30 && SumChosenValue == HintFour && ProductChosenValue == HintFive){
		    	
				
		    	
				if (CurrentLevel > 10){
		    	std::cout << "\nYou have unlocked successfully!\nYour level is now " << CurrentLevel+1 << std::endl;
				std::cout << HP << " is the remaining health point!";
		        HintOne = HintOne * 2;
		        HintTwo = HintTwo * 3;
		        HintThree = (HintOne + HintTwo) % 2; 
				
				CurrentLevel++;
				failed_attempt = 0;			    		
				}
		        
		        else {
		        std::cout << "\nYou have unlocked successfully!\nYour level is now " << CurrentLevel+1 << std::endl;
				std::cout << HP << " is the remaining health point!";
		        HintOne = HintOne + 1;
		        HintTwo = HintTwo + 1;
		        HintThree = (HintOne + HintTwo); 
				
				CurrentLevel++;
				failed_attempt = 0;		        	
				}

		    }
		    else if ( HP < 30 &&  SumChosenValue == HintFour && ProductChosenValue == HintFive){
		    	
		    	
		    	
		    	if (CurrentLevel > 10) {
		    	std::cout << "\nYou have unlocked successfully!\nYour level is now " << CurrentLevel+1 << std::endl;
				HP++;
				std::cout << HP << " is the remaining health point!"; 
		        HintOne = HintOne * 2;
		        HintTwo = HintTwo * 3;
		        HintThree = (HintOne + HintTwo) % 2; 
				
				CurrentLevel++;
				failed_attempt = 0;					
				}
				else {
				std::cout << "\nYou have unlocked successfully!\nYour level is now " << CurrentLevel+1 << std::endl;
				HP++;
				std::cout << HP << " is the remaining health point!"; 
		        HintOne = HintOne + 1;
		        HintTwo = HintTwo + 1;
		        HintThree = (HintOne + HintTwo); 
				
				CurrentLevel++;
				failed_attempt = 0;					
				}
			}
		    else {
		        std::cout << "\nYou have failed to unlock!\n";
		        failed_attempt++;
		        HP = HP - 2;
		    	if ( HP <= 10) {
		    		std::cout << HP << " Health point is left. Please, be careful!\n";
		    		if ( failed_attempt >= 3 )
		    			HP = HP - 3;
				}
				else {
					std::cout << HP << " is the remaining health point!\n" << failed_attempt << " is your current failed attemp!\n";
					if ( failed_attempt >= 4)
						HP = HP - 2;
				}
			}
	}
			std::cout << "\n\n\nYou have died. You have no health points!.\n";
			std::cout << CurrentLevel << " is the last level point you have reaced!.\n";
			std::cout << failed_attempt << " times you tried wrongly!\n";
			
		return;
}
