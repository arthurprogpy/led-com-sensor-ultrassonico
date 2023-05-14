#include <Ultrasonic.h> //inclusao da biblioteca do sensor
#define TRIGGER_PIN 3 // trigger conectado ao pino 3
#define ECHO_PIN 2 // echo conectado ao pino 2
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
const int led1 = 5; // o numero do pino do LED1
const int led2 = 6; // o numero do pino do LED2
const int led3 = 7; // o numero do pino do LED3
void setup() {
Serial.begin(9600); //Habilita Comunicação Serial a uma taxa de 9600
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
}
void loop() {
 float distancia;
long microsec = ultrasonic.timing();
//retorna a distancia em CM
distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
 Serial.print(distancia);
 Serial.println("cm"); //imprime o valor da variável distancia
 delay(100);

 if (distancia<60) // se a distancia menor que 60 liga led1
 digitalWrite(led1, HIGH); // liga led1

 if (distancia<30) // se a distancia menor que 30 liga led2
 digitalWrite(led2, HIGH); //liga led2

 if (distancia<15) // se a distancia menor que 15 liga led3
 digitalWrite(led3, HIGH); //liga led3

 if (distancia<5 ) // se a distancia for menor que 5
 digitalWrite(led1, HIGH); // Fica piscando todos
 digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
 delay(500);
 digitalWrite(led1, LOW);
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);
 delay(500);
} void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
