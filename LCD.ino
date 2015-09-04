

String lcd1_previous_message;
String lcd2_previous_message;
String lcd3_previous_message;

void setup_LCD_control()
{
  lcd1.begin (16, 2); //  LCD1 is 16x2
  lcd2.begin (16, 2); //  LCD2 is 16x2
  lcd3.begin (16, 2); //  LCD3 is 16x2

  lcd1.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd1.setBacklight(HIGH);
  lcd1.home (); // go home
  lcd2.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd2.setBacklight(HIGH);
  lcd2.home (); // go home
  lcd3.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd3.setBacklight(HIGH);
  lcd3.home (); // go home
  lcd1.print("V-tone");                  // Show LCD1 startup message
  display_parameter(1, 1, 0, "     by "); 
  display_parameter(1, 1, 1, "Gumtown");
  lcd2.print("a midi knob box");         // Show LCD2 startup message
  display_parameter(2, 1, 0, "control");
  display_parameter(2, 1, 1, "for the");  
  lcd3.print("GP-10, GT-100");           // Show LCD3 startup message
  display_parameter(3, 1, 0, "GR-55, &");
  display_parameter(3, 1, 1, " VG-99");
  delay(3000);
}

void clear_displays(){
  lcd1.clear();
  lcd2.clear();
  lcd3.clear();
}

void main_LCD_control()
{

}

void display_parameter(int lcd, int line, int pos, String message)
{
  if(pos>0) {pos=8; }; //if not at cursor position first character
  if(lcd==1 && message!=lcd1_previous_message){
  lcd1.home();
  lcd1.setCursor (pos, line);       // go to selected line and start of section
  lcd1.print("        ");           // Clear the 8 characters
  lcd1.setCursor (pos, line);       // go to selected line and start of section
  lcd1.print(message); 
  lcd1_previous_message=message; 
  };
  if(lcd==2 && message!=lcd2_previous_message){
  lcd2.home();
  lcd2.setCursor (pos, line);       // go to selected line and start of section
  lcd2.print("        ");           // Clear the 8 characters
  lcd2.setCursor (pos, line);       // go to selected line and start of section
  lcd2.print(message); 
  lcd2_previous_message=message; 
  };
  if(lcd==3 && message!=lcd3_previous_message){
  lcd3.home();
  lcd3.setCursor (pos, line);       // go to selected line and start of section
  lcd3.print("        ");           // Clear the 8 characters
  lcd3.setCursor (pos, line);       // go to selected line and start of section
  lcd3.print(message); 
  lcd3_previous_message=message; 
  };
}

void mode_display(){
  clear_displays();
  String msg="error";
  if(device_type == 1){
      if(device_mode == 1 || device_mode == 3){ msg=("  GP-10 PREAMP"); };
      if(device_mode == 2 || device_mode == 4){ msg=(" GP-10 EQUALIZER"); };
      mode_message(msg); 
      GP10_init();
  };
   if(device_type == 2){
      if(device_mode == 1 || device_mode == 3){ msg=("  GR-55 PREAMP"); };
      if(device_mode == 2 || device_mode == 4){ msg=(" GR-55 EQUALIZER"); };
      mode_message(msg); 
      GR55_init();
  };
   if(device_type == 3){
      if(device_mode == 1 || device_mode == 3){ msg=(" GT-100 PREAMP"); };
      if(device_mode == 2 || device_mode == 4){ msg=("GT-100 EQUALIZER"); };
      mode_message(msg); 
      GT100_init();
  };
   if(device_type == 4){
      if(device_mode == 1 || device_mode == 3){ msg=(" SY-300 OD/DS  "); };
      if(device_mode == 2 ){ msg=(" SY-300 MAIN EQ"); }; 
      if(device_mode == 4){ msg=(" SY-300 SUB EQ "); };
      mode_message(msg); 
      SY300_init();
  };
   if(device_type == 5){
      if(device_mode == 1){ msg=(" VG-99 PREAMP 1"); };
      if(device_mode == 2){ msg=(" VG-99 PREAMP 2"); };
      if(device_mode == 3){ msg=("VG99 EQUALIZER 1"); };
      if(device_mode == 4){ msg=("VG99 EQUALIZER 2"); }; 
      mode_message(msg);
      VG99_init();
  };
}

void mode_message(String msg){
  lcd1.print(msg);
  lcd2.print(msg);
  lcd3.print(msg);
  delay(1000);
}

