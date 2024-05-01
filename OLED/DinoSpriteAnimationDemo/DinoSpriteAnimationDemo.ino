/**
 * Animates the Chrome dinosaur from the dinosaur game
 * 
 * Sprite sheet from:
 * https://www.spriters-resource.com/browser_games/googledinosaurrungame/sheet/78171/
 *
 * Converted to byte arrays:
 * http://javl.github.io/image2cpp/
 * 
 * By Jon E. Froehlich
 * @jonfroehlich
 * http://makeabilitylab.io
 *
 */

// #include <SPI.h> Not using SPI so commented out
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 'Dino1', 44x47px
const unsigned char epd_bitmap_dino1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
	0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x03, 0xcf, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xcf, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 
	0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x30, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x30, 0x00, 0x0f, 0xfc, 
	0x00, 0x00, 0x30, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x30, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x3c, 0x03, 
	0xff, 0xff, 0xc0, 0x00, 0x3c, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0x0f, 0xff, 0xfc, 0xc0, 0x00, 
	0x3f, 0x0f, 0xff, 0xfc, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 
	0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x0f, 
	0xcf, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x03, 0x00, 0x00, 0x00, 
	0x00, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Dino2', 44x47px
const unsigned char epd_bitmap_dino2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
	0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 
	0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x30, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x30, 0x00, 0x0f, 0xfc, 
	0x00, 0x00, 0x30, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x30, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x3c, 0x03, 
	0xff, 0xff, 0xc0, 0x00, 0x3c, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0x0f, 0xff, 0xfc, 0xc0, 0x00, 
	0x3f, 0x0f, 0xff, 0xfc, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 
	0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x0f, 
	0xcf, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x03, 0x00, 0x00, 0x00, 
	0x00, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Dino3', 44x47px
const unsigned char epd_bitmap_dino3 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
	0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x03, 0xcf, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xcf, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 
	0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x30, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x30, 0x00, 0x0f, 0xfc, 
	0x00, 0x00, 0x30, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x30, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x3c, 0x03, 
	0xff, 0xff, 0xc0, 0x00, 0x3c, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0x0f, 0xff, 0xfc, 0xc0, 0x00, 
	0x3f, 0x0f, 0xff, 0xfc, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 
	0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x0f, 
	0xc3, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0xc3, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Dino4', 44x47px
const unsigned char epd_bitmap_dino4 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
	0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x03, 0xcf, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xcf, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 
	0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x30, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x30, 0x00, 0x0f, 0xfc, 
	0x00, 0x00, 0x30, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x30, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x3c, 0x03, 
	0xff, 0xff, 0xc0, 0x00, 0x3c, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0x0f, 0xff, 0xfc, 0xc0, 0x00, 
	0x3f, 0x0f, 0xff, 0xfc, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 
	0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x0f, 
	0xc3, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0xc3, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Dino5', 44x47px
const unsigned char epd_bitmap_dino5 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
	0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x03, 0xcf, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xcf, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 
	0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 
	0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x30, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x30, 0x00, 0x0f, 0xfc, 
	0x00, 0x00, 0x30, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x30, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x3c, 0x03, 
	0xff, 0xff, 0xc0, 0x00, 0x3c, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0x0f, 0xff, 0xfc, 0xc0, 0x00, 
	0x3f, 0x0f, 0xff, 0xfc, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 
	0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x0f, 
	0x0f, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc3, 0x00, 0x00, 0x00, 
	0x00, 0x03, 0xc3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1520)
const unsigned char* epd_bitmap_dino_array[5] = {
	epd_bitmap_dino1,
	epd_bitmap_dino2,
	epd_bitmap_dino3,
	epd_bitmap_dino4,
	epd_bitmap_dino5
};

const int SPRITE_WIDTH = 44;
const int SPRITE_HEIGHT = 47;
const int NUM_DINO_SPRITES = 5;

int _dinoSpriteIndex = 0;
int _xSprite = 0; // Sprite x location
int _ySprite = 0; // Sprite y location

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();

  // Center sprite
  _xSprite = display.width() / 2 - SPRITE_WIDTH / 2;
  _ySprite = display.height() / 2 - SPRITE_HEIGHT / 2;
}

void loop() {
  display.clearDisplay();
  display.drawBitmap(_xSprite, _ySprite,  epd_bitmap_dino_array[_dinoSpriteIndex], SPRITE_WIDTH, SPRITE_HEIGHT, WHITE);
  display.display();
  _dinoSpriteIndex++;
  if(_dinoSpriteIndex >= NUM_DINO_SPRITES){
    _dinoSpriteIndex = 0;
  }

  // Change delay here to change animation speed
  // A better way to do this would be to track millis() and switch after every
  // set time allotment
  delay(20);
}