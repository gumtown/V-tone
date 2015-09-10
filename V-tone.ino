
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Button.h>
#include <TicksPerSecond.h>
#include <RotaryEncoderAcelleration.h>


int device_type = 2;
int device_mode = 1;
int menu_mode = 0;
unsigned long currentTime;
unsigned long loopTime;
bool display_flag = false;
const int rotorPinA = 2;
const int rotorPinB = 3;
RotaryEncoderAcelleration rotor;
long last_value = 5000;
int encoder_pb = 4;           //pin D4
int red_pb = 5;               // pin 5
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev = 0;
int rotary1_val = 0;
int enc_val = 0;
int pb_val = 0;
String previous_value = 0;
int selection = 0;
String Level = String("   Level");
String Bass = String("Bass");
String Middle = String("Middle");
String Treble = String("Treble");
String Presense = String("Presense");
String Gain = String("Gain");
String Gainsw = String(" Gain sw");
String Amptype = String("Amp-type");
String Cabtype = String("Cab-type");
String Micpos = String("Mic-pos");
String Miclevl = String("Mic-levl");
String Sololvl = String("Solo-lvl");
String LoCut = String("Lo-Cut");
String LoGain = String("Lo-Gain");
String LoMidFrq = String("LoMidFrq");
String LoMidQ = String("LoMid-Q");
String LoMidGn = String("LoMid-Gn");
String HiCut = String("Hi-Cut");
String HiGain = String("Hi-Gain");
String HiMidFrq = String("HiMidFrq");
String HiMidQ = String("HiMid-Q");
String HiMidGn = String("HiMid-Gn");

void setup() {
  rotor.initialize(rotorPinA, rotorPinB);
  rotor.setMinMax(0, 10000);
  rotor.setPosition(5000);
  attachInterrupt(rotorPinA, UpdateRotor, CHANGE);
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

void UpdateRotor() {
  rotor.update();
}

void loop() {

  if (rotor.getPosition() != last_value) {
    //Serial.println(rotor.getPosition());
    last_value = rotor.getPosition();
  };
  read_input();
  process_analog();
 
/*if(menu_mode>0){  
  if(menu_mode==1){
  clear_displays();
  display_parameter(1, 0, 0, "SETUP MENU:");
  display_parameter(1, 1, 0, "< exit");
  display_parameter(2, 0, 0, "choose units");
  display_parameter(3, 0, 0, "<GR-55> ");
  menu_mode=2;
  while(pb_val<1){pb_val = digitalRead(red_pb); };
  };

    delay(100);
    read_input();
    if (pb_val < 1)menu_mode=0;
    if (enc_val < 1) {
      if (selection == 0) {
        selection = 1;
      } else {
        selection = 0;
      };
    };
    if (selection == 0) {
      display_parameter(3, 0, 1, "<No>    ");
    };
    if (selection==1) {
      display_parameter(3, 0, 1, "<Yes>   ");
    };
    if(menu_mode==0){ mode_display(); };
};
  //
*/
  rotor.setPosition(5000);
  last_value = 5000;
  delay(10);
  currentTime = millis();
  if ((currentTime >= (loopTime + 1500)) && display_flag) {  // if a parameter was changed and displayed, revert back to parameter names after 1.5 seconds of no knob activity.
    init_display();
    display_flag = false;
    loopTime = currentTime;
  };
 
}

void init_display() {
  if (device_type == 1) {
    GP10_init();
  };
  if (device_type == 2) {
    GR55_init();
  };
  if (device_type == 3) {
    GT100_init();
  };
  if (device_type == 4) {
    SY300_init();
  };
  if (device_type == 5) {
    VG99_init();
  };
};

void label_delay(int lcd, int line, int pos, String label) {

  //display_parameter(lcd, line, pos, label);
  loopTime = currentTime;
  display_flag = true;
}

void data_change(int input_source, int value) {
  if (device_type <= 1) {
    GP10_data_change(input_source, value);
  };
  if (device_type == 2) {
    GR55_data_change(input_source, value);
  };
  if (device_type == 3) {
    GT100_data_change(input_source, value);
  };
  if (device_type == 4) {
    SY300_data_change(input_source, value);
  };
  if (device_type >= 5) {
    VG99_data_change(input_source, value);
  };
}



