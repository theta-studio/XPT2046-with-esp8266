#include <XPT2046_Touchscreen.h>
#include <SPI.h>

#define CS_PIN  16
// MOSI=11, MISO=12, SCK=13

//XPT2046_Touchscreen ts(CS_PIN);
#define TIRQ_PIN  5
//XPT2046_Touchscreen ts(CS_PIN);  // Param 2 - NULL - No interrupts
//XPT2046_Touchscreen ts(CS_PIN, 255);  // Param 2 - 255 - No interrupts
XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN);  // Param 2 - Touch IRQ Pin - interrupt enabled polling

void setup() {
  Serial.begin(38400);
  ts.begin();
  ts.setRotation(2);
  while (!Serial && (millis() <= 1000));
}
int16_t miny = 1000;
int16_t minx = 1000;
int16_t Maxy = 0;
int16_t Maxx = 0;
void loop() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    //Serial.print("Pressure = ");
    //Serial.print(p.z);
    //Serial.print(", x = ");
    //Serial.print(p.x);
    //Serial.print(", y = ");
    //Serial.print(p.y);
    miny = min(miny, p.y);
    minx = min(minx, p.x);
    Maxy = max(Maxy, p.y);
    Maxx = max(Maxx, p.x);
    Serial.print("ymin= ");
    Serial.print(miny);
    Serial.print(" xmin= ");
    Serial.print(minx);
    Serial.print(" yMax= ");
    Serial.print(Maxy);
    Serial.print(" xMax= ");
    Serial.print(Maxx);
    delay(20);
    Serial.println();
  }
}
