#include "FastLED.h"

#define NUM_LEDS 150 // nombre de LEDs
#define BRIGHTNESS 100 // luminosité des LEDs

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, 4, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void colorStrip(int startIndex, int endIndex, int pin, CRGB color) {
  for (int i = startIndex; i <= endIndex; i++) {
    leds[i] = color; // Définir la couleur des LEDs
  }
  FastLED.show(); // Afficher les couleurs sur les LEDs
}

void loop() {
  // Exemples d'utilisation de la fonction colorStrip() avec différentes couleurs
 // int echelle_basse = 93;
 // int echelle_haute = 149;
  int echelle_basse = 43;
  int echelle_haute = 92;
  colorStrip(echelle_basse, echelle_haute, 4, CRGB::White); // Blanc
  delay(500); 

  colorStrip(echelle_basse, echelle_haute, 4, CRGB::Yellow); // Jaune
  delay(500); 

  colorStrip(echelle_basse, echelle_haute, 4, CRGB::Red); // Rouge
  delay(500); 

  colorStrip(echelle_basse, echelle_haute, 4, CRGB::Blue); // Bleu
  delay(500); 

  colorStrip(echelle_basse, echelle_haute, 4, CRGB::Green); // Vert
  delay(500); 
}
