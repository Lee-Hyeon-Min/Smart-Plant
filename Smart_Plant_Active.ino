#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

int pump = 13; // PORTB의 5번 => PB |= 0x20

void setup() {
  Serial.begin(9600);
  pinMode(pump,OUTPUT); // 13번 pin output mode
}

void loop() {
  // put your main code here, to run repeatedly:
  char data_rcvd = Serial.read();
  if(data_rcvd == '1'){
    digitalWrite(pump,LOW); // 13번 pin 나중에 |= 연산 진행
    delay(1000);
  }
  else if(data_rcvd == '0'){
    digitalWrite(pump,HIGH); // 13번 pin 나중에 |= 연산 진행
    delay(1000);  
  }
}
