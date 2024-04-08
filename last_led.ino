#include "FastLED.h"

#define L4 2 
#define L3 4 
#define L1 22  
#define L2 23     
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];
byte bright = 50; // luminosité des LEDs

String previousData = "";

void setup() {
  Serial.begin(9600); 
  FastLED.addLeds<WS2812, L1, GRB>(leds1, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812, L2, GRB>(leds2, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812, L3, GRB>(leds3, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812, L4, GRB>(leds4, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(bright);
}

void loop() {
  if (Serial.available() > 0) { 
    String newData = Serial.readStringUntil('\n'); 
    
    if (newData != previousData) { 
      previousData = newData; 
      int echelle_basse = 0;
      int echelle_haute = NUM_LEDS - 1;
      colorStrip(echelle_basse, echelle_haute, newData, CRGB::Red); // Rouge
    }
  }
}

void colorStrip(int startIndex, int endIndex, CRGB leds[], CRGB color) {
  for (int i = startIndex; i <= endIndex; i++) {
    leds[i] = color; // Définir la couleur des LEDs
  }
  FastLED.show(); // Afficher les couleurs sur les LEDs
}
