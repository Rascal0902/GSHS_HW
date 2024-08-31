void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.println("Hellow Ardulno");
}

void loop() {
  // put your main code here, to run repeatedly:
  char read_data;
  if(Serial.available())
  {
     read_data = Serial.read();
     if(read_data == 'b')
     {
        Serial.print("Bingo..");
     }
     else if(read_data == 'k')
     {
        digitalWrite(LED_BUILTIN, HIGH);   
        delay(1000);                      
        digitalWrite(LED_BUILTIN, LOW);   
        delay(10);
        Serial.print("Korea..");
     }
  }
}
