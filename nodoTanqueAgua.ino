int trig = D3;
int echo = D4;
//int signal = 11;
int blanco = D0;
int amarillo = D5;
int azul = D6;
int rojo = D7;
int duracion;
int distancia;
  
void setup()
{
  pinMode(trig, OUTPUT);  
  pinMode(echo, INPUT);
  pinMode(blanco, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(rojo, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite (trig, HIGH);
  delay(1);
  digitalWrite (trig, LOW);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / 58.2;
  //distancia /= 100;
  
  if (distancia <= 100){
    digitalWrite(blanco, HIGH);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
    digitalWrite(rojo, LOW);
      Serial.println("Tanque lleno");
  } else if (distancia <= 150){
    digitalWrite(blanco, LOW);
    digitalWrite(amarillo, HIGH);
    digitalWrite(azul, LOW);
    digitalWrite(rojo, LOW);
      Serial.println("Tanque a la mitad");
  } else if (distancia <= 200){
    digitalWrite(blanco, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, HIGH);
    digitalWrite(rojo, LOW);    
      Serial.println("Tanque a 1/4");
  } else {
    digitalWrite(blanco, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
    digitalWrite(rojo, HIGH);
      Serial.println("Tanque vacio");
  }
  delay(200);
}