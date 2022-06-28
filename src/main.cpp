#include <Arduino.h>

#include "io_defines.h"
#include "defines.h"
#include "buttons.h"
#include "analog_input.h"
#include "display.h"
#include "pwm_output.h"
#include "digital_output.h"


#define TIMER_INTERVAL_0_3S           300L
#define TIMER_INTERVAL_1S             1000L
#define TIMER_INTERVAL_1_5S           1500L
#define TIMER_INTERRUPT_DEBUG         0
#define _TIMERINTERRUPT_LOGLEVEL_     0
#define TIMER_INTERVAL_MS         100
#define HW_TIMER_INTERVAL_MS      50

void show_display();
void read_analog();
void calc_pid();
void TimerHandler();
void zeroDetect(); 

float celsius = 0;

bool flash_led = false;

//PID


//zero detect
bool zeroChangeDetect = false;
bool lastZeroState = false;

unsigned long loopDelay = millis();
unsigned long loopDelayRead = millis();
unsigned long loopDelayWrite = millis();

extern float erro;
extern float erro_ant;
extern float P;
extern float S;
extern float I;
extern float D;
extern int pwm1;
extern int spValue;
extern int pvValue;

void setup() {
  Serial.begin(115200);
  Serial.println("setup");
  delay(3000);

  pinMode(INT_LED, OUTPUT);
  pinMode(INT_ZERO, INPUT_PULLUP);

  display_begin();
  buttons_begin();

  delay(1000);

  attachInterrupt(digitalPinToInterrupt(INT_ZERO), zeroDetect, CHANGE);
  delay(300);

  analog_input_begin();
  
}

void loop() {
  if ((millis() - loopDelayRead) > 2000){
    loopDelayRead = millis();
    read_analog();
    show_display();
  }
}