
#include <stdio.h>

String command;

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  if(Serial.available())
  {
    char character = getchar();
    if(character == '1')
    {
      if(command == "led on")
      {
        digitalWrite(4, HIGH);
      }
      else if(command == "led off")
      {
        digitalWrite(4, LOW);
      }
      command = "";
      Serial.println();
    }
    else if(character)
    {
      Serial.print(character);
      command += character;
    
    }
    //Serial.println(command);
    
   }
  }
