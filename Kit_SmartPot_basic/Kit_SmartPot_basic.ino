#include "oled_u8g2.h"
OLED_U8G2 oled;

const int moisturePin = A3;

const int pin1 = D3;
const int pin2 = D4;
const int threshold = 3000;

void setup(){
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  oled.setup();  
}

void loop(){
  display_oled();
  delay(1); 
}

void setup_oled(){
  pinMode(SDA, INPUT);
  pinMode(SCL, INPUT);  
}

void display_oled(){
  int moistureValue = 4095 - analogRead(moisturePin);
  Serial.print("토양 수분 센서값 : ");
  Serial.println(moistureValue);
  Serial.println("------------------");

  if(moistureValue < threshold){
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  }
  else{
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }  

  char text[32] = "moist : ";
  char value[32];
  String str = String(moistureValue, DEC);
  str.toCharArray(value, 6);
  strcat(text, value);

  oled.setLine(1, "* Smart POT *");
  oled.setLine(2, text);
  oled.setLine(3, "-----------");
  oled.display();
  delay(500);
}
