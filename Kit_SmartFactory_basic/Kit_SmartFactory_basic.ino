#include "oled_u8g2.h"
OLED_U8G2 oled;

int RESET_PIN = D7;
int TRIG = D9;
int ECHO = D8;

int count = 0;
char temp_buffer[255] = {0, };
int pre_time = 0;

void oled_show(int count){
  sprintf(temp_buffer, "count : %d", count);
  oled.setLine(1, "*Smart Factory*");
  oled.setLine(2, temp_buffer);
  oled.setLine(3, "-------___-");
  oled.display();  
}

void setup(){
  Serial.begin(115200);
  oled.setup();
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RESET_PIN, INPUT);

  oled_show(count);
}

void loop(){
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);  
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 17 /1000;
  Serial.println(distance);

  if(distance < 10){
    int now_time = millis();
    if(now_time - pre_time > 500){
      count += 1;

      Serial.print("count : ");
      Serial.println(count);

      oled_show(count);
      delay(1000);

      pre_time = now_time;
    }
  }

  if(digitalRead(RESET_PIN) == LOW){
    Serial.println("reset count");
    count = 0;
    oled_show(count);  
  }
}
