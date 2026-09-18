#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Gb3 208
#define C4 262
#define F3 175
#define A3 220

const int midi1[10][3] = {
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 115},
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 0},
};

#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>
#define pinRojo 2
#define pinVerde 4
#define pinAzul 7
#define pinBuzzer 11
#define pinPote A0
#define pinTemp A3
#define pinServo1 A1
#define boton1 5

Servo servo1;


Adafruit_LiquidCrystal lcd1(0);

int valorTemp;
int valorPote;

void setup()
{
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
    
 servo1.attach(pinServo1);
 servo1.write(0);

  
lcd1.begin(16,2); 
}
   
void loop()
{
  veces10();
  comprobarTemp();
}
 
  
 void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}
  
void veces10()
{
  valorPote = analogRead(pinPote);
  valorPote = map(valorPote,0,1023,0,100);
  
  if(boton1 == LOW)
  {
  lcd1.print("Servo moviendose");
  for(int x = 0; x < 10; x++)
  {
    
    if(valorPote < 25);
    {
      servo1.write(90);
      delay(2000);
      servo1.write(0);
     
    }
    if(valorPote >= 25 && valorPote <= 50)
    {
      servo1.write(90);
      delay(5000);
      servo1.write(0);

    }
    if(valorPote > 50)
    {
      servo1.write(90);
      delay(8000);
      servo1.write(0);
    }
  }
  }

  void playMidi(int pin, const int notes[][3], size_t len);
  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, LOW);
  lcd1.print("Melodia");
}

void comprobarTemp()
{
  valorTemp = analogRead(pinTemp);
  valorTemp = map(((valorTemp - 20)*3.04),0,1023,-40,125);
  
  if(valorTemp > 40)
  {
   digitalWrite(pinRojo, HIGH);
   digitalWrite(pinVerde, LOW);
   digitalWrite(pinAzul, LOW);
  }
  else
  {
   digitalWrite(pinRojo, LOW);
   digitalWrite(pinVerde, LOW);
   digitalWrite(pinAzul, HIGH);
  }
}


  