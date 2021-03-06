#ifdef UseDisplay

//= DEFINES ========================================================================================
#define DISPLAY_STATUS_POS 15
#define DISPLAY_I2C_ADDRESS 0x27

#define BLANK_LINE "                                        "
#define TEST_LINE  "***************#123456789012345678901234"

//= INCLUDE ========================================================================================

//= CONSTANTS ======================================================================================

//= VARIABLES ======================================================================================
LiquidCrystal_I2C lcd(DISPLAY_I2C_ADDRESS, 16, 2);
byte progress = 0;                  // used to indicate progress on display

//**************************************************************************************************
void display_Setup() {
  lcd.init();                 // initialise the LCD

  lcd.backlight(); // turn backlight on
  lcd.blink();     // cursor blinks
  //------------- TEST SCREEN -----------------------
  lcd.clear();         // clear the screen
  lcd.home();          // set the cursor to position 0, line 1
  lcd.print(TEST_LINE);
  lcd.setCursor(0, 1);
  lcd.print(TEST_LINE);
  lcd.home();
  delay(TIME_TICK * 50);
  //-------------------
  lcd.clear();
  //-------------------------------------------------
  //lcd.noBacklight(); // turn backlight off
  lcd.noBlink();
}
//**************************************************************************************************

#endif

//==================================================================================================
void display_Print1stLine(struct Action *action) {
  display_Print1stLine(action, action->name);
}
//==================================================================================================
void display_Print1stLine(struct Action *action, const char* label) {
  char buffer[30];
  sprintf(buffer, "A%02d:%11s", action->actionCode, label);
  display_Print1stLine(buffer);
}
//==================================================================================================
void display_Print1stLine(const char* label) {
#ifdef UseDisplay
  lcd.home();
  lcd.print(BLANK_LINE);
  lcd.home();
  lcd.print(label);
#endif
}
//==================================================================================================
void display_ShowProgress() {
#ifdef UseDisplay

  lcd.setCursor(DISPLAY_STATUS_POS, 0);        // set the cursor to position 15, line 2
  progress = progress + 1;
  if (progress == 1) {
    lcd.print("+");
  } else if (progress == 2) {
    lcd.print("-");
  } else if (progress == 3) {
    lcd.print("#");
  } else if (progress == 4) {
    lcd.print("|");
  } else {
    lcd.print("*");
    progress = 0;
  }

#endif
}
//==================================================================================================
void display_Print2ndLine(const char* label) {
#ifdef UseDisplay
  lcd.setCursor(0, 1);        // set the cursor to position 0, line 2
  lcd.print(BLANK_LINE);
  lcd.setCursor(0, 1);
  lcd.print(label);
#endif
}
//==================================================================================================
void display_Clear1stLine() {
  __ClearLine(0);
}
//==================================================================================================
void display_Clear2ndLine() {
  __ClearLine(1);
}
//==================================================================================================
void __ClearLine(byte line) {
#ifdef UseDisplay
  lcd.setCursor(0, line);
  lcd.print(BLANK_LINE);
  lcd.setCursor(0, line);
#endif
}
//==================================================================================================
