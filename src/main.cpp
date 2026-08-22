#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
// Neopixel
#define NEOPIXEL_PIN 29 //P0_29
// button
#define BUTTON 31 //P0_31
// SDcard
#define SD_MOSI = 6 //P0_06
#define SD_MISO = 8 //P0_08
#define SD_SCK = 11 //P0_11
#define SD_CS = 20 //P0_20
// I2S audio
#define I2S_BCK 32 //P1_00
#define I2S_LCK 38 //P1_06
#define I2S_DIN 36 //P1_04

Adafruit_NeoPixel pixels(1, NEOPIXEL_PIN,  NEO_GRB + NEO_KHZ800);

void setup() {
  
}

void loop() {
  // put your main code here, to run repeatedly:
}