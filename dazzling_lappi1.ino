#define R 6
#define A 5
#define V 3

void setup()
{
  pinMode(R, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(V, OUTPUT);
}

void loop()
{
  for (int x = 1;x<=255;x++)
  {
   analogWrite(R,x);
 
    for (int x = 1;x<=255;x++)
  {
 
   analogWrite(A,x);
  
      
      for (int x = 1;x<=255;x++)
  {
   
   analogWrite(V,x);
  }
}
}
}