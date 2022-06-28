/**
Version: 0a
Tecnocoli - 06/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F411CE6 - HotPlate Soldier
**/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "io_defines.h"
#include "analog_input.h"
#include "pid.h"

void display_begin();
void show_display();

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

extern float celsius;
extern int pwm1;
extern int pwm2;
extern int spValue;

void display_begin(){

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    // Display static text
    display.println("Hello, Tecnocoli!");
    display.display();
    delay(1000);

}


void show_display(){
      display.clearDisplay();
    //   display.display(); 
      // display.setTextSize(1);
      display.setTextColor(WHITE);
      // display.setCursor(0, 0);
      display.setCursor(50, 0);
      display.setTextSize(3);
      display.println(celsius, 0);
      display.setTextSize(2);
      display.setCursor(15, 30);
      display.println(spValue);  
      display.setCursor(90, 30);
      display.println(pwm1);
      // display.setTextSize(2);
      display.display(); 

}