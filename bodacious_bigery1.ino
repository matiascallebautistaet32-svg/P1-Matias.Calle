#include <Servo.h>

#define boton1 2
#define boton2 4


Servo servoBase1;
Servo servoBase2;
bool movimiento1;
bool movimiento2;
int rotacion;


void setup()
{
   pinMode(boton1,INPUT);
   pinMode(boton2,INPUT);
   servoBase1.attach(A1);
   servoBase1.write(0);
   servoBase2.attach(A0);
   servoBase2.write(0);
}

void loop() 
{
  movimiento1 = digitalRead(boton1);
  movimiento2 = digitalRead(boton2);

	if(movimiento1 == LOW)
    {
      avanzar();
    }
  else if(movimiento2 == LOW)
  {
      retroceder();
  } 
  
}
void avanzar()
{
   rotacion = rotacion + 10;
   servoBase1.write(rotacion);
   servoBase2.write(rotacion);
   delay(1000);
  if(rotacion > 180)
  {
   rotacion = rotacion - 10;
  }
}
void retroceder()
{
   rotacion = rotacion - 10;
   servoBase1.write(rotacion);
   servoBase2.write(rotacion);
   delay(1000);
   if(rotacion < 0)
  {
   rotacion = rotacion + 10;
  }
}