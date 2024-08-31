//https://playground.arduino.cc/Interfacing/Processing/
//https://steemit.com/kr-newbie/@codingman/processing-i
/*import processing.serial.*;
import cc.arduino.*;

Arduino arduino;
int ledPin=13;

void setup() {  
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  arduino.pinMode(ledPin, Arduino.OUTPUT);
}
//pinMode(13,OUTPUT) => arduino.pinMode(13,Arduino.OUTPUT);
void draw() {
  arduino.digitalWrite(ledPin,Arduino.HIGH);
  delay(1000);
  arduino.digitalWrite(ledPin, Arduino.LOW);
  delay(1000);  
}*/
import processing.serial.*;
import cc.arduino.*;

Arduino arduino;
int ledPin=13;

boolean cnt = false;

void setup() {  // this is run once.   
    
    // set the background color
    background(255);
    
    // canvas size (Integers only, please.)
    size(600, 600); 
        
    //println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  arduino.pinMode(ledPin, Arduino.OUTPUT);
  fill(0);
} 

void draw() {  // this is run repeatedly.  
    rect(10,10,580,300,10);    
    rect(200,350,200,100,10);    
}

void mousePressed(){
 if(mouseX>200 && mouseX<400 && mouseY>350 && mouseY <450){
     cnt=!cnt;
 }
 if(cnt==true) {
   arduino.digitalWrite(ledPin,Arduino.HIGH);
   fill(255,0,0);
    }
 else{
   arduino.digitalWrite(ledPin,Arduino.LOW);
   fill(0,0,0);
 }
}
