#include "MainHeader.h"
#include "MainMenu.h"




void ClearScreen (unsigned int seggs)
{
  Sleep(seggs*1000); 
  system("cls"); // "cls" is used for window - Linux probably would just use "clear"
  return; 
}


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
