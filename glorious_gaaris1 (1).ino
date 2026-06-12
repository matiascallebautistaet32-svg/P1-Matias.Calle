#include <Servo.h>

#define pulsa 2
#define sensor 4
#define pinTemp A2

Servo servoBase1;
Servo servoBase2;

int posicionActual = 45; 
int temp;                
int cel;                 

void setup() {
  pinMode(pulsa, INPUT);
  pinMode(sensor, INPUT);
  
  servoBase1.attach(A1);
  servoBase2.attach(A0);
  
  servoBase1.write(45);
  servoBase2.write(45);
}

void loop() {
  int boton = digitalRead(pulsa);

  if (boton == HIGH) {
    nomovi();
  }
  
  if (boton == LOW) {
    medirtemp();
    
    if (cel > 35) {
      tempA();
    }
    
    if (cel <= 35) {
      int movimiento = digitalRead(sensor);
      
      if (movimiento == HIGH) {
        detectamovi();
      }
      
      if (movimiento == LOW) {
        movi();
      }
    }
  }
}

void nomovi() {
  servoBase1.write(45);
  servoBase2.write(45);
  posicionActual = 45;
  delay(100);
}

void medirtemp() {
  temp = analogRead(pinTemp);
  cel = map(temp, 20, 358, -40, 125); 
}

void tempA() {
  servoBase1.write(posicionActual);
  servoBase2.write(posicionActual);
  delay(100);
}

void detectamovi() {
  servoBase1.write(0);
  servoBase2.write(0);
  posicionActual = 0;
  delay(6000); 
}

void movi() {
  servoBase1.write(90);
  servoBase2.write(90);
  posicionActual = 90;
  delay(3000);
  
  int botonMedio = digitalRead(pulsa);
  if (botonMedio == LOW) {
    servoBase1.write(180);
    servoBase2.write(180);
    posicionActual = 180;
    delay(3000);
  }
}

