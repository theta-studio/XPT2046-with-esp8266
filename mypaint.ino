/*
   Copyright (c) 2015-2016  Spiros Papadimitriou

   This file is part of github.com/spapadim/XPT2046 and is released
   under the MIT License: https://opensource.org/licenses/MIT

   This software is distributed on an "AS IS" basis,
   WITHOUT WARRANTY OF ANY KIND, either express or implied.
*/

#include <Arduino.h>
#include <SPI.h>
#include <XPT2046_Touchscreen.h>
#include <Adafruit_ILI9341.h>
#define TFT_DC 2
#define TFT_CS 15
#define CS_PIN  16
#define TIRQ_PIN  5
int xmin=264;
int ymin=273;
int xMax=3775;
int yMax=3733;
int xmargin=xMax-xmin;
int ymargin=yMax-ymin;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN);
Adafruit_GFX_Button button;
void setup() {
  ts.begin();
  ts.setRotation(2);
  tft.begin();

  Serial.print("tftx ="); Serial.print(tft.width()); Serial.print(" tfty ="); Serial.println(tft.height());
  tft.fillScreen(ILI9341_BLACK);
  button.initButton(&tft, 100, 100, 70, 40, ILI9341_DARKCYAN, ILI9341_BLUE, ILI9341_GREENYELLOW, "Clear", 2);
  button.drawButton();
  tft.drawPixel(10, 100, ILI9341_BLUE);
}

static uint16_t prev_x = 0xffff, prev_y = 0xffff;

void loop() {
  uint16_t x, y;
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
     x=(p.x-xmin)*240/xmargin;
     y=(p.y-ymin)*320/ymargin;
    if (prev_x == 0xffff) {
      tft.drawPixel(x, y, ILI9341_BLUE);
    } else {
      tft.drawLine(prev_x, prev_y, x, y, ILI9341_BLUE);
    }
    prev_x = x;
    prev_y = y;
  } else {
    prev_x = prev_y = 0xffff;
  }
  button.press(button.contains(x, y)); // tell the button it is pressed


  // now we can ask the buttons if their state has changed
  if (button.justReleased()) {
    tft.fillScreen(ILI9341_BLACK);
    button.drawButton(); // draw normal
  }

  if (button.justPressed()) {
    button.drawButton(true); // draw invert!
  }
  delay(20);
}
