int valorpote;
int ejercicioActual = -1;
unsigned long tiempoAnterior = 0;
int indiceLista = 0;


#define R 11  
#define A 10  
#define V 9  
#define pote A0

void setup()
{    
    pinMode(pote, INPUT);
    pinMode(R, OUTPUT);
    pinMode(V, OUTPUT);
    pinMode(A, OUTPUT);
    Serial.begin(9600);
    randomSeed(analogRead(A1)); 
   
    analogWrite(R, 0); analogWrite(V, 0); analogWrite(A, 0);
}

void loop()
{
  valorpote = analogRead(pote);
  valorpote = map(valorpote, 0, 1023, 0, 100);
  

  static int ultimoValor = -1;
  if(valorpote != ultimoValor) {
    Serial.print("Valor Pote: "); Serial.println(valorpote);
    ultimoValor = valorpote;
  }

  eleccion();
}

void eleccion()
{
  int nuevoEjercicio = -1;

  
  if(valorpote >= 0 && valorpote <= 20)      nuevoEjercicio = 1;
  else if(valorpote > 20 && valorpote <= 40) nuevoEjercicio = 2;
  else if(valorpote > 40 && valorpote <= 60) nuevoEjercicio = 3;
  else if(valorpote > 60 && valorpote <= 80) nuevoEjercicio = 4;
  else if(valorpote > 80 && valorpote <= 100) nuevoEjercicio = 5;


  if (nuevoEjercicio != ejercicioActual) 
  {
    ejercicioActual = nuevoEjercicio;
    Serial.print("Iniciando Ejercicio: "); Serial.print(ejercicioActual); Serial.println(" ---");
    indiceLista = 0; 
    
    if(ejercicioActual == 2) ejercicio2();
    else if(ejercicioActual == 4) ejercicio4();
    else if(ejercicioActual == 5) ejercicio5();
  }

 
  if(millis() - tiempoAnterior >= 1000) {
    tiempoAnterior = millis();
    if(ejercicioActual == 1) ejercicio1_secuencia();
    else if(ejercicioActual == 3) ejercicio3_secuencia();
  }
}


{
  int numeros[5] = {1, 2, 3, 4, 5};
  int multiplicados[5];
  int factor = 3;
  
 
  for(int i = 0; i < 5; i++) {
    multiplicados[i] = numeros[i] * factor;
  }
  

  Serial.print("Indice "); Serial.print(indiceLista);
  Serial.print("Resultado: "); Serial.println(multiplicados[indiceLista]);

 
  int brillo = multiplicados[indiceLista] * 15; 
  analogWrite(R, brillo); 
  analogWrite(V, brillo); 
  analogWrite(A, brillo);
  
  indiceLista = (indiceLista + 1) % 5;
}

// 2. Promedio de notas y asignación de colores específicos
void ejercicio2()
{
  int notas[10] = {10, 9, 6, 3, 8, 1, 4, 9, 6, 7};
  int suma = 0;
  
  for(int x = 0; x < 10; x++) {
    suma += notas[x];
  }
  float promedio = (float)suma / 10.0;
  
  Serial.print("Suma Total: "); Serial.print(suma);
  Serial.print(" | Promedio: "); Serial.println(promedio);
  
 
  if(promedio >= 1.0 && promedio <= 5.0) {
    analogWrite(R, 255); analogWrite(V, 0); analogWrite(A, 0); 
  } else if(promedio > 5.0 && promedio <= 8.0) {
    analogWrite(R, 0); analogWrite(V, 255); analogWrite(A, 0); 
  } else if(promedio > 8.0 && promedio <= 10.0) {
    analogWrite(R, 0); analogWrite(V, 255); analogWrite(A, 255); 
  } 
}


void ejercicio3_secuencia()
{
  int notas[15] = {1, 4, 5, 6, 7, 10, 9, 6, 3, 8, 1, 4, 9, 6, 7};
  
  Serial.print("Evaluando nota numero "); Serial.print(indiceLista + 1);
  Serial.print(": "); Serial.println(notas[indiceLista]);

  if(notas[indiceLista] % 2 == 0) {
    analogWrite(R, 0); analogWrite(V, 255); analogWrite(A, 0); 
  } else {
    analogWrite(R, 255); analogWrite(V, 0); analogWrite(A, 0); 
  }
  
  indiceLista = (indiceLista + 1) % 15;
}


void ejercicio4()
{
  int numsaleatorios[30];
  int max1 = -1, max2 = -1, max3 = -1;
  
  Serial.println("Valores aleatorios generados:");
  for(int x = 0; x < 30; x++) {
    numsaleatorios[x] = random(0, 256); 
    Serial.print(numsaleatorios[x]); Serial.print(" ");

    if (numsaleatorios[x] > max1) { 
      max3 = max2; 
      max2 = max1; 
      max1 = numsaleatorios[x]; 
    } 
    else if (numsaleatorios[x] > max2) { 
      max3 = max2; 
      max2 = numsaleatorios[x]; 
    } 
    else if (numsaleatorios[x] > max3) { 
      max3 = numsaleatorios[x]; 
    }
  }
  Serial.println();
  Serial.print("Max1: "); Serial.print(max1);
  Serial.print(" | Max2: "); Serial.print(max2);
  Serial.print(" | Max3: "); Serial.println(max3);
  
  
  analogWrite(R, max1); 
  analogWrite(A, max2); 
  analogWrite(V, max3);
}


void ejercicio5()
{
  int numsaleatorios[30];
  int min1 = 256, min2 = 256, min3 = 256; 
  
  Serial.println("Valores aleatorios generados:");
  for(int x = 0; x < 30; x++) {
    numsaleatorios[x] = random(0, 256); 
    Serial.print(numsaleatorios[x]); Serial.print(" ");

    if(numsaleatorios[x] < min1) { 
      min3 = min2; 
      min2 = min1; 
      min1 = numsaleatorios[x]; 
    } 
    else if (numsaleatorios[x] < min2) { 
      min3 = min2; 
      min2 = numsaleatorios[x]; 
    } 
    else if (numsaleatorios[x] < min3) { 
      min3 = numsaleatorios[x]; 
    }
  }
  Serial.println();
  Serial.print("Min1: "); Serial.print(min1);
  Serial.print(" | Min2: "); Serial.print(min2);
  Serial.print(" | Min3: "); Serial.println(min3);
  
 
  analogWrite(R, min1); 
  analogWrite(A, min2); 
  analogWrite(V, min3); 
}
