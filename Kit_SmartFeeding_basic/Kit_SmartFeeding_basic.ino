#include <ESP32Servo.h>


Servo servo;

int sensor = D2;
static const int servoPin = D5;

void setup(){
  Serial.begin(115200);

  servo.attach(servoPin);
  servo.write(50);

  pinMode(sensor, INPUT);
}

void loop(){
  int result = digitalRead(sensor);
  
  if(result == HIGH){
    servo.write(0);
    delay(2000);
    }
  else
    servo.write(50);
}
