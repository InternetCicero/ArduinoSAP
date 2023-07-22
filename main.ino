#define LED_PIN_1 2
#define LED_PIN_2 3
#define LED_PIN_3 4
#define LED_PIN_4 5

#define LED_NUMBER 4

int pause = 100;

long stopAt = -1;

byte LEDPinArray[LED_NUMBER] = { LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4 };

void setup() {
  Serial.begin(9600);
   for (int i = 0; i < LED_NUMBER; i++) {
    pinMode(LEDPinArray[i], OUTPUT);
  }
}

bool stopAtCase(int i) {
  if(stopAt != -1 && i == stopAt) {
      digitalWrite(LEDPinArray[stopAt], HIGH);
      return true;
  } else {
    return false;
  }
}

void runForward() {
  for (int i = 0; i < LED_NUMBER; i++) {
    bool stop = stopAtCase(i);
    if(stop == false) {
      digitalWrite(LEDPinArray[i], HIGH);
      delay(pause);
      digitalWrite(LEDPinArray[i], LOW);
    } else {
      return;
    }
  }
}

void runBackward() {
  for (int i = LED_NUMBER-1; i >= 0; i--) {
    bool stop = stopAtCase(i);
    if(stop == false) {
      digitalWrite(LEDPinArray[i], HIGH);
      delay(pause);
      digitalWrite(LEDPinArray[i], LOW);
    } else {
      return;
    }
  }
}

void loop() {
    for(int i = 0; i < 5; i++) {
    if(i == 4) {
      randomSeed(analogRead(A0));
      stopAt = random(LED_NUMBER);
      Serial.print(stopAt);
      runForward();
      delay(5000);
      digitalWrite(LEDPinArray[stopAt], LOW);
      exit(0);
    }
  }
}
