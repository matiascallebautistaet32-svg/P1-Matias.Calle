#define R 3
#define A 2 
#define V 4 
int luz; int 
  temp; int cel; 
int valorluz; 
void setup() 
{ 
  Serial.begin(9800);
  pinMode(R,OUTPUT); 
  pinMode(A,OUTPUT); 
  pinMode(V,OUTPUT); 
} 
void loop() 
{ 
  luz = analogRead(A0); 
  temp = analogRead (A1);
  Serial.println("El nivel de luz actual es "); 
  valorluz = map(luz,0,1017,0,100);
  Serial.println(valorluz); 
  Serial.println("y la temperatura actual: "); 
  cel = map(((temp - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println(cel); delay(1000);
  if (valorluz > 30 && valorluz < 70)
  { if (cel > 90) 
  {
    analogWrite(R,255); 
    delay(1000); analogWrite(R,0); 
  } else if (cel <= 18)
  { analogWrite(A,255); 
   delay(1000); analogWrite(A,0);
  } else if (cel > 18 && cel <= 90)
  { analogWrite(V,255); 
   delay(1000);
   analogWrite(V,0); 
  } 
  } 
}



