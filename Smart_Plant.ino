#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 7 // 온습도 센서
#define DHTTYPE DHT11
#define A0Pin 0 // 토양 수분 센서

LiquidCrystal_I2C lcd(0x3F,16,2); // LCD I2C 연결
int SensorVal = 0;

DHT dht(DHTPIN,DHTTYPE);

void setup(){
  
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();
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

  if(Serial.available()){ 

    if(SensorVal <= 900){ // 토양 수분량이 충분하면 Slave에 1이란 신호 보냄
    Serial.write('1');
  }
    else if(SensorVal > 900){ // 토양 수분량이 부족하면 Slave에 0이란 신호 보냄
    Serial.write('0');
  }

  }
  lcd.clear();
}
