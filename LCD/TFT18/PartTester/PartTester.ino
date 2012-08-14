//////////////////////////////////////////////////////////////////////////////
//
// PartTester - Test Menu and Joystick using a MiniDuino
//
// Hardware -
// Microprocessor Board is a MiniDuino
//    ------> http://dougspcbdesigns.pbworks.com/w/page/55223153/MiniDuino
// 
//  This sketch works with the library for the Adafruit 1.8" TFT Breakout
//  
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Includes follow
//////////////////////////////////////////////////////////////////////////////

#include <MiniDuino.h>       // MiniDuino board library
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

//////////////////////////////////////////////////////////////////////////////
//#define SERIAL_OUT
//////////////////////////////////////////////////////////////////////////////

//#define SERIAL_OUT
#undef SERIAL_OUT

//////////////////////////////////////////////////////////////////////////////
// enums follow
//////////////////////////////////////////////////////////////////////////////

enum MENUITEMS
{
  MENU0,
  MENU1,
  MENU2,
  MENU3,
  MENU4,
  MENU5,
  MENU6,
  MENU7,
  MENU8,
  MENU9,
  MENU10,
  MENU11,
  MENU12,
  MENU13,
  MENU14,
  MENU20,
  MENU21,
  MENU30,
  MENU31,
  MENU40,
  MENU41,
  MENU50,
  MENU51,
  MENU60,
  MENU61,
};

//////////////////////////////////////////////////////////////////////////////
// defines follow
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Global variables follow
//////////////////////////////////////////////////////////////////////////////

int menuState;

MiniDuino myMiniDuino;

int sensNum;

//////////////////////////////////////////////////////////////////////////////
// class initializers
//////////////////////////////////////////////////////////////////////////////

Adafruit_ST7735 tft = Adafruit_ST7735(LCD_CS, LCD_DC, LCD_RST);

//////////////////////////////////////////////////////////////////////////////
// setup()
//////////////////////////////////////////////////////////////////////////////

void setup()  
{
  Serial.begin(9600);

  menuState = MENU0;

  tft.initR(INITR_REDTAB);

  tft.setTextSize(1);
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
  sensNum = 0;
}

//////////////////////////////////////////////////////////////////////////////
// loop()
//////////////////////////////////////////////////////////////////////////////

void loop()                     // run over and over again
{
  testMenu();
}

//////////////////////////////////////////////////////////////////////////////
// clearLine(int lineToClear)
//////////////////////////////////////////////////////////////////////////////

void clearLine(int lineToClear)
{
  setCursorTFT(lineToClear,0);
  tft.print("                     ");
  setCursorTFT(lineToClear,0);
}

//////////////////////////////////////////////////////////////////////////////////////
// setCursorTFT(int row, int col)
//////////////////////////////////////////////////////////////////////////////////////

void setCursorTFT(int row, int col)
{
  tft.setCursor(col*6, row*10);
}

