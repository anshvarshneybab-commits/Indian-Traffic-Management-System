//Librerias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2);  //

float tiempo1 = 0;
float tiempo2 = 0;
float distancia1 = 0;
float distancia2 = 0;
int tiempominverde = 5; 
int tiempomaxverde = 20;
int tiempoverde1 = 5;
int tiempoverde2 = 5;
int ledVerde1 = 2;
int ledAmarillo1 = 3;
int ledRojo1 = 4;
int ledVerde2 = 7;
int ledAmarillo2 = 6;
int ledRojo2 = 5;
int trigger1 =10; 
int echo1 =11;
int trigger2 =8; 
int echo2 =9;   


void setup()
{
 
  // Inicializar el LCD
  lcd.init();
 
  //Encender la luz de fondo.
  lcd.backlight();
 
  //Definimos entradas y salidas
  pinMode(trigger1, OUTPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledAmarillo1, OUTPUT);
  pinMode(ledRojo1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledAmarillo2, OUTPUT);
  pinMode(ledRojo2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //SEMAFORO1
  Serial.println("Tiempo en verde 1: ");
  Serial.println(tiempoverde1);//Muestra el tiempo del verde encendido
 
  Serial.println("Distancia 1: ");
  Serial.println(distancia1);
 
 //Mensaje en el LCD.
 lcd.clear();
 lcd.print("   Ansh Varshney ");
 lcd.setCursor(0,1);
 lcd.print("Project ")<<lcd.print(tiempoverde1)<<lcd.print("s");
 delay(100);
 
  digitalWrite(ledVerde1, HIGH);digitalWrite(ledAmarillo1, LOW);
  digitalWrite(ledRojo1, LOW);digitalWrite(ledVerde2, LOW);
  digitalWrite(ledAmarillo2, LOW);digitalWrite(ledRojo2, HIGH);
  delay(tiempoverde1 * 1000); //Convertir a milisegundos
 //pulso al sensor 1
  digitalWrite(trigger1, LOW);
  delayMicroseconds(4);
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger1, LOW);
 
  tiempo1 = pulseIn(echo1, HIGH);
  distancia1 = 0.01716*tiempo1; //distancia a cm
 
  if (distancia1>100)
  {
   
    tiempoverde1 = tiempoverde1 - 5;
   
   
    if (tiempoverde1 < tiempominverde)
    {
      tiempoverde1 = tiempominverde;
    }
  }
  else
  {
   
    tiempoverde1 = tiempoverde1 + 5;
   
   
    if (tiempoverde1 > tiempomaxverde)
    {
      tiempoverde1 = tiempomaxverde;
    }
  }

  digitalWrite(ledVerde1, LOW); digitalWrite(ledAmarillo1, HIGH);
  digitalWrite(ledRojo1, LOW);digitalWrite(ledVerde2, LOW);
  digitalWrite(ledAmarillo2, LOW);digitalWrite(ledRojo2, HIGH);
  delay(3000); //Amarillo encendido 3 segundos
 
  digitalWrite(ledVerde1, LOW); digitalWrite(ledAmarillo1, LOW);
  digitalWrite(ledRojo1, HIGH); digitalWrite(ledVerde2, LOW);
  digitalWrite(ledAmarillo2, LOW); digitalWrite(ledRojo2, HIGH);
 
   // SEMAFORO 2
  Serial.println("Tiempo en verde 2: ");
  Serial.println(tiempoverde2);
  Serial.println("Distancia 2: ");
  Serial.println(distancia2);
 
 //  Mensaje en el LCD.
 lcd.clear();
 lcd.print("   SEMAFORO 2  ");
 lcd.setCursor(0,1);
 lcd.print("Verde  ")<<lcd.print(tiempoverde2)<<lcd.print("S");
 delay(100);
 
  digitalWrite(ledVerde1, LOW);digitalWrite(ledAmarillo1, LOW);
  digitalWrite(ledRojo1, HIGH); digitalWrite(ledVerde2, HIGH);
  digitalWrite(ledAmarillo2, LOW); digitalWrite(ledRojo2, LOW);
  delay(tiempoverde2 * 1000); //Convertir a milisegundos
 
  // pulso al sensor 2
  digitalWrite(trigger2, LOW);
  delayMicroseconds(4);
  digitalWrite(trigger2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger2, LOW);
 
  tiempo2 = pulseIn(echo2, HIGH);
  distancia2 = 0.01716*tiempo2; //tiempo a uS y distancia a cm
 
  if (distancia2>100)
  {
   
    tiempoverde2 = tiempoverde2 - 5;
   
   
    if (tiempoverde2 < tiempominverde)
    {
      tiempoverde2 = tiempominverde;
    }
  }
  else
  {
   
    tiempoverde2 = tiempoverde2 + 5;
   
   
    if (tiempoverde2 > tiempomaxverde)
    {
      tiempoverde2 = tiempomaxverde;
    }
  }
 
  digitalWrite(ledVerde1, LOW);digitalWrite(ledAmarillo1, LOW);
  digitalWrite(ledRojo1, HIGH);digitalWrite(ledVerde2, LOW);
  digitalWrite(ledAmarillo2, HIGH);digitalWrite(ledRojo2, LOW);
  delay(3000); //Amarillo3 segundos
 
  digitalWrite(ledVerde1, LOW); digitalWrite(ledAmarillo1, LOW);
  digitalWrite(ledRojo1, HIGH); digitalWrite(ledVerde2, LOW);
  digitalWrite(ledAmarillo2, LOW); digitalWrite(ledRojo2, HIGH);
   
 
}
