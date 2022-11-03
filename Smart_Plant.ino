#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11
#define A0Pin 0

LiquidCrystal_I2C lcd(0x3F,16,2);
int SensorVal = 0;
int pump = 13;

DHT dht(DHTPIN,DHTTYPE);

void setup(){
  
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();
  pinMode(pump,OUTPUT);
}

void loop(){
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  SensorVal = analogRead(A0Pin);
  delay(1000);
  lcd.display();
  lcd.print("Temp = ");
  lcd.print(temperature);
  lcd.setCursor(0,1);
  lcd.print("Soil = ");
  lcd.print(SensorVal);
  Serial.print(temperature);
  Serial.print(SensorVal);
  if(SensorVal <= 900){
    digitalWrite(pump,LOW);
    delay(1000);
  }
  else if(SensorVal > 900){
    digitalWrite(pump,HIGH);
    delay(1000);
  }
  delay(10);
  lcd.clear();
}