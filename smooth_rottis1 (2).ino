// C++ code
//
void setup()
{
  pinMode(6, OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3,OUTPUT);

}

void loop()
{
delay(1000);
analogWrite(10,255);
delay(1000);  
analogWrite(10,0);
  
for (int x = 1;x <= 4; x++){
    analogWrite(10,255);
    analogWrite(6,40);
    analogWrite(11,40);
	digitalWrite(12,HIGH);
	analogWrite(3,40);
    analogWrite(9,255);
    
    delay(100);
    
    analogWrite(10,0);
    analogWrite(6,0);
    analogWrite(11,0);
    digitalWrite(12,LOW);
    analogWrite(3,0);
    analogWrite(9,0); 
    delay(100);
  }
    digitalWrite(12,HIGH);
    digitalWrite(7,HIGH);
    delay(1000);    
    digitalWrite(12,LOW);
    digitalWrite(7,LOW);
 
 for (int x = 1;x <= 4; x++){
    analogWrite(10,255);
    analogWrite(6,40);
    analogWrite(11,40);
	digitalWrite(12,HIGH);
	analogWrite(3,40);
    analogWrite(9,255);
    
    delay(100);
    
    analogWrite(10,0);
    analogWrite(6,0);
    analogWrite(11,0);
    digitalWrite(12,LOW);
    analogWrite(3,0);
    analogWrite(9,0); 
    delay(100);
  }
    analogWrite(9,175);
    analogWrite(5,238);
    analogWrite(3,238);
    delay(1000); 
    analogWrite(9,0);
    analogWrite(5,0);
    analogWrite(3,0);
  }
 

