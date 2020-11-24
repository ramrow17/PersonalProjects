
#include "MainHeader.h"
#include "MainMenu.h"
#include "PlayerCountMenu.h"
#include "ColorsMenu.h"
//

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



// *****	HERE WE ARE GONNA DO SOME SPINNING THINGS!	*****

void Process_S3Selection1() { return; }
void Process_S3Selection2() { return; }
void Process_S3Selection3() { return; }
void Process_S3Selection4() { return; }


