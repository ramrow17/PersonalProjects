/**************** UPDATED CODE BELOW ***********************/ 


#include <Adafruit_NeoPixel.h>

//Numbers that are being used in the generation for the spinny spin
unsigned long randNumber;
unsigned int pos = 0;
const unsigned int PixSize = 16; //Used for modularity on systems to have different pixels on strips

//Here is the PIN value used on the arduino
#define PIN 6
unsigned int spins = 6;
#define dir 1

// Here is the parameters for the "strip" variable AKA -> Adafruit_NeoPixel(x,y,z);
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)


Adafruit_NeoPixel strip = Adafruit_NeoPixel(PixSize, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  randomSeed(analogRead(1 + 2 + 3 + 4 + 5));

  strip.begin();
  colorWipe(0,0);  // Initialize all pixels to 'off'
  strip.show();
}    /***************end setup****************/

void loop()

{

  randNumber = random(0,PixSize);    // Generate random number for the pixels on the roulette

  roulette(strip.Color(PixSize,0,0),strip.Color(0,0,PixSize),strip.Color(0,PixSize,0));


}   /*****************END VOID*******************/



/****** Main driver code to initiate the roulette's functionality *********/

void roulette(uint32_t c, uint32_t d, uint32_t e)
{
  float waitTime = 4.0;    // long variable for adjustable dealy/wait time

  // Full speed spins
  for (int i = 0; i<PixSize; i++)
  {
    advanceOne(c,d,e, waitTime);

  }
  //    Slow spins & stop
  for ( int i = 0; i <(PixSize*6)+randNumber; i++)
  {
    advanceOne(c,d,e, waitTime);
    waitTime = (waitTime * 1.05);    // SLOWLY increase waitTime, and thus delay(), each time through the for loop
  }
  delay(100);

  int winner = (pos +1);
  if (winner>15) winner = 0;
 
  uint32_t win = strip.getPixelColor(winner);

		strip.setPixelColor(winner, (c+d+e));
		strip.show();
		delay(100);
		strip.setPixelColor(winner, win);
		strip.show();
		delay(200);
		strip.setPixelColor(winner, (c+d+e));
		strip.show();
		delay(100);
		strip.setPixelColor(winner, win);
		strip.show();

		  delay(2000);
}    /******************END ROULETTE*****************/

void blinkWinner()

{
  uint32_t win = strip.getPixelColor(pos);
 
  delay(100);
  colorWipe(0,0);
  strip.show();
  delay(100);
  strip.setPixelColor(pos, win);
  strip.show();
  delay(200); 
  colorWipe(0,0);
  strip.show();
  delay(100);
  strip.setPixelColor(pos, win);
  strip.show();
  delay(200);

}    /*****************END BlinkWinner ******************/



void advanceOne(uint32_t c, uint32_t d, uint32_t e, float wait)
{
  colorWipe(0,0);
 
  if ((pos & 0x01) == 0)     // it's even
  {
    strip.setPixelColor(pos,c);

  }
  else    // it's odd
  {
    strip.setPixelColor(pos,d);

  }
  if (pos == 0) strip.setPixelColor(pos,e);    // or it's "0"

  strip.show();
  delay(wait);

  if (dir)
  {
    pos--;
    if(pos<0) pos=15;

  }
  else
  {
    pos++;
    if(pos>15) pos=0;

  }
}    /*************** END AdvanceOne ********************/




// Fill the dots one after the other with a color

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}    /**************END colorWipe *********************/


