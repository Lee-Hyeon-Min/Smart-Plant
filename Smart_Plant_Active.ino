#define LED A2
int pump = 13; // PORTB의 5번 => DDRB |= 0x20

void setup() {
  Serial.begin(9600);
  pinMode(pump,OUTPUT); // 13번 pin output mode
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char data_rcvd = Serial.read();
    if(data_rcvd == '1'){
     digitalWrite(pump,LOW); // 13번 pin 나중에 |= 연산 진행
     delay(1000);
    }
    else if(data_rcvd == '0'){
     digitalWrite(pump,HIGH); // 13번 pin 나중에 |= 연산 진행
     delay(1000);  
    }
    if(data_rcvd == 'a'){ // 온도가 낮을 때
      analogWrite(LED, 200);
      delay(1000);
    }
    else if(data_rcvd == 'b'){ // 온도가 높을 때
      analogWrite(LED, 150);
      delay(1000);
    }
  }
}