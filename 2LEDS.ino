#include "FastLED.h"

byte bright = 100; // luminosité des LEDs
byte baza = 0;

#define NUM_LEDS_PER_STRIP 150 // nombre de LEDs par bande
#define PIN_LED_STRIP_1 3 // port de connexion de la première bande de LEDs
#define PIN_LED_STRIP_2 4 // port de connexion de la deuxième bande de LEDs

CRGB leds[NUM_LEDS_PER_STRIP * 2]; // 2 bandes de LEDs, chacune avec NUM_LEDS_PER_STRIP LEDs

void setup() {
  FastLED.addLeds <WS2812, PIN_LED_STRIP_1, GRB>(leds, 0, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds <WS2812, PIN_LED_STRIP_2, GRB>(leds, 0, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(bright);
}

void loop() {
    for (int i = 0; i < NUM_LEDS_PER_STRIP; i+=3) {
      leds[i] = CHSV(baza+ i * 5, 255, 255);
      leds[i+1] = CHSV(baza+ i * 5, 255, 255);
      leds[i+2] = CHSV(baza+ i * 5, 255, 255);
    }
    baza++;
    FastLED.setBrightness(bright);
    FastLED.show();
    delay(500); 
}
