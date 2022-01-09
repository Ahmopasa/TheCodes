#include <iostream>
#include <string>

class PickPocketGame {
	
	public: 
		bool Reset(); // Used
		int LastReachedLevel() const; // Used
		bool IsGameWon(); // Used
		int HealthPoints(); // Used
		int PickPocketInstructions(); // Used
		void PlayGameNow(int); // Used
		void UI();
		
	private: 
		int CurrentLevel = 1;
		int failed_attempt = 0;
		int health_points;
		std::string GameResetter = "";
		
};

	struct LockPickingGame {
	
		int FirstChosenValue = 0;
		int SecondChosenValue = 0;
		int ThirdChosenValue = 0;
};


