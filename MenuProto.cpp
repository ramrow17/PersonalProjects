// Here is the beginning of the menu logic code
// Last edit: September 23, 2020
// Sept22 -> got a basic menu working and tested
// Sept23 -> added sub menus and setup for more functionality


#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream> 
#include <cstdlib>  


using namespace std; 

typedef void (*Menu_Processing_Function_Pointer)(void);

struct Menu_Option
{
  char choice;
  char const * p_selection_text;
  Menu_Processing_Function_Pointer p_processing_function;
};


// Main function that will use whatever title and submenu necessary
void MenuFunc(const char*, const Menu_Option*); 



// The following functions, menu declaration and functions will be later moved to
// seperate header files to be cleaner for the main code.

// Main Menu Selection 
void Process_MMSelection1();
void Process_MMSelection2();
void Process_MMSelection3();
void Process_MMSelection4();

static const Menu_Option main_menu[] =
{
  {'1', "Option 1", Process_MMSelection1},
  {'2', "Option 2", Process_MMSelection2},
  {'3', "Option 3", Process_MMSelection3},
  {'4', "Option 4", Process_MMSelection4}
};
// End of declaration for Main menu schtuff




// Sub Menu 1 Selection
// Will be used for the Player amount selection (2-6) 
void Process_S1Selection1();
void Process_S1Selection2();
void Process_S1Selection3();
void Process_S1Selection4();

static const Menu_Option sub1_menu[] =
{
  {'1', "Option 1", Process_S1Selection1},
  {'2', "Option 2", Process_S1Selection2},
  {'3', "Option 3", Process_S1Selection3},
  {'4', "Option 4", Process_S1Selection4}
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

    MenuFunc(menu_title, main_menu); 

  return EXIT_SUCCESS;
} 











void Process_MMSelection1()
{ 
  
  system("cls"); 

  
  
  
  
  // Exiting the function...
  cout << "Goodbye - now exiting sub menu 1"; 
  Sleep(3000); system("cls"); return; 
  
} // ****  end Process_MMSelection1()  ****


void Process_MMSelection2()
{ 
  system("cls"); cout << "Hey nerdz"; Sleep(3000); system("cls"); return; 
  
} // ****  end Process_MMSelection2()  ****

void Process_MMSelection3() { return; }
void Process_MMSelection4() { return; }




void Process_S1Selection1() { return; }
void Process_S1Selection2() { return; }
void Process_S1Selection3() { return; }
void Process_S1Selection4() { return; }

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
    cout << "Enter selection, 0 to quit: ";
    cin >> choice;
    if (choice == '0') { flag = true; break; } 
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
