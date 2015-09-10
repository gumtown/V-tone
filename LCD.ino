
// ***************************** Hardware settings *****************************
#define I2C_ADDR1    0x27 // LCD1 Address [A0=open   A1=open   A2=open]
#define I2C_ADDR2    0x23 // LCD2 Address [A0=closed A1=open   A2=open]
#define I2C_ADDR3    0x25 // LCD3 Address [A0=open   A1=closed A2=open]
#define BACKLIGHT_PIN 3
#define EN_PIN  2
#define RW_PIN  1
#define RS_PIN  0
#define D4_PIN  4
#define D5_PIN  5
#define D6_PIN  6
#define D7_PIN  7

LiquidCrystal_I2C  lcd1(I2C_ADDR1, EN_PIN, RW_PIN, RS_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);
LiquidCrystal_I2C  lcd2(I2C_ADDR2, EN_PIN, RW_PIN, RS_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);
LiquidCrystal_I2C  lcd3(I2C_ADDR3, EN_PIN, RW_PIN, RS_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

// define custom character set (gliphs)
byte custom_0[8] = { 0b01111, 0b11111, 0b11111, 0b11111, 0b00011, 0b00011, 0b00001, 0b00000 };
byte custom_1[8] = { 0b00000, 0b10000, 0b11000, 0b11000, 0b11100, 0b11100, 0b11110, 0b11110 };
byte custom_2[8] = { 0b00000, 0b00001, 0b00011, 0b00011, 0b00111, 0b00111, 0b01111, 0b01111 };
byte custom_3[8] = { 0b11110, 0b11111, 0b11111, 0b11110, 0b11000, 0b11000, 0b10000, 0b00000 };
byte custom_4[8] = { 0b11110, 0b11110, 0b01110, 0b01110, 0b00111, 0b00111, 0b00011, 0b00001 };
byte custom_5[8] = { 0b01111, 0b01111, 0b01110, 0b01110, 0b11100, 0b11100, 0b11000, 0b10000 };
byte custom_6[8] = { 0b11111, 0b11111, 0b11111, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000 };
byte custom_7[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111 };
byte custom_8[8] = { 0b00001, 0b00011, 0b00111, 0b00111, 0b00111, 0b00111, 0b00111, 0b00111 };
byte custom_9[8] = { 0b00111, 0b00111, 0b00111, 0b00111, 0b00111, 0b00111, 0b00011, 0b00001 };
byte custom_A[8] = { 0b10000, 0b11000, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100 };
byte custom_B[8] = { 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11000, 0b10000 };
byte custom_C[8] = { 0b11111, 0b11111, 0b11111, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111 };
byte custom_D[8] = { 0b01110, 0b11111, 0b10001, 0b10111, 0b10111, 0b10001, 0b11111, 0b01110 };

String lcd1_previous_message;
String lcd2_previous_message;
String lcd3_previous_message;
String clear_8char = String("        ");


void setup_LCD_control()
{

  //lcd1.createChar(0, smiley);
  
  lcd1.begin (16, 2); //  LCD1 is 16x2
  lcd2.begin (16, 2); //  LCD2 is 16x2
  lcd3.begin (16, 2); //  LCD3 is 16x2

  lcd1.createChar(0, custom_0);  // load custom characters in LCD CGRAM
  lcd1.createChar(1, custom_1);
  lcd1.createChar(2, custom_2);
  lcd1.createChar(3, custom_3);
  lcd1.createChar(4, custom_4);
  lcd1.createChar(5, custom_5);
  lcd1.createChar(6, custom_6);
  lcd1.createChar(7, custom_D);
  
  lcd2.createChar(0, custom_6);
  lcd2.createChar(1, custom_7);
  lcd2.createChar(2, custom_8);
  lcd2.createChar(3, custom_9);
  lcd2.createChar(4, custom_A);
  lcd2.createChar(5, custom_B);
  lcd2.createChar(6, custom_C);
  lcd2.createChar(7, custom_1);

  lcd1.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd1.setBacklight(HIGH);
  lcd1.home (); // go home
  lcd2.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd2.setBacklight(HIGH);
  lcd2.home (); // go home
  lcd3.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd3.setBacklight(HIGH);
  lcd3.home (); // go home
  lcd1.write(byte(0));                  // Show LCD1 startup  Vtone logo
  lcd1.write(1);
  lcd1.write(2);
  lcd1.write(3); 
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.write(byte(6));
  lcd1.setCursor (0, 1);
  lcd1.write(254);                  
  lcd1.write(4);
  lcd1.write(5);
  lcd1.write(254);
  
  lcd2.setCursor (5, 0);  //position 5 line 1
  lcd2.write(byte(0));    //T
  lcd2.write(255);        //T
  lcd2.write(byte(0));    //T
  lcd2.write(2);          //O
  lcd2.write(byte(0));    //O
  lcd2.write(4);          //O
  lcd2.write(2);          //N         
  lcd2.write(7);          //N
  lcd2.write(4);          //N
  lcd2.write(255);        //E
  lcd2.write(6);          //E
  
  lcd2.setCursor (5, 1);  //position 5 line 2
  lcd2.write(254);        // bottom half of the TONE text
  lcd2.write(255);
  lcd2.write(254); 
  lcd2.write(3);
  lcd2.write(1);
  lcd2.write(5);  
  lcd2.write(3);
  lcd2.write(254);
  lcd2.write(5);  
  lcd2.write(255);
  lcd2.write(1);

  for(int scr=0; scr<4; ++scr){
    lcd1.scrollDisplayRight();  // nice little scrolling animation :)
    delay(50);
    lcd1.scrollDisplayRight();
    delay(50);
    lcd2.scrollDisplayLeft();
    delay(50);
    lcd1.scrollDisplayRight();
    delay(50);
  };
  lcd2.scrollDisplayLeft();
  
  lcd1.setCursor (6, 0);
  lcd1.write(7);
  lcd1.print(" 2015");
  display_parameter(1, 1, 6, "by Gumtown"); 
  lcd3.print("a midi controler");         
  //display_parameter(2, 1, 0, "for the");
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
  int half=pos; 
  if(half>0) half=8;
  if(pos==1) {pos=8; };              //if not at first character position , then start half way across the display
  if(lcd==1 && message!=lcd1_previous_message){
  lcd1.home();
  lcd1.setCursor (half, line);       // go to selected line and start of section
  lcd1.print(clear_8char);           // Clear the 8 characters
  lcd1.setCursor (pos, line);       // go to selected line and start of section
  lcd1.print(message); 
  lcd1_previous_message=message; 
  };
  if(lcd==2 && message!=lcd2_previous_message){
  lcd2.home();
  lcd2.setCursor (half, line);       // go to selected line and start of section
  lcd2.print(clear_8char);           // Clear the 8 characters
  lcd2.setCursor (pos, line);       // go to selected line and start of section
  lcd2.print(message); 
  lcd2_previous_message=message; 
  };
  if(lcd==3 && message!=lcd3_previous_message){
  lcd3.home();
  lcd3.setCursor (half, line);       // go to selected line and start of section
  lcd3.print(clear_8char);           // Clear the 8 characters
  lcd3.setCursor (pos, line);       // go to selected line and start of section
  lcd3.print(message); 
  lcd3_previous_message=message; 
  };
}

void mode_display(){
  clear_displays();
  String msg="error";
  if(device_type == 1){
      if(device_mode == 1){ msg=("  GP-10 PREAMP"); };
      if(device_mode == 2){ msg=(" GP-10 EQ"); };
      if(device_mode == 3){ msg=(" GP-10 Effects"); };
      if(device_mode == 4){ msg=("GP-10 Model/Syn"); };
      mode_message(msg); 
      GP10_init();
  };
   if(device_type == 2){
      if(device_mode == 1 ){ msg=("  GR-55 PREAMP"); };
      if(device_mode == 2 ){ msg=(" GR-55 EQ"); };
      if(device_mode == 3 ){ msg=(" GR-55 Effects"); };
      if(device_mode == 4 ){ msg=(" GR-55 Mix/SYNTH"); };
      mode_message(msg); 
      GR55_init();
  };
   if(device_type == 3){
      if(device_mode == 1 || device_mode == 3){ msg=(" GT-100 PREAMP"); };
      if(device_mode == 2 || device_mode == 4){ msg=("GT-100 EQ"); };
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
      if(device_mode == 3){ msg=("VG99 EQ 1"); };
      if(device_mode == 4){ msg=("VG99 EQ 2"); }; 
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

