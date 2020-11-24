#ifndef PCM
#define PCM

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




#endif PCM
