int valorpote;
#define V 11
#define A 10
#define R 9
#define pote A0

void setup()
{    
    pinMode(pote, INPUT);
    pinMode(R, OUTPUT);
    pinMode(V, OUTPUT);
    pinMode(A, OUTPUT);
    Serial.begin(9600);
    randomSeed(analogRead(A0));
}

void loop()
{
  valorpote = analogRead(pote);
  valorpote = map(valorpote, 0, 1023, 0, 100);
  Serial.println(valorpote);
  eleccion();
}

void eleccion()
{
  if(valorpote >= 0 && valorpote < 21)
  {
    ejercicio1(); 
    delay(1000);
  }
  else if(valorpote >= 21 && valorpote < 41)
  {
    ejercicio2(); 
    delay(1000);
  }
  else if(valorpote >= 41 && valorpote < 61)
  {
    ejercicio3(); 
    delay(1000);
  }
  else if(valorpote >= 61 && valorpote < 81)
  {
    ejercicio4(); 
    delay(1000);
  }
  else if(valorpote >= 81 && valorpote <= 100)
  {
    ejercicio5(); 
    delay(1000);
  }
}

void ejercicio1()
{
  int numeros[5] = {1, 2, 3, 4, 5};
  int tamano = 5;
  int multiplicados[5];
  int factor = 3;
  for(int x = 0; x < tamano; x++)
  {
    multiplicados[x] = numeros[x] * factor;
    if(multiplicados[x] == 3)
    {
      analogWrite(R, 255); analogWrite(V, 0); analogWrite(A, 0);
      delay(1000);
    }
    else if(multiplicados[x] == 6)
    {
      analogWrite(R, 0); analogWrite(V, 255); analogWrite(A, 0);
      delay(1000);
    } 
    else if(multiplicados[x] == 9)
    {
      analogWrite(R, 0); analogWrite(V, 0); analogWrite(A, 255);
      delay(1000);
    }
    else if(multiplicados[x] == 12)
    {
      analogWrite(R, 255); analogWrite(V, 0); analogWrite(A, 255);
      delay(1000);
    }
    else if(multiplicados[x] == 15)
    {
      analogWrite(R, 255); analogWrite(V, 255); analogWrite(A, 255);
      delay(1000);
    }
  }
}

void ejercicio2()
{
  int notas[10] = {10, 9, 6, 3, 8, 1, 4, 9, 6, 7};
  int tamano = 10;
  int promedio = 0;
  
  for(int x = 0; x < tamano; x++)
  {
    promedio += notas[x];
  }
  promedio = promedio / 10;
  
  if(promedio >= 1 && promedio <= 5)
  {
    analogWrite(R, 255); analogWrite(V, 0); analogWrite(A, 0);
    delay(1000);
  }
  else if(promedio >= 6 && promedio <= 8)
  {
    analogWrite(R, 0); analogWrite(V, 255); analogWrite(A, 0);
    delay(1000);
  } 
  else if(promedio >= 9 && promedio <= 10)
  {
    analogWrite(R, 0); analogWrite(V, 0); analogWrite(A, 255);
    delay(1000);
  } 
}

void ejercicio3()
{
  int notas[15] = {1, 4, 5, 6, 7, 10, 9, 6, 3, 8, 1, 4, 9, 6, 7}; // CORREGIDO: Quitada coma inicial extra
  int tamano = 15;
  int resto;
  for(int x = 0; x < tamano; x++)
  {
    resto = notas[x] % 2;
    if(resto == 0)
    {
      analogWrite(V, 255); analogWrite(A, 0); analogWrite(R, 0);
      delay(1000);
    }
    else
    {
      analogWrite(R, 255); analogWrite(A, 0); analogWrite(V, 0);
      delay(1000);
    }
  }
}

void ejercicio4()
{
  int numsaleatorios[30]; 
  int max1 = 0;
  int max2 = 0;
  int max3 = 0;
  
  int largovector = sizeof(numsaleatorios) / sizeof(numsaleatorios[0]);
  
  for(int x = 0; x < largovector; x++) 
  {
    numsaleatorios[x] = random(0, 256); 
    Serial.print(numsaleatorios[x]);
    Serial.print(" ");

    if (numsaleatorios[x] > max1) 
    {
      max3 = max2;       
      max2 = max1;
      max1 = numsaleatorios[x];
    } 
    else if (numsaleatorios[x] > max2) 
    {
      max3 = max2;       
      max2 = numsaleatorios[x];
    } 
    else if (numsaleatorios[x] > max3) 
    {
      max3 = numsaleatorios[x];
    }
  }
  Serial.println();
  
  analogWrite(R, max1);
  analogWrite(V, max2);
  analogWrite(A, max3);
  delay(1000);
}

void ejercicio5()
{
  int numsaleatorios[30]; 
  
  int min1 = 255; 
  int min2 = 255;
  int min3 = 255; 
  
  int largovector = sizeof(numsaleatorios) / sizeof(numsaleatorios[0]);
  for(int x = 0; x < largovector; x++) 
  {
    numsaleatorios[x] = random(0, 256); 
    Serial.print(numsaleatorios[x]);
    Serial.print(" ");

    if(numsaleatorios[x] < min1) 
    {
      min3 = min2;       
      min2 = min1;
      min1 = numsaleatorios[x];
    } 
    else if (numsaleatorios[x] < min2) 
    {
      min3 = min2;       
      min2 = numsaleatorios[x];
    } 
    else if (numsaleatorios[x] < min3) 
    {
      min3 = numsaleatorios[x];
    }
  }
  Serial.println();
  
  analogWrite(R, min1);
  analogWrite(V, min2);
  analogWrite(A, min3); 
 delay(1000);
}