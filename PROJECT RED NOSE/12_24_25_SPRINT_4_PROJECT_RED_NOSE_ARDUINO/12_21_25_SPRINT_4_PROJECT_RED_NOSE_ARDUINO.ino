#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0



/*
Step 4: Multi-Song Management (Structural Foundation)
Now you add the other buttons.

Goal: 3 Buttons. Each button sets its own "Playing" variable to true and sets the others to false.

Key Learning: This is where you implement stopAllPlayback(). When Button B is pressed, it must reset the noteIndex and lastTime for Song A so it doesn't start in the middle of a note later.

*/
//what was the mistake or misconcpetion I made step 2 or 3? Look at gemini logs
const int button1Pin = A0;
const int button2Pin = A1;
const int button3Pin = A2;






const int ledPin = 13;
const int buzzerPin = 7;

int button1State = LOW;
int button2State = LOW;
int button3State = LOW;

int ledState = LOW;
int previousButton1State = LOW;
int previousButton2State = LOW;
int previousButton3State = LOW;

unsigned long lastTime = 0;

int interval = 250;
int sound_interval = 150;
int note_index = 0; 

int currentSong = 0; //enum in the future?
 


bool playing1 = false;
bool playing2 = false;
bool playing3 = false;

int melody1[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, 
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, 
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4,
  NOTE_D4, NOTE_G4};

int melody2[] = {
  NOTE_D4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4,
  NOTE_D4, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_D4, NOTE_E4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_D5};

int melody3[] = {
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_D5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_G4, NOTE_A4, NOTE_A4, 
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D5, 
  NOTE_D5, NOTE_F5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_E5, NOTE_C5, NOTE_G4, 
  NOTE_E4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C4};


int size1 = sizeof(melody1) / sizeof(melody1[0]);
int size2 = sizeof(melody2) / sizeof(melody2[0]);
int size3 = sizeof(melody3) / sizeof(melody3[0]);

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop(){
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  
  
  
  unsigned long time = millis();
  
  if (button1State == HIGH && previousButton1State == LOW) {
    if (currentSong == 1) {
      currentSong = 0;
    }
    else {
    startSong(1);
    }
    delay(50);
  }
  

  if (button2State == HIGH && previousButton2State == LOW) {
    if (currentSong == 2) {
      currentSong = 0;
    }
    else {
    startSong(2);
    }
    delay(50);  
  }
  
  if (button3State == HIGH && previousButton3State == LOW) {
    if (currentSong == 3) {
      currentSong = 0;
    }
    else {
    startSong(3);
    }
    delay(50);  
  }
  
  
  
  if (currentSong == 1) {
    if (time - lastTime >= interval) {
      lastTime = time; 
      note_index++;
      if (note_index >= size1) {
        note_index = 0; 
        
      }
      
    }
    
    if (time - lastTime <= sound_interval) {

      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      tone(buzzerPin, melody1[note_index]);
      
    }
    
    else {
      ledState = LOW;
      digitalWrite(ledPin, ledState);
      noTone(buzzerPin);
    
    }
  
  }
  

    
  
//----------------------------------------------------------next one ------

  else if (currentSong == 2) {
    
    if (time - lastTime >= interval) {
      lastTime = time; 
      note_index++;
      if (note_index >= size2) {
        note_index = 0;      
      }
    }
    
    if (time - lastTime <= sound_interval) {

      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      tone(buzzerPin, melody2[note_index]);
      
    }
    
    else {
      ledState = LOW;
      digitalWrite(ledPin, ledState);
      noTone(buzzerPin);
    }
    
  }

  
//-----------------------------------------------------------------

  else if (currentSong == 3) {
    
    
    
    if (time - lastTime >= interval) {
      lastTime = time; 
      note_index++;
      if (note_index >= size3) {
        note_index = 0;      
      }
    }
    
    if (time - lastTime <= sound_interval) {

      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      tone(buzzerPin, melody3[note_index]);
      
    }
    
    else {
      ledState = LOW;
      digitalWrite(ledPin, ledState);
      noTone(buzzerPin);
    }
    
  }
   
  

  
  else {
    noTone(buzzerPin);
    ledState = LOW;
    digitalWrite(ledPin, ledState);
  
  }
  
  previousButton1State = button1State;
  previousButton2State = button2State;
  previousButton3State = button3State;  
}
  

void startSong(int songNumber) {
  currentSong = songNumber;
  note_index = 0;
  lastTime = millis();

}
