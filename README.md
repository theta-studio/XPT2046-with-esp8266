## background
In 2020, the libraly "Adafruit_ILI9341esp.h" seemes to be disappeared from the "Adafruit_ILI9341.h".Then,I made a way without "Adafruit_ILI9341esp.h" to use the touchscreen function of XPT2046 with esp8266. 
## circuit and pin assign
Follow https://macsbug.wordpress.com/2016/04/25/how-to-touch-operation-of-the-tft-lcd-in-esp8266-2/.
## how to test
1. write "calibration.ino" to the esp board to know the range of your touch screen. After writing, open the Seralmonitor and touch the screen as if to fill the whole.At this time, the microcontroller detect the frontier of the screen.
2. open "mypaint.ino" and set the value of xmin,ymin,xMax and ymax as you have had got when wrote the "calibration.ino".Then, write it.
## note
In "calibration.ino",variables of "x" and "y" means each position.
## link
http://www.fattelodasolo.it/2019/12/15/display-tft-2-4-spi-ili9341-con-touch-screen/
