/*#include <SoftwareSerial.h>
SoftwareSerial BTSerial(8,9);

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
BTSerial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:
if(BTSerial.available())
Serial.write(BTSerial.read());
if(Serial.available())
BTSerial.write(Serial.read());
}*/
/*#include <SoftwareSerial.h>
#define DOOR_PIN 8
#define RST_PIN 9
#define SS_PIN 10
SoftwareSerial BTSerial(2, 3);
void setup(){
Serial.begin(9600);
BTSerial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);
pinMode(DOOR_PIN, INPUT);
}
void loop(){
if(Serial.available()){
BTSerial.write(Serial.read());
}
if(BTSerial.available()){
char data = BTSerial.read();
Serial.write(data);
if(data == 'go'){
Serial.println(" = OK, Door Open");
pinMode(DOOR_PIN, OUTPUT);
digitalWrite(DOOR_PIN, LOW);
digitalWrite(LED_BUILTIN, LOW);
delay(500);
digitalWrite(DOOR_PIN, HIGH);
digitalWrite(LED_BUILTIN, HIGH);
delay(2500);
}
else{
Serial.println("Wrong.");
BTSerial.write("");
}
}
}*/
/*#include<SPI.h>
#include<MFRC522.h>

#define DOOR_PIN 8
#define RST_PIN 9
#define SS_PIN 10

MFRC522 rc522(SS_PIN,RST_PIN);

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rc522.PCD_Init();
  Serial.println("Card Scaning\r\n");
  pinMode(DOOR_PIN,INPUT);
}
void loop(){
   if(!rc522.PICC_IsNewCardPresent()) return;
   if(!rc522.PICC_ReadCardSerial()) return;
   if(rc522.uid.uidByte[0] == 0x80 && rc522.uid.uidByte[1] == 0xE7&& rc522.uid.uidByte[2] == 0xB5
       && rc522.uid.uidByte[3] == 0x4F)
       {
        Serial.println("Registered card ===>> Door Open");
        pinMode(DOOR_PIN,OUTPUT);
        digitalWrite(DOOR_PIN,LOW);
        delay(500);
        pinMode(DOOR_PIN,INPUT);
        delay(2500);
       }
       else
       {
        Serial.println("====== Unregisterd card ======");
       }
}*/
#include <SPI.h>
#include <MFRC522.h>

#define DOOR_PIN 8
#define RST_PIN 9
#define SS_PIN 10

MFRC522 rc522(SS_PIN, RST_PIN);

void setup(){
Serial.begin(9600);
SPI.begin();
rc522.PCD_Init();
Serial.println("Card Scaning\r\n");
pinMode(DOOR_PIN, INPUT);
}

void loop(){
if (!rc522.PICC_IsNewCardPresent()) return;
if (!rc522.PICC_ReadCardSerial()) return;
if (rc522.uid.uidByte[0] == 10 && rc522.uid.uidByte[1] == 53
&& rc522.uid.uidByte[2] == 52 && rc522.uid.uidByte[3] == 9){
Serial.println("Registered card ===>> Door Open");
pinMode(DOOR_PIN, OUTPUT);
digitalWrite(DOOR_PIN, LOW);
delay(500);
pinMode(DOOR_PIN, INPUT);
delay(2500);
}
else{
Serial.println("====== Unregistered card =======");
delay(500);
}
}
/*
#include <SPI.h>
#include <MFRC522.h>

#define DOOR_PIN 8
#define RST_PIN 9
#define SS_PIN 10

MFRC522 rc522(SS_PIN, RST_PIN);

byte key[5][4];

void setup(){
Serial.begin(9600);
SPI.begin();
rc522.PCD_Init();
Serial.println("Card Scaning\r\n");
pinMode(DOOR_PIN, INPUT);

key[0][0] = 0x97;
key[0][1] = 0xB1;
key[0][2] = 0xD2;
key[0][3] = 0x34;

key[1][0] = 0x4F;
key[1][1] = 0xA4;
key[1][2] = 0x96;
key[1][3] = 0xF0;
}

void loop(){
if (!rc522.PICC_IsNewCardPresent()) return;
if (!rc522.PICC_ReadCardSerial()) return;
bool tf = false;
for (int i=0; i<2; i++){
tf = true;
for (int j=0; j<4; j++) if (rc522.uid.uidByte[j] != key[i][j]) tf = false;
if (tf){
Serial.println("Registered card ===>> Door Open");
pinMode(DOOR_PIN, OUTPUT);
digitalWrite(DOOR_PIN, LOW);
delay(500);
pinMode(DOOR_PIN, INPUT);
delay(2500);
break;
}
}
if (!tf){
Serial.println("====== Unregistered card =======");
delay(500);
}
}

Serial.println(rc522.uid.uidByte[0]);
Serial.println(rc522.uid.uidByte[1]);
Serial.println(rc522.uid.uidByte[2]);
Serial.println(rc522.uid.uidByte[3]);*/
