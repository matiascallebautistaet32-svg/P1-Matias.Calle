#define boton 2
#define boton2 3
#define A 10
#define R 11
#include <Servo.h>
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Fb5 740
#define G5 784
#define Gb5 831
#define A5 880
#define Ab5 932
#include <Adafruit_LiquidCrystal.h>
#define temp A2
Adafruit_LiquidCrystal lcd1(0);
Servo servo1;
Servo servo2;
bool valorboton1;
bool valorboton2;
int temperatura;
int valortemperatura;
bool estaAbierta = LOW;

const int midi1[5][3] = {
 {Fb5, 273, 0},
 {G5, 273, 0},
 {Gb5, 273, 0},
 {A5, 273, 0},
 {Ab5, 273, 0},
};

void playMidi(int pin, const int notes[][3], size_t len)
{
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(boton, INPUT);
  pinMode(boton2, INPUT);
  servo1.attach(A0);
  servo1.write(80);
  servo2.attach(A1);
  servo2.write(80);
  Serial.begin(9600);
  lcd1.begin(16,2);
}

void loop()
{
  lcd1.setCursor(1,0);
  
  HaceFrio();
  mensajeLCD();
  AbrirCerrar();
  delay(1000);
}

void abrir()
{
  servo1.write(80);
  servo2.write(80);
}

void cerrar()
{
  servo1.write(0);
  servo2.write(0);
}

void AbrirCerrar()
{
  valorboton1 = digitalRead(boton);
  valorboton2 = digitalRead(boton2);
  if(valorboton1 == LOW)
  {
    abrir();
    playMidi(13, midi1, ARRAY_LEN(midi1));
  }
  if(valorboton2 == LOW)
  {
    cerrar();
  }
}

void HaceFrio()
{
  temperatura =  analogRead(temp);
  valortemperatura = map(((temperatura - 20) * 3.04), 0, 1023, -40, 125);
 if(valortemperatura < 15)
 {
   analogWrite(A, 255);
   analogWrite(R, 0);
 }
 else if(valortemperatura >= 30)
 {
   analogWrite(R, 255);
   analogWrite(A, 0);
 }
}

void mensajeLCD()
{
  if(estaAbierta)
  {
    lcd1.print("Cerrada");
  }
  else
  {
   lcd1.print("Abierta"); 
  }
}