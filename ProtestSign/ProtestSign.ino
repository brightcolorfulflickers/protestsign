
/*
 * LED Protest Sign
 * by brightcolorfulflickers
 * February 2017
 *
 * github.com/brightcolorfulflickers
 * brightcolorfulflickers.tumblr.com
 * instagram.com/brightcolorfulflickers
 */

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <SD.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 6

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };
String textToPrint = "Hello world";  

const int buttonArray[] = {5,9,10,11,12,13,A1,A0};
const int lengthDipswitch = 8;
const int chipSelect = 4;


void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(255);
  matrix.setTextColor(colors[0]);
  for (int i=0; i < lengthDipswitch; i++) {
    pinMode(buttonArray[i], INPUT);
  }
  Serial.begin(9600);  
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");  
}

int x    = matrix.width();
int pass = 0;
unsigned long prevFrameTime = 0L;             // For animation timing
#define FPS 15 
int checkMessage = 0;

void loop() {
  unsigned long t = millis();
  if((t - prevFrameTime) >= (1000L / FPS)) { // Handle scrolling
      matrix.fillScreen(0);
      matrix.setCursor(x, 0);
      matrix.print(textToPrint);
      int msgLen = (int)textToPrint.length()*6;
      if(--x < -msgLen) {
         x = matrix.width(); // We must repeat!
         checkMessage = 1;
         if(++pass >= 3) pass = 0;
            matrix.setTextColor(colors[pass]);
      }
    matrix.show();
    prevFrameTime = t;
  }
  
  if (checkMessage == 1) {
    int msgCount = 0;
    int msgIndex = readDipswitch();
    File dataFile = SD.open("messages.txt");
    // if the file is available, write to it:
    if (dataFile) {
      while (dataFile.available()) {
        String line = dataFile.readStringUntil('\n');
        if (msgCount == msgIndex) {
          textToPrint = line;  
          Serial.println(line);
        }
        msgCount++;
      }
      dataFile.close();
    }
    // if the file isn't open, pop up an error:
    else {
      Serial.println("error opening txt file");
    }
    checkMessage = 0;
  }
}

int readDipswitch() {
  int dipswitchRead[lengthDipswitch];
  int dipswitchSum = 0;
  for (int i=0; i < lengthDipswitch; i++) {
    dipswitchRead[i] = digitalRead(buttonArray[i]);
    dipswitchSum += dipswitchRead[i]*ipow(2,i);
  }

  return dipswitchSum;
}

int ipow(int base, int exponent) {
  int result = 1;
  while (exponent != 0)
  {
      if ((exponent & 1) == 1)
          result *= base;
      exponent >>= 1;
      base *= base;
  }

  return result;
}
