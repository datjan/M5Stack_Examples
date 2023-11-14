
// EXAMPLES FOR M5STACK ATOM MATRIX CONTROLLER
//
// BOARDMANAGER URL 
// https://dl.espressif.com/dl/package_esp32_index.json
//
// BOARD
// esp32 -> M5Stack-ATOM
//
// LIBRARIES
// FastLED - https://github.com/FastLED/FastLED
//
// Upload the sketch and Press the Button for change the Matrix LED
// The M5Stack library is not needed!


#include <FastLED.h>  // For integrated 5x5 Matrix LED - https://github.com/FastLED/FastLED

// For integrated Matrix LED
#define NUM_LEDS 25
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
  FastLED.setBrightness(20);

  Serial.println("Clearing display");
  MatrixClear();

  Serial.println("Showing LEDs Smile");
  MatrixSmile();

}

void loop(){

  // Read integrated Button
  currentState = digitalRead(BUTTON_PIN);  

  // If Button state change
  if (lastState != currentState){ 
    if (currentState == LOW){
      Serial.println("Button - state change to LOW");
      // Set Matrix LED
      MatrixPress();
    } else {
      Serial.println("Button - state change to HIGH");
      // Set Matrix LED
      MatrixSmile();
    }
  }

  // save the last button state
  lastState = currentState;
}

void MatrixClear(){
  Serial.println("Matrix - Clearing display");
  for(int num=0; num<NUM_LEDS; num++) {
    leds[num] = CRGB::Black;
  }
  FastLED.show();
}
void MatrixSmile(){
  MatrixClear();
  Serial.println("Matrix - Smile display");
  leds[1] = CRGB::Green;
  leds[3] = CRGB::Green;
  leds[12] = CRGB::Green;
  leds[15] = CRGB::Green;
  leds[19] = CRGB::Green;
  leds[21] = CRGB::Green;
  leds[22] = CRGB::Green;
  leds[23] = CRGB::Green;
  FastLED.show(); 
}
void MatrixPress(){
  MatrixClear();
  Serial.println("Matrix - Press display");
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Red;
  leds[3] = CRGB::Red;
  leds[4] = CRGB::Red;
  leds[5] = CRGB::Red;
  leds[7] = CRGB::Blue;
  leds[9] = CRGB::Red;
  leds[11] = CRGB::Blue;
  leds[12] = CRGB::Blue;
  leds[13] = CRGB::Blue;
  leds[15] = CRGB::Red;
  leds[17] = CRGB::Blue;
  leds[19] = CRGB::Red;
  leds[20] = CRGB::Red;
  leds[21] = CRGB::Red;
  leds[23] = CRGB::Red;
  leds[24] = CRGB::Red;
  FastLED.show();
}