const int echo = D8;
const int trig = D9;
const int cds = A3;

const int led1 = D3; //blue
const int led2 = D2; //green

const int cds_threshold = 300;
const int usw_threshold = 30;

void setup(){
  Serial.begin(57600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(cds, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop(){
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);
  float distance = ((float)(340 * duration) / 10000) / 2;
  int cdsValue = (analogRead(cds))/10;
  
  if ( cdsValue < cds_threshold )
    digitalWrite(led1, HIGH);
  else
    digitalWrite(led1, LOW);

  Serial.print(" 조도 센서 : ");
  Serial.println(cdsValue);

  if( distance < usw_threshold )
    digitalWrite(led2, HIGH);
  else
    digitalWrite(led2, LOW);

  Serial.print( " 초음파 센서 : ");
  Serial.print(distance);
  Serial.println("cm");
  Serial.println("-----------------");

  delay(300);
}
