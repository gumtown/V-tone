#include <string.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

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
int device_type = 2;
int device_mode = 1;
int knob1=A0;
int knob2=A1;
int knob3=A2;
int knob4=A3;
int knob5=A6;
int knob6=A7;
int knob7=A8;
int knob8=A9;
int knob9=A11;
int knob10=A10;
int knob11=A12;
int knob12=A12;
unsigned long currentTime;
unsigned long loopTime;
bool display_flag = false;
const int pin_A = 2;  // pin D2
const int pin_B = 3;  // pin D3
int encoder_pb = 4; //pin D4
int red_pb = 5; // pin 5
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;
int enc_val = 0;
int pb_val = 0;
int previous_value=0;

void setup() {
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  pinMode(encoder_pb, INPUT);
  pinMode(red_pb, INPUT);
  currentTime = millis();
  loopTime = currentTime;
  Serial.begin(115200);
  setup_variables();
  setup_LCD_control();
  setup_MIDI_common();
  mode_display();

}

void loop() {
 /*   if(currentTime >= (loopTime + 5)){
    // 5ms since last check of encoder = 200Hz  
    encoder_A = digitalRead(pin_A);    // Read encoder pins
    encoder_B = digitalRead(pin_B);   
    if((!encoder_A) && (encoder_A_prev)){
      // A has gone from high to low 
      if(encoder_B) {
        // B is high so clockwise
        // increase the brightness, dont go over 255
        //if(brightness + fadeAmount <= 255) brightness += fadeAmount;               
      }   
      else {
        // B is low so counter-clockwise      
        // decrease the brightness, dont go below 0
        //if(brightness - fadeAmount >= 0) brightness -= fadeAmount;               
      }   

    }   
    encoder_A_prev = encoder_A;     // Store value of A for next time    
    
    // set the brightness of pin 9:
    //analogWrite(9, brightness);   
   
    loopTime = currentTime;  // Updates loopTime
  }*/
  
  enc_val=digitalRead(encoder_pb);
  if(enc_val<1) { 
    while(enc_val<1){delay(100); enc_val=digitalRead(encoder_pb); };
    ++device_mode; 
    if(device_mode>4){ device_mode=1; };
    Serial.print("device mode = "+String(device_mode)); Serial.println();    
    mode_display(); 
    };
    
  pb_val=digitalRead(red_pb);
  if(pb_val<1) { 
    while(pb_val<1){delay(100); pb_val=digitalRead(red_pb); };
    ++device_type; 
    if(device_type>5){ device_type = 1; };
    Serial.print("device type = "+String(device_type)); Serial.println();    
    mode_display(); 
    };
  
  read_input();
  process_analog();
  delay(10);
  currentTime = millis();
  if((currentTime >= (loopTime + 1500)) && display_flag){
  if(device_type == 1) {GP10_init(); };
  if(device_type == 2) {GR55_init(); };
  if(device_type == 3) {GT100_init(); };
  if(device_type == 4) {SY300_init(); };
  if(device_type == 5) {VG99_init(); };
  display_flag=false;
  loopTime = currentTime;
  };
}

void label_delay(int lcd, int line, int pos, String label){

  //display_parameter(lcd, line, pos, label);
  loopTime = currentTime;
  display_flag=true;
}

void data_change(int input_source, int value){
  if(device_type <= 1) {GP10_data_change(input_source, value); };
  if(device_type == 2) {GR55_data_change(input_source, value); };
  if(device_type == 3) {GT100_data_change(input_source, value); };
  if(device_type == 4) {SY300_data_change(input_source, value); };
  if(device_type >= 5) {VG99_data_change(input_source, value); };
}

void menu(){
 back:
  delay(300);

  lcd1.clear();
  lcd2.clear();
  lcd3.clear();
  
  lcd3.print("MENU:  select"); 

  display_parameter(3, 1, 1, "<GR-55>");
  enc_val=digitalRead(encoder_pb);
  if(enc_val==HIGH) {enc_val=0; GR55_init(); return; }else{ goto back; };
}


