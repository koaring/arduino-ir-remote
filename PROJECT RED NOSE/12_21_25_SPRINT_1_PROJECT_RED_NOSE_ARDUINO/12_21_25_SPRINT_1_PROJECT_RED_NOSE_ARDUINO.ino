

/*

The "Sprint 1" Setup:

Put one LED and one Button in Tinkercad.

Try to write this specific logic:

If the button is pressed, the LED should start blinking (500ms ON, 500ms OFF).

If the button is pressed again, the LED must turn OFF instantly.


*/


const int ledPin = 13;
const int buttonPin = A0;

unsigned long lastTime = 0;
int ledState = LOW;

bool playing = false;
int lastButton = LOW;


long interval = 500;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  
  int buttonState = digitalRead(buttonPin);
  unsigned long currentTime = millis();
  
  if (buttonState == HIGH && lastButton == LOW) {
    playing = !playing;
    delay(50);
  }
  
  lastButton = buttonState;
  
  if (playing) {
    if (currentTime - lastTime >= interval) {
      lastTime = currentTime;
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      }
  }
  else {
    ledState = LOW;
    digitalWrite(ledPin, ledState);
  } 
}
