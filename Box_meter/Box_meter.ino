#include <Ultrasonic.h>
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
#define NUM_LCD_COLUMNS 20
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, NUM_LCD_COLUMNS, 4);
const byte trigPing1 = 8;
const byte echoPin1  = 7;
const byte trigPing2 = 10;
const byte echoPin2  = 9;
const byte trigPing3 = 12;
const byte echoPin3  = 11;

Ultrasonic ultrasonic1(trigPing1, echoPin1), ultrasonic2(trigPing2, echoPin2), ultrasonic3(trigPing3, echoPin3);
const int wallDist1 = 40, wallDist2 = 40, wallDist3 = 40;

int distance1, distance2, distance3;
int dimension1, dimension2, dimension3;
//Volume is long to avoid overflow on 16-bit system, which can be caused if dimensions are greater than 32cm each.
unsigned long volume;
char line1[NUM_LCD_COLUMNS], line2[NUM_LCD_COLUMNS], line3[NUM_LCD_COLUMNS];

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  lcd.print("Log Box Meter");
  lcd.setCursor(0,1); //coluna, linha
  lcd.print("Iniciando...");
}

void loop() {
  distance1 = ultrasonic1.read();
  distance2 = ultrasonic2.read();
  distance3 = ultrasonic3.read();

  dimension1 = wallDist1 - distance1;
  dimension1 = constrain(dimension1, 0, 200);
  dimension2 = wallDist2 - distance2;
  dimension2 = constrain(dimension2, 0, 200);
  dimension3 = wallDist3 - distance3;
  dimension3 = constrain(dimension3, 0, 200);
  volume     = (unsigned long) ((unsigned long)dimension1 * (unsigned long)dimension2 * (unsigned long)dimension3);
  
  // Output in Serial
  Serial.print("Distances in cm: ");
  Serial.println(distance1);
  Serial.println(distance2);
  Serial.println(distance3);
  Serial.print("Dimensions in cm: ");
  Serial.println(dimension1);
  Serial.println(dimension2);
  Serial.println(dimension3);
  Serial.print("Volume in cm3: ");
  Serial.println(volume);

  // Output in LCD
  lcd.clear();

  lcd.setCursor(0,0);
  sprintf(line1, "x1 = %d cm", dimension1);
  lcd.print(line1);

  lcd.setCursor(0,1);
  sprintf(line2, "x2 = %d cm", dimension2);
  lcd.print(line2);

  lcd.setCursor(0,2);
  sprintf(line3, "x3 = %d cm", dimension3);
  lcd.print(line3);

  lcd.setCursor(0,3);
  sprintf(line3, "V  = %lu cm3", volume);
  lcd.print(line3);
  
  delay(2000);
}
