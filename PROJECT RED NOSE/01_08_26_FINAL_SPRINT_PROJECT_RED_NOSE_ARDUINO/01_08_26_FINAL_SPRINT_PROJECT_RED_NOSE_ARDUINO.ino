#define IR_USE_AVR_TIMER1

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

#include <IRremote.h>
#include <LiquidCrystal.h>

/*
Sprint 9: Audio and Rhythmn finalizing
*/




LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);


const int redLedPin = 13;
const int greenLedPin = 12;

const int RGB_RED_LED = 11; 
const int RGB_BLUE_LED = 10;
const int RGB_GREEN_LED = 9;

const int buzzerPin = 7;
const int irReceiverPin = 6;

int redLedState = LOW;
int greenLedState = LOW;


unsigned long lastTime = 0;



int baseTempo = 1000;
int note_index = 0;

int colorCycle = 0;

int currentSong = 0;
 

int melody1[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, 
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, 
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4,
  NOTE_D4, NOTE_G4};


int durations1[] = {
  4, 4, 2,   4, 4, 2,   4, 4, 4, 4, 1, // Jingle bells, jingle bells, jingle all the way
  4, 4, 4, 4, 4,                       // Oh what fun it is to ride
  4, 4, 4, 4, 4,                       // In a one horse open sleigh, hey!
  4, 4, 4, 4, 2                                 // (Last two notes)
};

int melody2[] = {
  NOTE_D4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4,
  NOTE_D4, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_D4, NOTE_E4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_D5};

int durations2[] = {
  4, 4, 8, 8, 4, 4, 4, 4,             // We wish you a merry Christmas
  4, 4, 8, 8, 4, 4, 4, 4,             // We wish you a merry Christmas
  4, 4, 8, 8, 4, 4, 4, 4,             // We wish you a merry Christmas
  4, 4, 4, 4, 4, 2                    // And a happy New Year!
};


int melody3[] = {
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_D5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_G4, NOTE_A4, NOTE_A4, 
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D5, 
  NOTE_D5, NOTE_F5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_E5, NOTE_C5, NOTE_G4, 
  NOTE_E4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C4};

int durations3[] = {
  2, 4, 2, 4,      // Si-lent night (4)
  2, 4, 2, 4,      // Ho-ly night (4)
  4, 4, 4, 2, 4,   // All is calm, all is bright (5)
  4, 4, 4, 2, 4,   // Round yon virgin, mother and child (5)
  4, 4, 4, 2, 4,   // Holy infant so tender and mild (5)
  4, 4, 4, 2, 4,   // Sleep in heavenly peace (5)
  4, 4, 4, 2, 4,   // Sleep in heavenly peace (5)
  2, 4, 1, 1       // End (4) -> Total 37
};

int size1 = sizeof(melody1) / sizeof(melody1[0]);
int size2 = sizeof(melody2) / sizeof(melody2[0]);
int size3 = sizeof(melody3) / sizeof(melody3[0]);


void setColor(int R, int B, int G) {
  analogWrite(RGB_RED_LED,   R);
  analogWrite(RGB_BLUE_LED,  B);
  analogWrite(RGB_GREEN_LED, G);
}

void setup() {
  lcd.begin(16, 2); // Set up the number of columns and rows on the LCD.

  Serial.begin(9600);
  IrReceiver.begin(irReceiverPin);
  
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  pinMode(RGB_RED_LED, OUTPUT);
  pinMode(RGB_GREEN_LED, OUTPUT);
  pinMode(RGB_BLUE_LED, OUTPUT);
  
  pinMode(buzzerPin, OUTPUT);
  delay(500);             // Give the hardware a moment to stabilize
  IrReceiver.begin(irReceiverPin); // Re-initialize to be sure
  IrReceiver.resume();    // Clear any "ghost" signals left in the buffer
  lcd.clear();
  lcd.print("System Ready");
  delay(1000);
  lcd.clear();
}

void loop(){
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);
  
        
    switch(IrReceiver.decodedIRData.decodedRawData) {
      case 0xF30CFF00:

        if (currentSong == 1) {
        currentSong = 0;
        }
        else {
          lcd.clear();
          lcd.print("Jingle Bells");          
          startSong(1);

        }

      delay(50);
       break;
    
      case 0xE718FF00:

        if (currentSong == 2) {
        currentSong = 0;
        }
        else {

          lcd.clear();
          lcd.print("We Wish You");
          startSong(2);
        }
        delay(50);
        break;

      case 0xA15EFF00:
        if (currentSong == 3) {
        currentSong = 0;
        }
        else {
          lcd.clear();
          lcd.print("Silent Night");           
          startSong(3);

        }
        delay(50);
        break;
    
      default:
        currentSong = 0;
        break;
    }
    IrReceiver.resume();
  }
  
  switch (currentSong) {
    case 1:
      songPlayer(melody1, durations1, size1);
      break;
    case 2:
      songPlayer(melody2, durations2, size2);    
      break;
    case 3:
      songPlayer(melody3, durations3, size3);
      break;
    default: 
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, LOW);
      setColor(0, 0, 0);
      noTone(buzzerPin);
      lcd.clear();
      break;
    }
}

  

void startSong(int songNumber) {
  currentSong = songNumber;
  note_index = 0;
  lastTime = millis();

}

void songPlayer(int melody[], int durations[], int size) {
  unsigned long time = millis();
  

  int interval = baseTempo / (durations[note_index]);
  int sound_interval = interval * 0.8;  
  
  if (time - lastTime >= interval) {
      lastTime = time; 
      note_index++;
    colorCycle++;
      if (note_index >= size) {
        note_index = 0; 
        
      }
      lcd.setCursor(0, 1);
      lcd.print("Note: ");
      lcd.print(note_index);
      lcd.print("   ");
    }
  
  int r = (colorCycle % 3 == 0) ? 255 : 0; 
  int g = (colorCycle % 3 == 1) ? 255 : 0;
  int b = (colorCycle % 3 == 2) ? 255 : 0;
    

  

  
 
    if (time - lastTime <= sound_interval) {
      redLedState = HIGH;
      greenLedState = LOW;
      setColor(r, b, g);
      digitalWrite(redLedPin, redLedState);
      digitalWrite(greenLedPin, greenLedState);
      tone(buzzerPin, melody[note_index]);
      
    }
  
    else {
      redLedState = LOW;
      greenLedState = HIGH;
      setColor(0, 0, 0);
      digitalWrite(redLedPin, redLedState);
      digitalWrite(greenLedPin, greenLedState);
      noTone(buzzerPin);
    
    }
}
