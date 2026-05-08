#define pinbuzz 6
#define pinmovi 2
#define V 4
#define R 8
bool movi = false;

void setup()
{
  pinMode(pinbuzz,OUTPUT);
  pinMode(V,OUTPUT);
  pinMode(R,OUTPUT);
 
}

void loop()
{
  
  movi = digitalRead(pinmovi);
  
  if(movi == true)
  {
    digitalWrite(R,HIGH);
    digitalWrite(V,LOW);   
    delay(100);  
    tone(pinbuzz, 1000); 
  } 
  else 
  {
    digitalWrite(V,HIGH);   
    digitalWrite(R,LOW);
    delay(10);
    noTone(pinbuzz);             
  }
}
