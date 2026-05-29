#define pinBoton  2   
#define PR  A0    
#define PA  A1    
#define PV  A2     

#define R  11     
#define A 10       
#define V  9        

int ValorRojo;
int ValorVerde;
int ValorAzul;
bool ValorBoton;

void setup() 
{
  pinMode(pinBoton, INPUT);
  pinMode(R, OUTPUT);
  pinMode(V, OUTPUT);
  pinMode(A, OUTPUT);
  Serial.begin(9800);
}

void loop()
{
  ValorBoton = digitalRead(pinBoton);
  delay(100);
  if(ValorBoton == HIGH){
    
  ValorRojo = analogRead(PR);
  ValorVerde = analogRead(PV);
  ValorAzul = analogRead(PA);
  ValorRojo =  map(ValorRojo,0 ,1023 ,0 ,255);
  ValorAzul = map(ValorAzul,0 ,1023 ,0 ,255);
  ValorVerde = map(ValorVerde,0 ,1023 ,0 ,255);
  
  Serial.println("Tiene 10 s para configurar el color del led...");
  delay(10000);
 
  Serial.print("El led esta usando esta configuracion: ");
  Serial.println();
  Serial.println(ValorRojo);
  Serial.println(ValorVerde);
  Serial.println(ValorAzul);
  PrendeApaga();

}
}
void PrendeApaga()
{
  analogWrite(R,ValorRojo);
  analogWrite(V,ValorVerde);
  analogWrite(A,ValorAzul);
  delay(10000);
  analogWrite(R,0);
  analogWrite(V,0);
  analogWrite(A,0);
}
