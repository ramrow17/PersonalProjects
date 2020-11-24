#include "MainHeader.h"
#include "MainMenu.h"
#include "PlayerCountMenu.h"






// ********* BEGIN PLAYER COUNT SUB MENU *********


// *** 		ADDING 1 TO PLAYER COUNT 	****
void Process_S1Selection1() {
  if (PlayerCount < 6) PlayerCount++;
  cout << "Updated player count: " << PlayerCount << endl;
  ClearScreen(1); 
  return;
}


// **** 	REDUCING PLAYERCOUNT BY 1 	****
void Process_S1Selection2() { 
  if (PlayerCount > 2) PlayerCount--; 
  cout << "Updated player count: " << PlayerCount << endl; 
  ClearScreen(1); 
  return;
}


// **** 	RESETTING PLAYERCOUNT   	****
void Process_S1Selection3() { 
	PlayerCount = 2; cout << "Updated player count: " << PlayerCount << endl; 
  ClearScreen(1);  return; 
   }

// ****		CUSTOM PLAYERCOUNT VAL		****
void Process_S1Selection4() { 

	unsigned int TempVal = 0;
	
	// *** Need to test this while loop, the not symbols might be wrong idk
	while(((TempVal > 6) || (TempVal < 2)))
	{
		cout << "Enter any number 2-6:";
		cin >> TempVal;	
	}
	
	cout << "Updated player count: " << TempVal << endl; 
	PlayerCount = TempVal; ClearScreen(1); 
	return; 
}
