   #include "FastLED.h"

byte bright = 50; // luminosité des LEDs
byte baza = 0;

#define NUM_LEDS 150 // nombre de LEDs par bande
#define PIN1 2  
#define PIN2 4 
#define PIN3 22  
#define PIN4 23     
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, PIN1, GRB>(leds1, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812, PIN2, GRB>(leds2, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812, PIN3, GRB>(leds3, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812, PIN4, GRB>(leds4, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(bright);
}

void loop() {
    for (int i = 0; i < NUM_LEDS; i+=3) {
      leds1[i] = CHSV(baza + i * 5, 255, 255);
      leds1[i+1] = CHSV(baza + i * 5, 255, 255);
      leds1[i+2] = CHSV(baza + i * 5, 255, 255);
      
      leds2[i] = CHSV(baza + i * 5, 255, 255);
      leds2[i+1] = CHSV(baza + i * 5, 255, 255);
      leds2[i+2] = CHSV(baza + i * 5, 255, 255);
      
      leds3[i] = CHSV(baza + i * 5, 255, 255);
      leds3[i+1] = CHSV(baza + i * 5, 255, 255);
      leds3[i+2] = CHSV(baza + i * 5, 255, 255);
      
      leds4[i] = CHSV(baza + i * 5, 255, 255);
      leds4[i+1] = CHSV(baza + i * 5, 255, 255);
      leds4[i+2] = CHSV(baza + i * 5, 255, 255);
    }
    baza++;
    FastLED.setBrightness(bright);
    FastLED.show();
    //delay(500); 
} 
