// include the library code:
#include <LiquidCrystal.h>
#define paper 8
#define rock 7
#define scissors 6
#define red 13
#define green 9
#define blue 10
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String values[]={"paper","scissors","rock"};
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(paper,INPUT_PULLUP);
  pinMode(scissors,INPUT_PULLUP);
  pinMode(rock,INPUT_PULLUP);
  // Print a message to the LCD.
  pinMode(blue,OUTPUT);
   pinMode(red,OUTPUT);
   pinMode(green,OUTPUT);
}

void loop() {
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  int generated = random(0,2) ;
   int user;
   //0 paper, 1 scissors, 2 rock
  lcd.setCursor(0, 0);
  lcd.print("Choose Paper");
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Scissor or rock");
  if(digitalRead(paper)==LOW){user=0;results(user,generated);}
  if(digitalRead(rock)==LOW){user=2;results(user,generated);}
  if(digitalRead(scissors)==LOW){user=1;results(user,generated);}
  
  
  
  
}

int results(int user, int generated){
  lcd.clear();
  bool fin = false;
  while(!fin){
  lcd.setCursor(0,0);
  lcd.print("You:" +values[user]);
  lcd.setCursor(0,1);
  delay(1000);
  lcd.print("Me:");
  delay(3000);
  lcd.print(values[generated]); 
    delay(1000);
    switch (user){
      case 0:
      if(generated==1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You loose :)");
        digitalWrite(red,HIGH);
        delay(1000);
      	fin=true;}
      if(generated==2){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You win :(");
        digitalWrite(green,HIGH);
        delay(1000);
      	fin=true;}
      if(generated==0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Draw :O");
        digitalWrite(blue,HIGH);
        delay(1000);
      	fin=true;}
      break;
     case 1:
      if(generated==2){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You loose :)");
        digitalWrite(red,HIGH);
        delay(1000);
      	fin=true;}
      if(generated==0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You win :(");
        digitalWrite(green,HIGH);
        delay(1000);
      	fin=true;}
      if(generated==1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Draw :O");
        digitalWrite(blue,HIGH);
        delay(1000);
      	fin=true;}
      break;
    case 2:
      if(generated==0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You loose :)");
        digitalWrite(red,HIGH);
        delay(1000);
      	fin=true;}
      if(generated==1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You win :(");
        digitalWrite(green,HIGH);
        delay(1000);
      	fin=true;}
      if(generated==2){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Draw :O");
        digitalWrite(blue,HIGH);
        delay(1000);
      	fin=true;}
      break;
  }
    
  }}

