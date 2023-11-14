
// EXAMPLES FOR M5STACK ATOM Lite CONTROLLER
//
// BOARDMANAGER URL 
// https://dl.espressif.com/dl/package_esp32_index.json
//
// BOARD
// esp32 -> M5Stack-ATOM
//
// Upload the sketch and Press the Button for change the RGB LED
// The M5Stack library is not needed!


#include <FastLED.h>  // For Atom integrated RGB LED - https://github.com/FastLED/FastLED

// For integrated RGB LED
#define NUM_LEDS 1
#define DATA_PIN 27
CRGB leds[NUM_LEDS];

// For integrated Button
#define BUTTON_PIN 39
int lastState = HIGH; // the previous state from the input pin
int currentState = HIGH;     // the current reading from the input pin

void setup(){
  Serial.begin(115200);

  // Init integrated Button
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Init integrated Matrix LED
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

  Serial.println("Clearing Led");
  LedOff();

  Serial.println("Showing Green");
  LedGreen();

}

void loop(){

  // Read integrated Button
  currentState = digitalRead(BUTTON_PIN);  

  // If Button state change
  if (lastState != currentState){ 
    if (currentState == LOW){
      Serial.println("Button - state change to LOW");
      // Set Matrix LED
      LedRed();
    } else {
      Serial.println("Button - state change to HIGH");
      // Set Matrix LED
      LedGreen();
    }
  }

  // save the last button state
  lastState = currentState;
}

void LedOff(){
  Serial.println("Led - Off");
  leds[0] = CRGB::Black;
  FastLED.show();
}
void LedGreen(){
  Serial.println("Led - Green");
  leds[0] = CRGB::Green;
  FastLED.show(); 
}
void LedRed(){
  Serial.println("Led - Red");
  leds[0] = CRGB::Red;
  FastLED.show();
}