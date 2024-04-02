#include "FastLED.h"

#define NUM_LEDS 150 // nombre de LEDs
#define BRIGHTNESS 100 // luminosité des LEDs
int L1_b = 0;
int L1_h = 21;
int L2_b = L1_h  + 1;
int L2_h = 76;
int L3_b = L2_h  +1 ;
int L3_h = 101;
int pin_leg = 4;
int pause_timing = 500;

CRGB leds[NUM_LEDS];
CRGB random_color[6];
bool booll1= false;
bool booll2= false;
bool booll3= false;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, 4, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  turnOffStrip(L1_b, L3_h);
  while (!Serial) {
  }
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); 
    input.trim(); 

    if (input == "L1") {
      Serial.print("Verin 1 : ");
      booll1 = lastiter(booll1, L1_b, L1_h, CRGB::Green);
    } else if (input == "L2") {
      Serial.print("Verin 2 : ");
      booll2 = lastiter(booll2, L2_b, L2_h, CRGB::Red); 
    } else if (input == "L3") {
      Serial.print("Verin 3 : ");
      booll3 = lastiter(booll3, L3_b, L3_h, CRGB::Yellow);
    } else {
      Serial.println("Aucun verin");
    }
  }
}

void colorStrip(int startIndex, int endIndex, CRGB color) {
  for (int i = startIndex; i <= endIndex; i++) {
    leds[i] = color; // Définir la couleur des LEDs
  }
  FastLED.show(); // Afficher les couleurs sur les LEDs
}

void turnOffStrip(int startIndex, int endIndex) {
  for (int i = startIndex; i <= endIndex; i++) {
    leds[i] = CRGB::Black; // Éteindre les LEDs
  }
  FastLED.show(); // Afficher les LEDs éteintes
}

bool lastiter(bool lighton, int startIndex, int endIndex, CRGB color) {
  if (lighton == false){
    colorStrip(startIndex, endIndex, color);
    Serial.println("Allumage");
    }
  else{
    turnOffStrip(startIndex, endIndex);
    Serial.println("Extinction"); 
    }
  return lighton = !lighton;
}
