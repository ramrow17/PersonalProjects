#ifndef CM
#define CM


static const char* ColorChoices[] = {"Blue", "Orange", "Green", "Red", "Pink", "Yellow", "Purple", "Black"}; 
bool ColorAvailable[] = {0,0,0,0, 0,0,0,0}; 


// Sub Menu 2 Selection
// Will be used for the Player color selection
void Process_S2Selection1(); // Set PlayerNumber
void Process_S2Selection2(); // Choose Set PlayerNumber to color
void Process_S2Selection3(); // See available colors
void Process_S2Selection4(); // Print all PlayerNumbers with Colors

static const Menu_Option sub2_menu[] =
{
  {'1', "Option 1", Process_S2Selection1},
  {'2', "Option 2", Process_S2Selection2},
  {'3', "Option 3", Process_S2Selection3},
  {'4', "Option 4", Process_S2Selection4}
};
// End of declaration for Sub menu 2



#endif CM