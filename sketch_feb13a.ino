#include <FastLED.h>

//predni
#define LED_PIN_1 5
#define NUM_LEDS_1 90

//zadni
#define LED_PIN_2 6
#define NUM_LEDS_2 90

//kufr
#define LED_PIN_3 11
#define NUM_LEDS_3 70

//přední blatník + info HUD
#define LED_PIN_4 9
#define NUM_LEDS_4 41

//zadní blatník
#define LED_PIN_5 10
#define NUM_LEDS_5 30

CRGB leds_1[NUM_LEDS_1];
CRGB leds_2[NUM_LEDS_2];
CRGB leds_3[NUM_LEDS_3];
CRGB leds_4[NUM_LEDS_4];
CRGB leds_5[NUM_LEDS_5];

int brightness = 255;
const int btn1 = 7;
const int btn2 = 8;
const int btn3 = 4;

const int buzzer = 3;

const float br = 0.5;
const float br2 = 1;

const CRGB RGBsvetla_zadni(255 * br, 0 * br, 0 * br);
const CRGB RGBsvetla_predni(255 * br, 255 * br, 255 * br);
const CRGB RGBsvetla_blinkr(255 * 1, 100 * 1, 0 * 1);

void setup() {
  FastLED.addLeds<WS2812, LED_PIN_1, GRB>(leds_1, NUM_LEDS_1);
  FastLED.addLeds<WS2812, LED_PIN_2, GRB>(leds_2, NUM_LEDS_2);
  FastLED.addLeds<WS2812, LED_PIN_3, GRB>(leds_3, NUM_LEDS_3);
  FastLED.addLeds<WS2812, LED_PIN_4, GRB>(leds_4, NUM_LEDS_4);
  FastLED.addLeds<WS2812, LED_PIN_5, GRB>(leds_5, NUM_LEDS_5);
  FastLED.setBrightness(brightness);
  fill_solid(leds_1, NUM_LEDS_1, CRGB::Black);
  fill_solid(leds_2, NUM_LEDS_2, CRGB::Black);
  fill_solid(leds_3, NUM_LEDS_3, CRGB::Black);
  fill_solid(leds_4, NUM_LEDS_4, CRGB::Black);
  fill_solid(leds_5, NUM_LEDS_5, CRGB::Black);


  FastLED.show();
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  zapinaci_animace();
}

