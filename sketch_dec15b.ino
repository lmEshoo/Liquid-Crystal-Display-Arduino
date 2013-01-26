#include <LiquidCrystal.h>

unsigned  ledRed = 12;
unsigned ledGreen = 13;
unsigned counter = -1;  // or int
unsigned Byte = 33;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
   lcd.begin(16, 2);
   pinMode(ledRed,OUTPUT);    // Sets pin12 as an output
   pinMode(ledGreen,OUTPUT);  // Sets pin13 as an output
   Serial.begin(9600);        // not sure, but must
   //Serial.println("Hello blah"); 
   outputASCII();
   lcd.print("hello, world!");
   lcd.setCursor(4,1);
   lcd.print("& lenny");
}  //setup
void loop(){
  counter+=1; 
  ledLight(ledRed);
  Serial.print(counter);
  sec(counter);
  ledLight(ledGreen);
  anaToVoltConvert();

}  //loop

void sec( int count ){
  if( count > 1 || count < 1)
      Serial.println(" seconds");
  else Serial.println(" second");
}  //sec

void ledLight( unsigned lightPin ){
  digitalWrite(lightPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(750);                     // wait for a second
  digitalWrite(lightPin, LOW);    // turn the LED off by making the voltage LOW  
}  //ledLight

void anaToVoltConvert(){
  //read input from analog pin 0:
  unsigned sensorValue = analogRead(A0);
  double voltage = sensorValue*(5.0/1023.0);
  Serial.print("  ");
  Serial.print(voltage);
  Serial.println(" Voltages");
  delay(500);
}  //anaToVoltConvert

void outputASCII(){
  for( unsigned i=Byte; i<93; i++){
      Serial.write(Byte);
      Serial.print(", dec: ");
      Serial.print(Byte);
      Serial.print(", Hex: ");
      Serial.print(Byte, HEX);
      Serial.print(", Oct: ");
      Serial.print(Byte, OCT);
      Serial.print(", Bin: ");
      Serial.println(Byte, BIN);
      Byte++;
  }
}  //outputASCII
