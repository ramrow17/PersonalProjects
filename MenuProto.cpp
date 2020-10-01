// Here is the beginning of the menu logic code
// Last edit: September 23, 2020
// Sept22 -> got a basic menu working and tested
// Sept23 -> added sub menus and setup for more functionality
// Sept27 -> Worked in sub menu 1 functionality 
// Sept29 -> Tested possibilities for confirmation in submenu 1
// Sept30 -> Finished up functionality with submenu 1 and testing


#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream> 
#include <cstdlib>  


using namespace std; 


typedef void (*Menu_Processing_Function_Pointer)(void);

static const char* ColorChoices[] = {"Blue", "Orange", "Green", "Red", "Pink", "Yellow", "Purple", "Black"}; 

struct Menu_Option
{
  char choice;
  char const * p_selection_text;
  Menu_Processing_Function_Pointer p_processing_function;
};


unsigned int PlayerCount = 0; 



// Main function that will use whatever title and submenu necessary
void MenuFunc(const char*, const Menu_Option*); 
void ClearScreen(unsigned int); 


// The following functions, menu declaration and functions will be later moved to
// seperate header files to be cleaner for the main code.

// Main Menu Selection 
void Process_MMSelection1(); // go to sub menu 1
void Process_MMSelection2(); // go to sub menu 2 
void Process_MMSelection3(); // go to sub menu 3
void Process_MMSelection4(); // reset all values for things 

static const Menu_Option main_menu[] =
{
  {'1', "1 - SubMenu 1", Process_MMSelection1},
  {'2', "2 - SubMenu 2", Process_MMSelection2},
  {'3', "3 - SubMenu 3", Process_MMSelection3},
  {'4', "4 - SubMenu 4 or is it..?", Process_MMSelection4}
};
// End of declaration for Main menu schtuff




// Sub Menu 1 Selection
// Will be used for the Player amount selection (2-6) 
void Process_S1Selection1(); // Add
void Process_S1Selection2(); // Subtract
void Process_S1Selection3(); // Reset PlayerCount
void Process_S1Selection4(); // Confirm

static const Menu_Option sub1_menu[] =
{
  {'1', "1 - Add", Process_S1Selection1},
  {'2', "2 - Subtract", Process_S1Selection2},
  {'3', "3 - Reset PlayerCount", Process_S1Selection3},
  {'4', "4 - Custom Amount", Process_S1Selection4}
};
// End of declaration for Sub menu 1




// Sub Menu 2 Selection
// Will be used for the Player color selection
void Process_S2Selection1();
void Process_S2Selection2();
void Process_S2Selection3();
void Process_S2Selection4();

static const Menu_Option sub2_menu[] =
{
  {'1', "Option 1", Process_S2Selection1},
  {'2', "Option 2", Process_S2Selection2},
  {'3', "Option 3", Process_S2Selection3},
  {'4', "Option 4", Process_S2Selection4}
};
// End of declaration for Sub menu 2




// Sub Menu 3 Selection
// Will be used for spinning section
void Process_S3Selection1(); //null
void Process_S3Selection2();
void Process_S3Selection3(); //null
void Process_S3Selection4();
// NOTE: Two of these selection will be null (From button press)


static const Menu_Option sub3_menu[] =
{
  {'1', "Option 1", Process_S3Selection1},
  {'2', "Option 2", Process_S3Selection2},
  {'3', "Option 3", Process_S3Selection3},
  {'4', "Option 4", Process_S3Selection4}
};
// End of declaration for Sub menu 3







static const size_t quantity_selections =
    sizeof(main_menu) / sizeof(main_menu[0]);

int main()
{
  static const char* menu_title = 
    "------------------------------\n"
    "         Beginning Menu\n"
    "------------------------------\n"
    ;
	PlayerCount = 2; 
    MenuFunc(menu_title, main_menu); 

  return EXIT_SUCCESS;
} 





// *** 	MAIN MENU SELECTION START HERE 	*** 


void Process_MMSelection1()
{ 
  
  ClearScreen(0);  
  static const char* SubMenuTitle = 
  "------------------------------\n"
  "         First Sub Menu\n"
  "------------------------------\n";


  cout << "Lets go to submenu 1!\n"; 
  ClearScreen(3); 

  MenuFunc(SubMenuTitle, sub1_menu); 

  // Exiting the function...
  cout << "Goodbye - now exiting sub menu 1"; 
  ClearScreen(3);  return; 
  
} // ****  end Process_MMSelection1()  ****




void Process_MMSelection2()
{ 

  ClearScreen(0);  
  static const char* SubMenuTitle = 
  "------------------------------\n"
  "         Second Sub Menu\n"
  "------------------------------\n";


  cout << "Lets go to submenu 2!\n"; 
  ClearScreen(3); 

  MenuFunc(SubMenuTitle, sub2_menu); 

  // Exiting the function...
  cout << "Goodbye - now exiting sub menu 2"; 
  ClearScreen(3);  return; 
  
} // ****  end Process_MMSelection2()  ****




void Process_MMSelection3() 
{

  system("cls"); 
  static const char* SubMenuTitle = 
  "------------------------------\n"
  "         Third Sub Menu\n"
  "------------------------------\n";


  cout << "Lets go to submenu 3!\n"; 
  ClearScreen(3); 

  MenuFunc(SubMenuTitle, sub3_menu); 

  // Exiting the function...
  cout << "Goodbye - now exiting sub menu 3"; 
  ClearScreen(3);  return; 
  
} // ****  end Process_MMSelection3()  ****



void Process_MMSelection4() 
{ 
  ClearScreen(1); 
  cout << "So we're not going into a sub menu or anything but... Hey :-)\n"; 
  Sleep(1000); 
  // Exiting the function...
  cout << "Goodbye - now exiting option 4"; 
  ClearScreen(1);  return; 

} // ****  end Process_MMSelection4()  ****









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








void Process_S2Selection1() { return; }
void Process_S2Selection2() { return; }
void Process_S2Selection3() { return; }
void Process_S2Selection4() { return; }

void Process_S3Selection1() { return; }
void Process_S3Selection2() { return; }
void Process_S3Selection3() { return; }
void Process_S3Selection4() { return; }




// This is the menu function that will display your sub menu 

void MenuFunc(const char* title, const Menu_Option* MenuChoice)
{

  bool flag = false; char choice;

  while (flag != true) {
    cout << title; 

    for (size_t i = 0; i < quantity_selections; ++i)
    {
        cout << MenuChoice[i].p_selection_text << "\n";
    }
	
	
	// *** TEST HERE TO MAKE SURE TERNARY OPERATOR IS WORKING PROPERLY *** 
    cout << "Enter selection, "
		<< ((MenuChoice == main_menu) ?  "enter 0 to quit" : "enter 0 to confirm selection(s)") 
		<< endl; 
		
    cin >> choice;
    if (choice == '0')  { flag = true; break; } 
    for (size_t i = 0; i < quantity_selections; ++i)
      {
        if (choice == MenuChoice[i].choice)
        {
        Menu_Processing_Function_Pointer p_function = MenuChoice[i].p_processing_function ;
        p_function();
        break;
        }
      }

    } // while (flag != 1)


}



void ClearScreen (unsigned int seggs)
{
  Sleep(seggs*1000); 
  system("cls"); // "cls" is used for window - Linux probably would just use "clear"
  return; 
}