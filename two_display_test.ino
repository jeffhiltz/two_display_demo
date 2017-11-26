/**
 * Draw a rectangle demo on each of two SSD1306.  They have the same i2c address (0x3C)
 * so we switch back and forth between two sets of i2c pins on each loop.
 * 
 * The SCL pin is shared between the two displays so only 3 pins are needed.
 * 
 * Adafruit rules.  I couldn't do this without their libraries.
 */


#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display;

void setup()   {                
  Serial.begin(115200);
}

int toggle = true;

void loop() {
  if (toggle) {
    Serial.println("D2, D1...");
    Wire.begin(D2, D1); // sda, scl
    Adafruit_SSD1306 display(2); // sda
  } else {
    Serial.println("D3, D1...");
    Wire.begin(D3, D1); // sda, scl
    Adafruit_SSD1306 display(3); // sda
  }
  toggle = !toggle;
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // draw rectangles
  display.clearDisplay();
  testdrawrect();
}

void testdrawrect(void) {
  for (int16_t i=0; i<display.height()/2; i+=2) {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, WHITE);
    display.display();
    delay(1);
  }
}



