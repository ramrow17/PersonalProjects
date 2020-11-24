#include <Adafruit_NeoPixel.h>

//Numbers that are being used in the generation for the spinny spin
long randNumber;
int pos = 0;
#define NUMPIXELS 60 

//Here is the PIN value used on the arduino
#define PIN 6
int spins = 6;
#define dir 1

// Here is the parameters for the "strip" variable AKA -> Adafruit_NeoPixel(x,y,z);
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)


//Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



void setup()
{
  randomSeed(analogRead(1 + 2 + 3 + 4 + 5));

  pixels.begin();
  colorWipe(0,0);  // Initialize all pixels to 'off'
  pixels.show();
}    /***************end setup****************/

void loop()

{

  randNumber = random(0,NUMPIXELS);    // Generate random number for the pixels on the roulette

  roulette(pixels.Color(NUMPIXELS/2,0,0),pixels.Color(0,0,NUMPIXELS/2),pixels.Color(0,NUMPIXELS/2,0));


}   /*****************END VOID*******************/



/****** Main driver code to initiate the roulette's functionality *********/

void roulette(uint32_t c, uint32_t d, uint32_t e)
{
  float waitTime = .200;    // long variable for adjustable dealy/wait time

  // Full speed spins
  for (int i = 0; i<NUMPIXELS; i++)
  {
    advanceOne(c,d,e, waitTime);

  }
  //    Slow spins & stop
  for ( int i = 0; i <(NUMPIXELS*6)+randNumber; i++)
  {
    advanceOne(c,d,e, waitTime);
    waitTime = (waitTime * 1.05);    // SLOWLY increase waitTime, and thus delay(), each time through the for loop
  }
  delay(10);

  int winner = (pos +1);
  if (winner>NUMPIXELS-1) winner = 0;
 
  uint32_t win = pixels.getPixelColor(winner);

    pixels.setPixelColor(winner, (c+d+e));
    pixels.show();
    delay(10);
    pixels.setPixelColor(winner, win);
    pixels.show();
    delay(10);
    pixels.setPixelColor(winner, (c+d+e));
    pixels.show();
    delay(10);
    pixels.setPixelColor(winner, win);
    pixels.show();

      delay(100);
}    /******************END ROULETTE*****************/

void blinkWinner()

{
  uint32_t win = pixels.getPixelColor(pos);
 
  delay(10);
  colorWipe(0,0);
  pixels.show();
  delay(10);
  pixels.setPixelColor(pos, win);
  pixels.show();
  delay(10); 
  colorWipe(0,0);
  pixels.show();
  delay(10);
  pixels.setPixelColor(pos, win);
  pixels.show();
  delay(10);

}    /*****************END BlinkWinner ******************/



void advanceOne(uint32_t c, uint32_t d, uint32_t e, float wait)
{

  colorWipe(0,0); // Clearing all the pixels for NeoPixel
 
  // it's even
  if ((pos & 0x01) == 0)     
  {   pixels.setPixelColor(pos,c);  }
  
  // it's odd
  else    
  {   pixels.setPixelColor(pos,d);  }
    
  if (pos == 0) pixels.setPixelColor(pos,e);    // or it's "0"


  pixels.show();
  //delay(5);

  if (dir)
  { pos--;
    if(pos<0) pos=NUMPIXELS-1;  } // if(dir)
  
  else
  { pos++;
    if(pos>NUMPIXELS-1) pos=0;  } // else

}    /*************** END AdvanceOne ********************/




// Fill the dots one after the other with a color

void colorWipe(uint32_t c, uint8_t wait) 
{
  for(uint16_t i=0; i<pixels.numPixels(); i++) { 
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(wait);
  }
  
}    /**************END colorWipe *********************/
