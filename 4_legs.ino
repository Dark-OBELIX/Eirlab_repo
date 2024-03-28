#include "FastLED.h"

byte bright = 50; // luminosité des LEDs
byte baza = 0;

#define NUM_LEDS 150 // nombre de LEDs par bande
#define L4 2 
#define L3 4 
#define L1 22  
#define L2 23     
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, L1, GRB>(leds1, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812, L2, GRB>(leds2, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812, L3, GRB>(leds3, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812, L4, GRB>(leds4, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(bright);
}

void loop() {
  int echelle_basse = 0;
  int echelle_haute = NUM_LEDS - 1;
  colorStrip(echelle_basse, echelle_haute, leds1, CRGB::Red); // Rouge
  colorStrip(echelle_basse, echelle_haute, leds2, CRGB::Red); // Rouge
  colorStrip(echelle_basse, echelle_haute, leds3, CRGB::Blue); // Bleu
  colorStrip(echelle_basse, echelle_haute, leds4, CRGB::Blue); // Bleu
}

void colorStrip(int startIndex, int endIndex, CRGB leds[], CRGB color) {
  for (int i = startIndex; i <= endIndex; i++) {
    leds[i] = color; // Définir la couleur des LEDs
  }
  FastLED.show(); // Afficher les couleurs sur les LEDs
}
