#include <LiquidCrystal_I2C.h>

const int upButton = 7;
const int downButton = 8;
const int selectButton = 9;
const int max = 9;
const char* schedules[] = {"Tuesday 1",   "Tuesday 2",  "Wednesday 1",
                           "Wednesday 2", "Thursday 1", "Thursday 2",
                           "Friday 1",    "Friday 2"};
int option = 0;
bool selected = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  lcd.init();
  lcd.backlight();
  lcd.print("Select your day.");
  lcd.setCursor(0, 1);
  lcd.print(">" + String(schedules[option]));
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  updateSel();
}
void loop() {
  if (!digitalRead(downButton)) {
    if (selected) {
      selected = 0;
      option--;
    }
    option++;
    updateSel();
    delay(100);
    while (!digitalRead(downButton))
      ;
  }
  if (!digitalRead(upButton)) {
    if (selected) {
      selected = 0;
      option--;
    }
    option--;
    updateSel();
    delay(100);
    while (!digitalRead(upButton))
      ;
  }
  if (!digitalRead(selectButton)) {
    if (!selected) select(option);
    updateSel();
    delay(100);
    while (!digitalRead(selectButton))
      ;
  }

  if (selected) {
    select(option);
  }
}

void screenOption(int option) {
  lcd.clear();
  lcd.print(">" + String(schedules[option - 1]));
  lcd.setCursor(0, 1);
  if (option == max)
    lcd.print(" ");
  else
    lcd.print(" " + String(schedules[option]));
}

void updateSel() {
  if (option == max) option--;
  if (option < 0) option = 0;
  if (option != 0) screenOption(option);
}

void select(int option) {
  lcd.clear();
  lcd.setCursor(0, 0);
  if (option == 0)
    lcd.print(String(schedules[option]));
  else
    lcd.print(String(schedules[option - 1]));
  delay(5000);
  selected = 1;
}

bool i2CAddrTest(uint8_t addr) {
  Wire.begin();
  Wire.beginTransmission(addr);
  return !Wire.endTransmission();
}