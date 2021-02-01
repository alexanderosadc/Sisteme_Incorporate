#define LED_PIN 4
#include <stdio.h>
String command;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  if(Serial.available())
  {
    char character = Serial.read();
    if(character == '1')
    {
      if(command == "led on")
      {
        digitalWrite(LED_PIN, HIGH);
      }
      else if(command == "led off")
      {
        digitalWrite(LED_PIN, LOW);
      }
      command = "";
      Serial.println();
    }
    else if(character)
    {
      Serial.print(character);
      command += character;
    }
   }
  }
