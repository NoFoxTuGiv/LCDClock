#include <Arduino.h>
#include <LiquidCrystal.h>
#include <RTClib.h>

RTC_DS1307 rtc;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char time[30];

void getTime(void);

void setup() {
  // Initialize RTC
  if (!rtc.begin()) {
    lcd.print("RTC not found");
    while (1); // Halt the program
  }

  // Set RTC time only if it's not running
  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  getTime();

  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print(time);
  lcd.setCursor(0, 1);
  lcd.print("NoFoxTuGiv");
}

void getTime(void) {
  DateTime now = rtc.now();

  int hour = now.hour();
  if (hour < 0) hour += 24;
  if (hour >= 24) hour -= 24;

  bool isPM = hour >= 12;
  hour = hour % 12;
  if (hour == 0) hour = 12;

  sprintf(time, "%02d:%02d:%02d %s", hour, now.minute(), now.second(), isPM ? "PM" : "AM");

  delay(1000);
}