void loop() {

  if (digitalRead(btn3) == 1) {
    //mod 1
    for (int a = 0; a < 5; a++) {
      for (int i = 0; i <= 3; i++) {
        if (digitalRead(btn3) == 0) {
          a = 9999;
          i = 9999;
        }

        fill_solid(leds_1, NUM_LEDS_1 / 4, CRGB(255 * br2, 0, 0));
        fill_solid(leds_1 + NUM_LEDS_1 / 2, NUM_LEDS_1 / 4, CRGB(255 * br2, 0, 0));

        fill_solid(leds_2, NUM_LEDS_2 / 4, CRGB(255 * br2, 0, 0));
        fill_solid(leds_2 + NUM_LEDS_2 / 2, NUM_LEDS_2 / 4, CRGB(255 * br2, 0, 0));

        fill_solid(leds_3, (NUM_LEDS_3 / 2) - 5, CRGB(255 * br2, 0, 0));
        fill_solid(leds_3 + (NUM_LEDS_3 / 2) - 5, 10, CRGB(255 * br2, 255 * br2, 255 * br2));

        fill_solid(leds_4, 26, CRGB(255 * br2, 0, 0));

        fill_solid(leds_5, 30, CRGB(255 * br2, 0, 0));
        FastLED.show();
        delay(30);
        fill_solid(leds_1, NUM_LEDS_1, CRGB::Black);

        fill_solid(leds_2, NUM_LEDS_2, CRGB::Black);

        fill_solid(leds_3, NUM_LEDS_3, CRGB::Black);

        fill_solid(leds_4, 26, CRGB::Black);

        fill_solid(leds_5, 30, CRGB::Black);
        FastLED.show();
        delay(30);
      }
      delay(50);
      for (int i = 0; i <= 3; i++) {
        if (digitalRead(btn3) == 0) {
          a = 9999;
          i = 9999;
        }

        fill_solid(leds_1 + NUM_LEDS_1 / 4, NUM_LEDS_1 / 4, CRGB(0, 0, 255 * br2));
        fill_solid(leds_1 + (NUM_LEDS_1 / 2 + NUM_LEDS_1 / 4), NUM_LEDS_1 / 4, CRGB(0, 0, 255 * br2));

        fill_solid(leds_2 + NUM_LEDS_2 / 4, NUM_LEDS_2 / 4, CRGB(0, 0, 255 * br2));
        fill_solid(leds_2 + (NUM_LEDS_2 / 2 + NUM_LEDS_2 / 4), NUM_LEDS_2 / 4, CRGB(0, 0, 255 * br2));

        fill_solid(leds_3 + (NUM_LEDS_3 / 2) + 5, (NUM_LEDS_3 / 2) - 5, CRGB(0, 0, 255 * br2));
        fill_solid(leds_3 + (NUM_LEDS_3 / 2) - 5, 10, CRGB(255 * br2, 255 * br2, 255 * br2));

        fill_solid(leds_4, 26, CRGB(0, 0, 255 * br2));

        fill_solid(leds_5, 30, CRGB(0, 0, 255 * br2));
        FastLED.show();
        delay(30);
        fill_solid(leds_1, NUM_LEDS_1, CRGB::Black);

        fill_solid(leds_2, NUM_LEDS_2, CRGB::Black);

        fill_solid(leds_3, NUM_LEDS_3, CRGB::Black);

        fill_solid(leds_4, 26, CRGB::Black);

        fill_solid(leds_5, 30, CRGB::Black);
        FastLED.show();
        delay(30);
      }
    }

    //bila zmena
    for (int i = 0; i <= 3; i++) {
      if (digitalRead(btn3) == 0) {
          i = 9999;
        }

      fill_solid(leds_1, NUM_LEDS_1, CRGB(255 * br2, 255 * br2, 255 * br2));

      fill_solid(leds_2, NUM_LEDS_2, CRGB(255 * br2, 255 * br2, 255 * br2));

      fill_solid(leds_3 + (NUM_LEDS_3 / 2) - 5, 10, CRGB(255 * br2, 255 * br2, 255 * br2));
      FastLED.show();
      delay(30);
      fill_solid(leds_1, NUM_LEDS_1, CRGB::Black);

      fill_solid(leds_2, NUM_LEDS_2, CRGB::Black);

      fill_solid(leds_3, NUM_LEDS_3, CRGB::Black);
      FastLED.show();
      delay(30);
    }
  } else {

    //varovn blinkr
    if (digitalRead(btn1) == 0 && digitalRead(btn2) == 0) {
      tone(buzzer, 600);
      fill_solid(leds_3, 90, RGBsvetla_zadni);
      for (int i = 0; i <= 21; i++) {
        leds_1[22] = RGBsvetla_blinkr;
        leds_1[21 - i] = RGBsvetla_blinkr;
        leds_1[23 + i] = RGBsvetla_blinkr;
        leds_2[22] = RGBsvetla_blinkr;
        leds_2[21 - i] = RGBsvetla_blinkr;
        leds_2[23 + i] = RGBsvetla_blinkr;

        leds_1[45 + 22] = RGBsvetla_blinkr;
        leds_1[45 + 21 - i] = RGBsvetla_blinkr;
        leds_1[45 + 23 + i] = RGBsvetla_blinkr;
        leds_2[45 + 22] = RGBsvetla_blinkr;
        leds_2[45 + 21 - i] = RGBsvetla_blinkr;
        leds_2[45 + 23 + i] = RGBsvetla_blinkr;

        if (i <= 9) {
          if (i % 2 == 0) {
            leds_4[30 - (i / 2)] = RGBsvetla_blinkr;
            leds_4[36 + (i / 2)] = RGBsvetla_blinkr;
          }
        }
        FastLED.show();
        delay(20);
      }
      delay(25);
      noTone(buzzer);
      for (int i = 0; i <= 21; i++) {
        leds_1[22] = CRGB(0, 0, 0);
        leds_1[21 - i] = CRGB(0, 0, 0);
        leds_1[23 + i] = CRGB(0, 0, 0);
        leds_1[45 + 22] = CRGB(0, 0, 0);
        leds_1[45 + 21 - i] = CRGB(0, 0, 0);
        leds_1[45 + 23 + i] = CRGB(0, 0, 0);
        leds_2[22] = CRGB(0, 0, 0);
        leds_2[21 - i] = CRGB(0, 0, 0);
        leds_2[23 + i] = CRGB(0, 0, 0);
        leds_2[45 + 22] = CRGB(0, 0, 0);
        leds_2[45 + 21 - i] = CRGB(0, 0, 0);
        leds_2[45 + 23 + i] = CRGB(0, 0, 0);

        if (i <= 9) {
          if (i % 2 == 0) {
            leds_4[30 - (i / 2)] = CRGB(0, 0, 0);
            leds_4[36 + (i / 2)] = CRGB(0, 0, 0);
          }
        }
        FastLED.show();
        delay(15);
      }
      delay(100);

    }
    //levy blinkr
    else if (digitalRead(btn1) == 0) {
      tone(buzzer, 1000);
      for (int i = 0; i <= 21; i++) {
        if (digitalRead(btn2) == 1) {
          leds_1[22] = RGBsvetla_blinkr;
          leds_1[21 - i] = RGBsvetla_blinkr;
          leds_1[23 + i] = RGBsvetla_blinkr;
          leds_2[22] = RGBsvetla_blinkr;
          leds_2[21 - i] = RGBsvetla_blinkr;
          leds_2[23 + i] = RGBsvetla_blinkr;

          if (i <= 9) {
            if (i % 2 == 0) {
              leds_4[30 - (i / 2)] = RGBsvetla_blinkr;
            }
          }

          if (digitalRead(btn3) == 0) {
            leds_1[45 + 22] = RGBsvetla_predni;
            leds_1[45 + 21 - i] = RGBsvetla_predni;
            leds_1[45 + 23 + i] = RGBsvetla_predni;
            leds_2[45 + 22] = RGBsvetla_zadni;
            leds_2[45 + 21 - i] = RGBsvetla_zadni;
            leds_2[45 + 23 + i] = RGBsvetla_zadni;
            fill_solid(leds_3, 90, RGBsvetla_zadni);
            leds_4[33] = CRGB(0, 255, 0);
          }
          FastLED.show();
          delay(20);
        } else {
          fill_solid(leds_1, 45, CRGB::Black);
          fill_solid(leds_2, 45, CRGB::Black);
          fill_solid(leds_3, 90, CRGB::Black);
          leds_4[33] = CRGB(0, 0, 0);
          FastLED.show();
        }
      }
      delay(25);
      noTone(buzzer);
      for (int i = 0; i <= 21; i++) {
        if (digitalRead(btn2) == 1) {
          leds_1[22] = CRGB(0, 0, 0);
          leds_1[21 - i] = CRGB(0, 0, 0);
          leds_1[23 + i] = CRGB(0, 0, 0);
          leds_2[22] = CRGB(0, 0, 0);
          leds_2[21 - i] = CRGB(0, 0, 0);
          leds_2[23 + i] = CRGB(0, 0, 0);

          if (i <= 9) {
            if (i % 2 == 0) {
              leds_4[30 - (i / 2)] = CRGB(0, 0, 0);
            }
          }
          fill_solid(leds_3, 90, RGBsvetla_zadni);
          FastLED.show();
          delay(15);
        } else {
          fill_solid(leds_1, 45, CRGB::Black);
          fill_solid(leds_2, 45, CRGB::Black);
          fill_solid(leds_3, 90, CRGB::Black);
          leds_4[33] = CRGB(0, 0, 0);
          FastLED.show();
        }
      }
      delay(100);
    }

    //pravý blinkr
    else if (digitalRead(btn2) == 0) {
      tone(buzzer, 1000);
      for (int i = 0; i <= 21; i++) {
        if (digitalRead(btn1) == 1) {
          leds_1[45 + 22] = RGBsvetla_blinkr;
          leds_1[45 + 21 - i] = RGBsvetla_blinkr;
          leds_1[45 + 23 + i] = RGBsvetla_blinkr;
          leds_2[45 + 22] = RGBsvetla_blinkr;
          leds_2[45 + 21 - i] = RGBsvetla_blinkr;
          leds_2[45 + 23 + i] = RGBsvetla_blinkr;

          if (i <= 9) {
            if (i % 2 == 0) {
              leds_4[36 + (i / 2)] = RGBsvetla_blinkr;
            }
          }

          if (digitalRead(btn3) == 0) {
            leds_1[22] = RGBsvetla_predni;
            leds_1[21 - i] = RGBsvetla_predni;
            leds_1[23 + i] = RGBsvetla_predni;
            leds_2[22] = RGBsvetla_zadni;
            leds_2[21 - i] = RGBsvetla_zadni;
            leds_2[23 + i] = RGBsvetla_zadni;
            fill_solid(leds_3, 90, RGBsvetla_zadni);
            leds_4[33] = CRGB(0, 255, 0);
          }
          FastLED.show();
          delay(20);
        } else {
          fill_solid(leds_1 + 45, 45, CRGB::Black);
          fill_solid(leds_2 + 45, 45, CRGB::Black);
          fill_solid(leds_3, 90, CRGB::Black);
          leds_4[33] = CRGB(0, 0, 0);
          FastLED.show();
        }
      }
      delay(25);
      noTone(buzzer);
      for (int i = 0; i <= 21; i++) {
        if (digitalRead(btn1) == 1) {
          leds_1[45 + 22] = CRGB(0, 0, 0);
          leds_1[45 + 21 - i] = CRGB(0, 0, 0);
          leds_1[45 + 23 + i] = CRGB(0, 0, 0);
          leds_2[45 + 22] = CRGB(0, 0, 0);
          leds_2[45 + 21 - i] = CRGB(0, 0, 0);
          leds_2[45 + 23 + i] = CRGB(0, 0, 0);

          if (i <= 9) {
            if (i % 2 == 0) {
              leds_4[36 + (i / 2)] = CRGB(0, 0, 0);
            }
          }

          fill_solid(leds_3, 90, RGBsvetla_zadni);
          FastLED.show();
          delay(15);
        } else {
          fill_solid(leds_1 + 45, 45, CRGB::Black);
          fill_solid(leds_2 + 45, 45, CRGB::Black);
          fill_solid(leds_3, 90, CRGB::Black);
          leds_4[33] = CRGB(0, 0, 0);
          FastLED.show();
        }
      }
      delay(100);
    }

    //červené svetla
    else if (digitalRead(btn3) == 0) {
      for (int i = 0; i <= 21; i++) {
        if (digitalRead(btn1) == 1 && digitalRead(btn2) == 1 && digitalRead(btn3) == 0) {
          leds_1[22] = RGBsvetla_predni;
          leds_1[21 - i] = RGBsvetla_predni;
          leds_1[23 + i] = RGBsvetla_predni;
          leds_2[22] = RGBsvetla_zadni;
          leds_2[21 - i] = RGBsvetla_zadni;
          leds_2[23 + i] = RGBsvetla_zadni;

          leds_1[45 + 22] = RGBsvetla_predni;
          leds_1[45 + 21 - i] = RGBsvetla_predni;
          leds_1[45 + 23 + i] = RGBsvetla_predni;
          leds_2[45 + 22] = RGBsvetla_zadni;
          leds_2[45 + 21 - i] = RGBsvetla_zadni;
          leds_2[45 + 23 + i] = RGBsvetla_zadni;
          fill_solid(leds_3, 90, RGBsvetla_zadni);
          leds_4[33] = CRGB(0, 255, 0);
          FastLED.show();

          delay(30);
        }
      }
    } else {
      fill_solid(leds_1, 90, CRGB::Black);
      fill_solid(leds_2, 90, CRGB::Black);
      fill_solid(leds_3, 90, CRGB::Black);
      leds_4[33] = CRGB(0, 0, 0);
      FastLED.show();
    }
  }
}





