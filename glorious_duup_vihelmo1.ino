#define V 6
#define A 5
#define pote A0
#define pintemp A1
#define pinsensor 3

int valorpote;
int valortemp;
bool movi = false;

void setup()
{
  pinMode(V,OUTPUT);
  pinMode(A,OUTPUT);
  pinMode(pote,INPUT);
  pinMode(pintemp,INPUT);
  pinMode(pinsensor,INPUT);
}
void loop()
{
  movi = analogRead(pinsensor);
  valorpote = analogRead(pote);
  valortemp = analogRead(pintemp);
  valorpote = map(valorpote,0,1023,0,100);
  valortemp = map(((valortemp - 20) * 3.04), 0, 1023, 0, 100);
  
  if(valorpote > 50 && valortemp > 20)
  {
    if(movi == true)
    {
      analogWrite(V,255);
      analogWrite(A,255);
      delay(1000);
    }
    else
    {
      analogWrite(V,0);
      analogWrite(A,0);
      delay(1000);
    }
  }
}