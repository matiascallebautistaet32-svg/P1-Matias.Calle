#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define boton1 3
#define boton2 5
#define boton3 6
#define C3 131
#define G3 196
#define A3 220
#define F3 175
#define E3 165
#define D3 147
#define E3 165
#define F3 175
#define G3 196
#define D3 147
#define C3 131
#define G3 196
#define F3 175
#define E3 165
#define D3 147

int valorboton1;
int valorboton2;
int valorboton3;

const int midi1[21][3] = {
 {C3, 136, 0},
 {C3, 136, 0},
 {G3, 136, 0},
 {G3, 136, 0},
 {A3, 136, 0},
 {A3, 136, 0},
 {G3, 136, 0},
 {F3, 136, 0},
 {F3, 136, 0},
 {E3, 136, 0},
 {E3, 136, 0},
 {D3, 136, 0},
 {D3, 136, 0},
 {C3, 136, 0},
 {G3, 136, 0},
 {G3, 136, 0},
 {F3, 136, 0},
 {F3, 136, 0},
 {E3, 136, 0},
 {E3, 136, 0},
 {D3, 136, 0},
};

const int midi2[20][3] = {
 {E3, 136, 0},
 {E3, 136, 0},
 {F3, 136, 0},
 {G3, 136, 0},
 {G3, 136, 0},
 {F3, 136, 0},
 {E3, 136, 0},
 {D3, 136, 0},
 {C3, 136, 0},
 {C3, 136, 0},
 {D3, 136, 0},
 {E3, 136, 0},
 {E3, 136, 0},
 {D3, 136, 0},
 {D3, 136, 0},
 {E3, 136, 0},
 {E3, 136, 0},
 {F3, 136, 0},
 {G3, 136, 0},
 {G3, 136, 0},
};

const int midi3[20][3] = {
 {G3, 136, 0},
 {G3, 136, 0},
 {F3, 136, 0},
 {E3, 136, 0},
 {E3, 136, 0},
 {D3, 136, 136},
 {F3, 136, 0},
 {G3, 136, 0},
 {E3, 136, 136},
 {D3, 136, 0},
 {F3, 136, 136},
 {G3, 136, 0},
 {G3, 136, 0},
 {G3, 136, 0},
 {G3, 136, 0},
 {F3, 136, 0},
 {E3, 136, 0},
 {D3, 136, 0},
 {D3, 136, 0},
 {E3, 136, 0},
 };
   
   
void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}
void setup()
{
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  Serial.begin(9800);
   
}
void loop() 
{
 
  
  valorboton1 = digitalRead(boton1);
  Serial.println("Valor de boton1: ");
  Serial.println(valorboton1);
  delay(1000);
  
  valorboton2 = digitalRead(boton2);
  Serial.println("Valor de boton2: ");
  Serial.println(valorboton2);
  delay(1000);


  valorboton3 = digitalRead(boton3);
  Serial.println("Valor de boton3: ");
  Serial.println(valorboton3);
  delay(1000);

  
  if(valorboton1 == LOW)
  {
   playMidi(11, midi1, ARRAY_LEN(midi1));
   delay(1000);
  }
  if(valorboton2 == LOW)
  {
   playMidi(11, midi2, ARRAY_LEN(midi2));
   delay(1000);
  }
  if(valorboton3 == LOW)
  {
   playMidi(11, midi3, ARRAY_LEN(midi3));
   delay(1000);
  }
}
