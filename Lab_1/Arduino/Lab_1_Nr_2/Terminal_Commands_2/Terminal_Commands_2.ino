#include <stdio.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte rowsCol = 4;
char keys[rowsCol][rowsCol] = 
{
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'c', '0', '=', '+'}
};

byte rowPins[rowsCol] = {2, 3, 4, 5};
byte colPins[rowsCol] = {6, 7, 8, 9};
int i = 0;
char arr[10];
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rowsCol, rowsCol);

void setup() {
    lcd.begin(16, 2);
}

void loop() {
  char key = keypad.getKey();
  if(key)
  {
    lcd.print(key);
    lcd.display();
  }
}
