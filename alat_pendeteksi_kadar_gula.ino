#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int hijau = 9;
int merah = 8;

void setup(void)
{
 Serial.begin(9600);
lcd.begin();
 
 pinMode(hijau, OUTPUT);
 pinMode(merah, OUTPUT);
}

void loop(void)
{

 long pinRead = analogRead(A3);

 if (pinRead > 644){
  pinRead = 644;
  }

 long cah = (pinRead/2) * 100;
 long cahaya = cah*2;
 
 long percahaya = cahaya/644;

 long mg = (28.7 * percahaya) + 46;

 
 Serial.print("Persen Cahaya : ");
 Serial.print(percahaya);
 Serial.println();
 Serial.print("Kadar Gula Darah : ");
 Serial.print(mg);
 Serial.print(" mg/dl");
 Serial.println();
 Serial.println();

 if(percahaya < 50){
  if (mg<150){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gula Darah: ");
    lcd.print(mg);
    lcd.print("mg/dl");
    lcd.setCursor(0,1);
    lcd.print("Aman");
    digitalWrite(hijau, HIGH);
    digitalWrite(merah, LOW);
  }else if(mg>150){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gula Darah: ");
    lcd.print(mg);
    lcd.print("mg/dl");
    lcd.setCursor(0,1);
    lcd.print("Berbahaya");
    digitalWrite(hijau, LOW);
    digitalWrite(merah, HIGH);
  }else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tidak Ada Sample");
    digitalWrite(hijau, LOW);
    digitalWrite(merah, LOW);
    }
 }else{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tidak Ada Sample");
  digitalWrite(hijau, LOW);
  digitalWrite(merah, LOW);
  }

 delay(1000);

}
