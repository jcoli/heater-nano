/**
Version: 0a
Tecnocoli - 06/2022
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F411CE6 - HotPlate Soldier
**/
#include <Arduino.h>

#include "io_defines.h"

void digital_output_begin();

void digital_output_begin(){
    pinMode(PW_LED, OUTPUT);
    pinMode(RUN_LED, OUTPUT);  

}
