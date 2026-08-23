#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include "SdFat.h"
#include <bluefruit.h>
// Neopixel
#define NEOPIXEL_PIN 29 //P0_29
// button
#define BUTTON 31 //P0_31
// SDcard
#define SD_MOSI 6 //P0_06
#define SD_MISO 8 //P0_08
#define SD_SCK 11 //P0_11
#define SD_CS 20 //P0_20
// I2S audio
#define I2S_BCK 32 //P1_00
#define I2S_LCK 38 //P1_06
#define I2S_DIN 36 //P1_04

BLEUart bleuart;

void checkSDCard();
void setupBLE();
Adafruit_NeoPixel led(1, NEOPIXEL_PIN,  NEO_GRB + NEO_KHZ800);
SdFat sd;


void setup() {
  Serial.begin(115200);
  led.begin();
  checkSDCard();
  setupBLE();
}

void loop() {

}
void checkSDCard(){
  SPI.setPins(SD_MISO, SD_SCK, SD_MOSI);
  if (!sd.begin(SD_CS, SD_SCK_MHZ(25))) {
    led.setPixelColor(0, led.Color(255, 0, 0));
  }
  else{
    led.setPixelColor(0, led.Color(0, 255, 0));
  }
  led.show();
}
void setupBLE(){
  Bluefruit.begin();
  bleuart.begin();
  Bluefruit.setName("nanoTune");
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addService(bleuart);
  Bluefruit.Advertising.addName();
  Bluefruit.Advertising.start(0);
}