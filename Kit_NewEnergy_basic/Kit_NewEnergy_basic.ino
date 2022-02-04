#include "oled_u8g2.h"
OLED_U8G2 oled;

const double c_value = 0.001221245421;

void setup(){

  Serial.begin(9600);
  oled.setup();
}

void loop(){
  display_oled();
  delay(1000);
}

void setup_oled(){
  pinMode(SDA, INPUT);
  pinMode(SCL, INPUT);
}

void display_oled(){
  int solar_voltage_value = analogRead(A3);
  Serial.print("태양광 센서 : ");
  Serial.println(solar_voltage_value);

  char text1[32] = "S : ";
  char value1[32];
  String str = String(solar_voltage_value * c_value, DEC);
  str.toCharArray(value1, 6);
  strcat(text1, value1);
  strcat(text1, "V");
  
  int windturbine_voltage_value = analogRead(A5);
  Serial.print("풍력 센서 : ");
  Serial.println(windturbine_voltage_value);
  Serial.println("-------------------");

  char text2[32] = "W : ";
  char value2[32];
  String str2 = String(windturbine_voltage_value * c_value, DEC);
  str2.toCharArray(value2, 6);
  strcat(text2, value2);
  strcat(text2, "V");

  oled.setLine(1, "* ECO Energy *");
  oled.setLine(2, text1);
  oled.setLine(3, text2);
  oled.display();
}
