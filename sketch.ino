#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int r=0;
int vrx=A1;
int vry=A0;
int sw=A2;
int readingx=0;
int readingy=0;
int x=0;
int y=0;
int score=0;
byte monster[8] = {
  B00100,
  B01110,
  B01110,
  B01111,
  B01100,
  B11110,
  B01110,
  B00100
};
byte food[] = {
  B00011,
  B00111,
  B01111,
  B11111,
  B11111,
  B01111,
  B00111,
  B00011
};

void setup() {
  // put your setup code here, to run once:
pinMode(sw,INPUT_PULLUP);
pinMode(vrx,INPUT);
pinMode(vry,INPUT);
Serial.begin(9600);
lcd.init();
lcd.backlight();
lcd.createChar(0,monster);
lcd.setCursor(x,y);
 lcd.write(byte(0));
lcd.createChar(1,food);

}

 void win(){
score++;
Serial.println(score);

 }
  void lose(){
score=0;
Serial.println("Game Over");

 }

void loop() {
   // put your main code here, to run repeatedly:

   
 for(byte i=19;i>=0;i--){
 int z=i+2;

lcd.setCursor(i,r);
lcd.write(byte(1));
lcd.setCursor(z,r);
lcd.write(byte(1));

delay(200);
lcd.setCursor(i,r);
lcd.print(" ");
lcd.setCursor(z,r);
lcd.print(" ");

/*if(i==0){
 
  lcd.setCursor(z,r);
lcd.write(byte(1));
delay(2000);
}*/
if(z==x&&r==y){
  win();
}
if(i==x&&r==y){
  lose();
}

readingx=analogRead(vrx);
readingy=analogRead(vry);

if(readingy>=750){
  if(y<0)y=3;
  lcd.setCursor(x,y);
  lcd.print(" ");
  lcd.setCursor(x,--y);
 lcd.write(byte(0));
//Serial.print("F");
delay(100);
}

 else if(readingy<=500){
  if(y>3)y=0;
  lcd.setCursor(x,y);
  lcd.print(" ");
  lcd.setCursor(x,++y);
 lcd.write(byte(0));
//Serial.print("B");
delay(100);
}
 else if(readingx>=750){
if(x<0)x=19;
    lcd.setCursor(x,y);
  lcd.print(" ");
  lcd.setCursor(--x,y);
 lcd.write(byte(0));
//Serial.print("L");
delay(100);  

}
else if(readingx<=450){
  if(x>19)x=0;
  lcd.setCursor(x,y);
  lcd.print(" ");
  lcd.setCursor(++x,y);
 lcd.write(byte(0));
//Serial.print("R");
delay(100);
}
else{
    lcd.setCursor(x,y);
  lcd.print(" ");
  lcd.setCursor(x,y);
 lcd.write(byte(0));
//Serial.print("S");
delay(100);
}

}

 r= random(3);

}
 
