#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

#define OLED_RESET 1
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

void setup(void) {
  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("Found sense");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop(void) {
  uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  
  display.clearDisplay(); 
  display.setTextSize(2);  // Set the text size
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("ColorSense");

  display.setTextSize(1);
  display.setCursor(0,20);
  display.print("Lux:");
  display.setCursor(40,20);
  display.print(lux, DEC);

  display.setCursor(0,30);
  display.print("RED: ");
  display.setCursor(40,30);
  display.print(r, DEC);
  
  display.setCursor(0,40);
  display.print("GREEN: ");
  display.setCursor(40,40);
  display.print(g, DEC);

  display.setCursor(0,50);
  display.print("BLUE: ");
  display.setCursor(40,50);
  display.print(b, DEC);
  display.display();
  }   
