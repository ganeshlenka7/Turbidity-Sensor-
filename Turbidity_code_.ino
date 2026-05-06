#include <LiquidCrystal_I2C.h>

// LCD Address and Size
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Turbidity Sensor Pin
int sensorPin = A0;

// LED Pins
int clearLED = 2;
int cloudyLED = 3;
int dirtyLED = 4;

void setup()
{
  Serial.begin(9600);

  // LCD Start
  lcd.init();
  lcd.backlight();

  // LED Setup
  pinMode(clearLED, OUTPUT);
  pinMode(cloudyLED, OUTPUT);
  pinMode(dirtyLED, OUTPUT);

  // Startup Message
  lcd.setCursor(0, 0);
  lcd.print("Water Monitor");

  lcd.setCursor(0, 1);
  lcd.print("Initializing");

  delay(2000);

  lcd.clear();
}

void loop()
{
  // Read Raw Sensor Value
  int sensorValue = analogRead(sensorPin);

  // Convert to Turbidity %
  int turbidity = map(sensorValue, 0, 750, 100, 0);

  // Limit Values
  turbidity = constrain(turbidity, 0, 100);

  // Print SAME value in Serial Monitor
  Serial.print("Turbidity: ");
  Serial.print(turbidity);
  Serial.println("%");

  // LCD First Line
  lcd.setCursor(0, 0);
  lcd.print("Turbidity: ");

  lcd.setCursor(11, 0);
  lcd.print("    ");   // Clear old value

  lcd.setCursor(11, 0);
  lcd.print(turbidity);
  lcd.print("%");

  // CLEAR WATER
  if (turbidity < 20)
  {
    digitalWrite(clearLED, HIGH);
    digitalWrite(cloudyLED, LOW);
    digitalWrite(dirtyLED, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Crystal Clear ");
  }

  // CLOUDY WATER
  else if (turbidity >= 20 && turbidity < 50)
  {
    digitalWrite(clearLED, LOW);
    digitalWrite(cloudyLED, HIGH);
    digitalWrite(dirtyLED, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Filter Needed ");
  }

  // DIRTY WATER
  else
  {
    digitalWrite(clearLED, LOW);
    digitalWrite(cloudyLED, LOW);
    digitalWrite(dirtyLED, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("Unsafe Water! ");
  }

  delay(500);
}
