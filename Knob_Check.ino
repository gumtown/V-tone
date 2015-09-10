

int knob1 = A0;
int knob2 = A1;
int knob3 = A2;
int knob4 = A3;
int knob5 = A6;
int knob6 = A7;
int knob7 = A8;
int knob8 = A9;
int knob9 = A11;
int knob10 = A10;
int knob11 = A12;
//int knob12 = A12;



int knob1_read;
int knob2_read;
int knob3_read;
int knob4_read;
int knob5_read;
int knob6_read;
int knob7_read;
int knob8_read;
int knob9_read;
int knob10_read;
int knob11_read;
int knob12_read;

int knob1_previous;
int knob2_previous;
int knob3_previous;
int knob4_previous;
int knob5_previous;
int knob6_previous;
int knob7_previous;
int knob8_previous;
int knob9_previous;
int knob10_previous;
int knob11_previous;
int knob12_previous;

void setup_variables() {
  read_input();
  knob1_previous = knob1_read;
  knob2_previous = knob2_read;
  knob3_previous = knob3_read;
  knob4_previous = knob4_read;
  knob5_previous = knob5_read;
  knob6_previous = knob6_read;
  knob7_previous = knob7_read;
  knob8_previous = knob8_read;
  knob9_previous = knob9_read;
  knob10_previous = knob10_read;
  knob11_previous = knob11_read;
  knob12_previous = knob12_read;
}

void read_input() {
  // ************ Read the A/D converter values for each knob ********************
  knob1_read = analogRead(knob1) / 8;
  knob2_read = analogRead(knob2) / 8;
  knob3_read = analogRead(knob3) / 8;
  knob4_read = analogRead(knob4) / 8;
  knob5_read = analogRead(knob5) / 8;
  knob6_read = analogRead(knob6) / 8;
  knob7_read = analogRead(knob7) / 8;
  knob8_read = analogRead(knob8) / 8;
  knob9_read = analogRead(knob9) / 8;
  knob10_read = analogRead(knob10) / 8;
  knob11_read = analogRead(knob11) / 8;
 // knob12_read = analogRead(knob12) / 8;
 
 // ************ Read the current position of the Rotor encoder ******************
  knob12_read = knob12_read + rotor.getPosition() - 5000;

    enc_val = digitalRead(encoder_pb);
    pb_val = digitalRead(red_pb);  
// ************ Read the right side push button to set the parameter page ************
  if (enc_val < 1) {
    while (enc_val < 1) {
      delay(100);
      enc_val = digitalRead(encoder_pb);
    };
    ++device_mode;                           // increment parameter pages. Preamp, EQ, etc
    if (device_mode > 4) {
      device_mode = 1;
    };
    Serial.print("device mode = " + String(device_mode)); Serial.println();
    mode_display();
  };
// ************* Read the left side push button to set the Device Type ***************
  if (pb_val < 1) {
    int t=0;
    while (pb_val < 1) {
      delay(100);
      pb_val = digitalRead(red_pb);
      if(t>10){menu_mode=1; t=0; goto fuc;};
      ++t;
    };
    ++device_type;                        // increment device type. GP-10, GR-55, etc
    if (device_type > 5) {
      device_type = 1;
    };
    Serial.print("device type = " + String(device_type)); Serial.println();
    mode_display();   
    fuc:;
  };



};




void process_analog() {

 // determine if a value has changed from it's previous value ********
 // if it has changed then forward the value for processing to data_change() ********
 
  if (knob1_read/2 != knob1_previous/2) {
    knob1_previous = knob1_read;
    data_change(1, knob1_read);
  };
  if (knob2_read/2 != knob2_previous/2) { 
    knob2_previous = knob2_read;
    data_change(2, knob2_read);
  };
  if (knob3_read/2 != knob3_previous/2) {
    knob3_previous = knob3_read;
    data_change(3, knob3_read);
  };
  if (knob4_read/2 != knob4_previous/2) {
    knob4_previous = knob4_read;
    data_change(4, knob4_read);
  };
  if (knob5_read/2 != knob5_previous/2) {
    knob5_previous = knob5_read;
    data_change(5, knob5_read);
  };
  if (knob6_read/2 != knob6_previous/2) {
    knob6_previous = knob6_read;
    data_change(6, knob6_read);
  };
  if (knob7_read/2 != knob7_previous/2) {
    knob7_previous = knob7_read;
    data_change(7, knob7_read);
  };
  if (knob8_read/2 != knob8_previous/2) {
    knob8_previous = knob8_read;
    data_change(8, knob8_read);
  };
  if (knob9_read/2 != knob9_previous/2) {
    knob9_previous = knob9_read;
    data_change(9, knob9_read);
  };
  if (knob10_read/2 != knob10_previous/2) {
    knob10_previous = knob10_read;
    data_change(10, knob10_read);
  };
  if (knob11_read/2 != knob11_previous/2) {
    knob11_previous = knob11_read;
    data_change(11, knob11_read);
  };
  if (knob12_read != knob12_previous) {
    knob12_previous = knob12_read;
    data_change(12, knob12_read);
  };
}
