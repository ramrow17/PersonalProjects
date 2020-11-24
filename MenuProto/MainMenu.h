#ifndef MM
#define MM


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




#endif MM
