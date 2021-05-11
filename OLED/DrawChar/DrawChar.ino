/**
 * Iterates through all the characters in the font. See:
 * https://makeabilitylab.github.io/physcomp/advancedio/oled.html#drawing-text
 * 
 * Adafruit Gfx Library:
 * https://learn.adafruit.com/adafruit-gfx-graphics-library/overview 
 *
 * Adafruit OLED tutorials:
 * https://learn.adafruit.com/monochrome-oled-breakouts
 *  
 * By Jon E. Froehlich
 * @jonfroehlich
 * http://makeabilitylab.io
 *
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 _display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int NEXT_CHAR_BUTTON_INPUT_PIN = 4;
int _lastButtonVal = HIGH;
int _currentCharIndex = 1; // start with frowney face
const int MAX_CHARS = 256;

void setup() {
  Serial.begin(9600);

  pinMode(NEXT_CHAR_BUTTON_INPUT_PIN, INPUT_PULLUP);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!_display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  _display.clearDisplay();
  _display.setTextSize(3);      // Normal 1:1 pixel scale
  _display.setTextColor(SSD1306_WHITE); // Draw white text
  _display.setCursor(0, 0);     // Start at top-left corner

  // Set cp437 to true to use full 256 characters. According to the Adafruit_GFX.h docs
  // There was an error in glcdfont.c for the longest time -- one character (#176, the 'light shade' block) 
  // was missing -- this threw off the index of every character that followed it. But a TON of code has 
  // been written with the erroneous character indices. By default, the library uses the original
  // 'wrong' behavior and old sketches will still work. Pass 'true' to this function to use correct 
  // CP437 character values in your code.
  // See: https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GFX.h
  // 
  // This is generally *NOT* important but only if we are going to iterate through all chars
  _display.cp437(true); 

  showAllChars();

  delay(1000);

  _display.clearDisplay();
  drawChar(_currentCharIndex);
  _display.display(); // show the graphics buffer to screen
}

void loop() {
  
  int buttonVal = digitalRead(NEXT_CHAR_BUTTON_INPUT_PIN);

  // Iterate through 
  if(_lastButtonVal != buttonVal && buttonVal == LOW){
    _display.clearDisplay();
    
    _currentCharIndex++;

    if(_currentCharIndex > MAX_CHARS){
      _currentCharIndex = 0;
    }
    drawChar(_currentCharIndex);
    _display.display(); // show the graphics buffer to screen

    delay(200);
  }

  _lastButtonVal = buttonVal;
}

void showAllChars(){
  _display.setTextSize(1);      // Normal 1:1 pixel scale
  _display.setTextColor(SSD1306_WHITE); // Draw white text
  _display.setCursor(0, 0);     // Start at top-left corner
  
  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  // Notice that we are using .write here rather than .print!
  for(int16_t i=0; i<256; i++) {
    if(i == '\n') _display.write(' ');
    else          _display.write(i);
  }

  _display.display(); // show the graphics buffer to screen
  
}

void drawChar(int charIndex){
  int16_t x1, y1;
  uint16_t textWidth, textHeight;
  _display.setTextSize(3);
  _display.getTextBounds("X", 0, 0, &x1, &y1, &textWidth, &textHeight);
  uint16_t yText = _display.height() / 2 - textHeight + 4;
  uint16_t xText = _display.width() / 2 - textWidth / 2;
  _display.setCursor(xText, yText);
  _display.write(_currentCharIndex);
  yText += textHeight + 4;

  // We could have also done this:
  // _display.drawChar(xText, yText, (char)charIndex, SSD1306_WHITE, SSD1306_BLACK, 3);

  _display.setTextSize(1);
  String strLbl = (String)"Char: " + _currentCharIndex;
  _display.getTextBounds(strLbl, 0, 0, &x1, &y1, &textWidth, &textHeight);
  xText = _display.width() / 2 - textWidth / 2;
  _display.setCursor(xText, yText);
  _display.print(strLbl);
}
