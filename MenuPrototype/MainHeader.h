// Here is the beginning of the menu logic code
// Last edit: October 13th, 2020
// Sept22 -> got a basic menu working and tested
// Sept23 -> added sub menus and setup for more functionality
// Sept27 -> Worked in sub menu 1 functionality 
// Sept29 -> Tested possibilities for confirmation in submenu 1
// Sept30 -> Finished up functionality with submenu 1 and testing
// Oct13  -> Began creation of sub menu 2 
// Nov23  -> Actually split files and cleaned up code
//


#ifndef HEAD
#define HEAD

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream> 
#include <cstdlib>  
#include "MainMenu.h"
#include "PlayerCountMenu.h"
#include "ColorsMenu.h"

using namespace std; 


typedef void (*Menu_Processing_Function_Pointer)(void);

unsigned int PlayerCount = 0; 
unsigned int PlayerSet = 0; 



// Main function that will use whatever title and submenu necessary
void MenuFunc(const char*, const Menu_Option*); 
void ClearScreen(unsigned int); 

struct Menu_Option
{
  char choice;
  char const * p_selection_text;
  Menu_Processing_Function_Pointer p_processing_function;
};

static const size_t quantity_selections =
    sizeof(main_menu) / sizeof(main_menu[0]);
	
	
#endif //HEAD