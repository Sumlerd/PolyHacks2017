#include <Adafruit_NeoPixel.h>
int ledpin = 2;
#define PIN 6
// small led 73
// large led 116
int ledLenght = 73;
int timeLen = 100;

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(ledLenght, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  //pinMode(ledpin,OUTPUT);
}

void loop() {
  String state = Serial.readString();
  float input[5];
  input[0]=state.substring(0,4).toFloat();
  input[1]=state.substring(5,9).toFloat();
  input[2]=state.substring(10,14).toFloat();
  
float greatest = 0.0;
int larg=10;

int rInt = (int) 255*input[0];
int gInt = (int) 255*input[1];
int bInt = (int) 255*input[2];

  theaterChase(strip.Color(  rInt, gInt, bInt), timeLen); //red
  delay(500);
     
}


//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}



