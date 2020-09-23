// Here is the beginning of the menu logic code
// Last edit: September 22, 2020

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

void Process_Selection_One();
void Process_Selection_Two();


static const Menu_Option main_menu[] =
{
  {'1', "Option 1", Process_Selection_One},
  {'2', "Option 2", Process_Selection_Two},
};
static const size_t quantity_selections =
    sizeof(main_menu) / sizeof(main_menu[0]);

int main()
{
  static const char* menu_title = 
    "\n"
    "------------------------------\n"
    "         Main Menu\n"
    "------------------------------\n"
    ;
    bool flag = false; char choice;


    while (flag != true) {
    cout << menu_title; 

    for (size_t i = 0; i < quantity_selections; ++i)
    {
        cout << main_menu[i].p_selection_text << "\n";
    }
    cout << "Enter selection, 0 to quit: ";
    cin >> choice;
    if (choice == '0') { flag = true; break; } 
    for (size_t i = 0; i < quantity_selections; ++i)
      {
        if (choice == main_menu[i].choice)
        {
        Menu_Processing_Function_Pointer p_function = main_menu[i].p_processing_function ;
        p_function();
        break;
        }
      }

    } // while (flag != 1)


  return EXIT_SUCCESS;
} 

void Process_Selection_One()
{ system("cls"); cout << "Hey frenz\n"; return; }


void Process_Selection_Two()
{ system("cls"); cout << "Hey nerdz\n"; return; }
