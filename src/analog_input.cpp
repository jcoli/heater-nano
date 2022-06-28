/**
Version: 0a
Tecnocoli - 06/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F411CE6 - HotPlate Soldier
**/
#include <Arduino.h>

#include "io_defines.h"

void read_analog();


const float beta = 4200.0;
const float r0 = 100000.0;
const float t0 = 273.0 + 25.0;
const float rx = r0 * exp(-beta/t0);
const int nAmostras = 10;
const float vcc = 5;
const float R = 85000.0;

float sumCelsius = 0;

extern float celsius;

void analog_input_begin(){
    analogReference(EXTERNAL);
    
    float soma = 0;

    for (int i = 0; i < nAmostras; i++) {
        soma += analogRead(THERM1);
        delay (5);
    }
    delay(500);
    float v = (vcc*soma)/(nAmostras*1023.0);
    float rt = (vcc*R)/v - R;

    // Calcula a temperatura
    double t = beta / log(rt/rx);
    float tempcelsius = t -273.0;
    sumCelsius = tempcelsius*3;
    celsius = sumCelsius/3;
}

void read_analog(){
      float soma = 0;
      for (int i = 0; i < nAmostras; i++) {
        soma += analogRead(THERM1);
        delay (5);
      }
      float v = (vcc*soma)/(nAmostras*1023.0);
      float rt = (vcc*R)/v - R;
    
      // Calcula a temperatura
      double t = beta / log(rt/rx);
      float tempcelsius = t -273.0;
      sumCelsius = sumCelsius-celsius+tempcelsius;
      celsius = (sumCelsius/3);
      // Serial.print("temp: ");
      // Serial.println(celsius);


}