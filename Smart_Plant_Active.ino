#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

int pump = 13;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  char data_rcvd = Serial.read();
  if(data_rcvd == '1'){
    digitalWrite(pump,LOW);
    delay(1000);
  }
  else if(data_rcvd == '0'){
    digitalWrite(pump,HIGH);
    delay(1000);  
  }
}