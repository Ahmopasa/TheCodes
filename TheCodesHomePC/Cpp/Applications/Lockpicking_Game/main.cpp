	#include <iostream>
	#include <stdlib.h>
	#include <time.h>
	#include "PickPocket.h"
	
	PickPocketGame GamePlayer_1;

	int main(){
	 
	 	bool GameWon = GamePlayer_1.IsGameWon();
	 	int HealthPoints = GamePlayer_1.PickPocketInstructions();
	 	
	while ( GameWon ) {
		
	    GamePlayer_1.PlayGameNow(HealthPoints);
		GameWon = GamePlayer_1.IsGameWon();
	
	}
	
	return 0;
}

