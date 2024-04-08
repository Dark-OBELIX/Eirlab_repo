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

  // Éteindre toutes les LEDs au début du programme
  for (int i = 0; i < NUM_LEDS; i++) {
    leds1[i] = CRGB::Black;
    leds2[i] = CRGB::Black;
    leds3[i] = CRGB::Black;
    leds4[i] = CRGB::Black;
  }
  FastLED.show();

  // Initialiser la communication série
  Serial.begin(9600);
}

void loop() {
  int echelle_basse = 0;
  int echelle_haute = NUM_LEDS - 1;

  // Lire l'entrée depuis le terminal série
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input == "L1") {
      toggleLEDs(leds1, CRGB::Red, echelle_basse, echelle_haute);
    } else if (input == "L2") {
      toggleLEDs(leds2, CRGB::Red, echelle_basse, echelle_haute);
    } else if (input == "L3") {
      toggleLEDs(leds3, CRGB::Blue, echelle_basse, echelle_haute);
    } else if (input == "L4") {
      toggleLEDs(leds4, CRGB::Blue, echelle_basse, echelle_haute);
    }
  }
}

void toggleLEDs(CRGB leds[], CRGB color, int startIndex, int endIndex) {
  // Vérifier si la première LED est allumée
  if (leds[startIndex] == color) {
    // Si oui, éteindre toutes les LEDs
    for (int i = startIndex; i <= endIndex; i++) {
      leds[i] = CRGB::Black;
    }
  } else {
    // Si non, allumer toutes les LEDs avec la couleur spécifiée
    for (int i = startIndex; i <= endIndex; i++) {
      leds[i] = color;
    }
  }
  FastLED.show();
}
