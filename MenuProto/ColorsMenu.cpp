#include "ColorsMenu.h"
#include "MainHeader.h"


// *****	HERE WE PROCESS THE PLAYER NUMBERS WITH THE COLORS!! 	*****

// Set which player will be receiving a color
void Process_S2Selection1() 
{
	unsigned int TempVal = 0; 
	while(((TempVal > PlayerCount) || (TempVal < 1)))
	{
		cout << "Choose the player number you wish to set(1-" << PlayerCount << "): "; 
		cin >> TempVal; 
	}
	cout << "Player " << TempVal << " will now choose their color\n";
  PlayerSet = TempVal; 
	ClearScreen(2); 
	return; }
	
// Set the color for the set player number	
void Process_S2Selection2() 
{ 
	
	unsigned int TempVal = 12; 
	while(((TempVal > 8) || (TempVal < 1)))
	{
		cout << "Set the color for Player " << PlayerSet << ", Choose a number 1-8 for colors (0 to not choose any): ";
		cin >> TempVal; 
  }
    TempVal--;
    if (ColorAvailable[TempVal] == 1)
    {
      cout << "Color " << ColorChoices[TempVal] << " is unavailable!\n"; 
    }
    else if (ColorAvailable[TempVal] == 0)
	    { ColorAvailable[TempVal] = 1;  }
	
	cout << "Player color #" << PlayerSet <<  " is now set to " << ColorChoices[TempVal] << endl; 
  

	return; }
	
// See all the colors available	
void Process_S2Selection3() { return; }

// Print out all the player numbers with their respective color
void Process_S2Selection4() { return; }