void zapinaci_animace() {
  //uvod blinkry:
  for (int i = 0; i <= 21; i++) {
    leds_1[22] = RGBsvetla_blinkr;
    leds_1[21 - i] = RGBsvetla_blinkr;
    leds_1[23 + i] = RGBsvetla_blinkr;
    leds_2[22] = RGBsvetla_blinkr;
    leds_2[21 - i] = RGBsvetla_blinkr;
    leds_2[23 + i] = RGBsvetla_blinkr;


    leds_1[45 + 22] = RGBsvetla_blinkr;
    leds_1[45 + 21 - i] = RGBsvetla_blinkr;
    leds_1[45 + 23 + i] = RGBsvetla_blinkr;
    leds_2[45 + 22] = RGBsvetla_blinkr;
    leds_2[45 + 21 - i] = RGBsvetla_blinkr;
    leds_2[45 + 23 + i] = RGBsvetla_blinkr;

    if (i <= 9) {
      if (i % 2 == 0) {
        leds_4[30 - (i / 2)] = RGBsvetla_blinkr;
        leds_4[36 + (i / 2)] = RGBsvetla_blinkr;
      }
    }
    FastLED.show();
    delay(5);
  }
  delay(20);
  for (int i = 0; i <= 21; i++) {
    leds_1[22] = CRGB(0, 0, 0);
    leds_1[21 - i] = CRGB(0, 0, 0);
    leds_1[23 + i] = CRGB(0, 0, 0);
    leds_1[45 + 22] = CRGB(0, 0, 0);
    leds_1[45 + 21 - i] = CRGB(0, 0, 0);
    leds_1[45 + 23 + i] = CRGB(0, 0, 0);
    leds_2[22] = CRGB(0, 0, 0);
    leds_2[21 - i] = CRGB(0, 0, 0);
    leds_2[23 + i] = CRGB(0, 0, 0);
    leds_2[45 + 22] = CRGB(0, 0, 0);
    leds_2[45 + 21 - i] = CRGB(0, 0, 0);
    leds_2[45 + 23 + i] = CRGB(0, 0, 0);

    if (i <= 9) {
      if (i % 2 == 0) {
        leds_4[30 - (i / 2)] = CRGB(0, 0, 0);
        leds_4[36 + (i / 2)] = CRGB(0, 0, 0);
      }
    }
    FastLED.show();
    delay(5);
  }
  delay(50);
  for (int i = 0; i <= 21; i++) {
    leds_1[22] = RGBsvetla_blinkr;
    leds_1[21 - i] = RGBsvetla_blinkr;
    leds_1[23 + i] = RGBsvetla_blinkr;
    leds_2[22] = RGBsvetla_blinkr;
    leds_2[21 - i] = RGBsvetla_blinkr;
    leds_2[23 + i] = RGBsvetla_blinkr;


    leds_1[45 + 22] = RGBsvetla_blinkr;
    leds_1[45 + 21 - i] = RGBsvetla_blinkr;
    leds_1[45 + 23 + i] = RGBsvetla_blinkr;
    leds_2[45 + 22] = RGBsvetla_blinkr;
    leds_2[45 + 21 - i] = RGBsvetla_blinkr;
    leds_2[45 + 23 + i] = RGBsvetla_blinkr;

    if (i <= 9) {
      if (i % 2 == 0) {
        leds_4[30 - (i / 2)] = RGBsvetla_blinkr;
        leds_4[36 + (i / 2)] = RGBsvetla_blinkr;
      }
    }
    FastLED.show();
    delay(5);
  }
  delay(20);
  for (int i = 0; i <= 21; i++) {
    leds_1[22] = CRGB(0, 0, 0);
    leds_1[21 - i] = CRGB(0, 0, 0);
    leds_1[23 + i] = CRGB(0, 0, 0);
    leds_1[45 + 22] = CRGB(0, 0, 0);
    leds_1[45 + 21 - i] = CRGB(0, 0, 0);
    leds_1[45 + 23 + i] = CRGB(0, 0, 0);
    leds_2[22] = CRGB(0, 0, 0);
    leds_2[21 - i] = CRGB(0, 0, 0);
    leds_2[23 + i] = CRGB(0, 0, 0);
    leds_2[45 + 22] = CRGB(0, 0, 0);
    leds_2[45 + 21 - i] = CRGB(0, 0, 0);
    leds_2[45 + 23 + i] = CRGB(0, 0, 0);

    if (i <= 9) {
      if (i % 2 == 0) {
        leds_4[30 - (i / 2)] = CRGB(0, 0, 0);
        leds_4[36 + (i / 2)] = CRGB(0, 0, 0);
      }
    }
    FastLED.show();
    delay(5);
  }
  for (int i = 0; i <= 21; i++) {
    leds_1[22] = RGBsvetla_predni;
    leds_1[21 - i] = RGBsvetla_predni;
    leds_1[23 + i] = RGBsvetla_predni;
    leds_2[22] = RGBsvetla_zadni;
    leds_2[21 - i] = RGBsvetla_zadni;
    leds_2[23 + i] = RGBsvetla_zadni;

    leds_1[45 + 22] = RGBsvetla_predni;
    leds_1[45 + 21 - i] = RGBsvetla_predni;
    leds_1[45 + 23 + i] = RGBsvetla_predni;
    leds_2[45 + 22] = RGBsvetla_zadni;
    leds_2[45 + 21 - i] = RGBsvetla_zadni;
    leds_2[45 + 23 + i] = RGBsvetla_zadni;
    fill_solid(leds_3, 90, RGBsvetla_zadni);
    FastLED.show();

    delay(30);
  }
  for (int i = 21; i >= 0; i--) {
    // leds_1[22] = CRGB(0, 0, 0);
    leds_1[21 - i] = CRGB(0, 0, 0);
    leds_1[23 + i] = CRGB(0, 0, 0);
    leds_2[21 - i] = CRGB(0, 0, 0);
    leds_2[23 + i] = CRGB(0, 0, 0);

    // leds_1[45 + 22] = CRGB(0, 0, 0);
    leds_1[45 + 21 - i] = CRGB(0, 0, 0);
    leds_1[45 + 23 + i] = CRGB(0, 0, 0);
    // leds_2[45 + 22] = CRGB(0, 0, 0);
    leds_2[45 + 21 - i] = CRGB(0, 0, 0);
    leds_2[45 + 23 + i] = CRGB(0, 0, 0);
    fill_solid(leds_3, 90, CRGB(0, 0, 0));
    FastLED.show();

    delay(30);
  }
}
