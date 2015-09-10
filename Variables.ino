
// this page has the common variables used between many devices.

void mid_q(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 126, 0, 5);
  String mid_q[] = {"0.5", "1", "2", "4", "8", "16"};
   display_parameter(lcd, line, pos, mid_q[value]);
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

void mid_freq(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 126, 0, 27);
  String freq[] = {"20.0Hz", "25.0Hz", "31.5Hz", "40.0Hz", "50.0Hz", "63.0Hz", "80.0Hz", "100Hz", "125Hz", "160Hz", "200Hz", "250Hz", "315Hz",
  "400Hz", "500Hz", "630Hz", "800HZ", "1.00kHz", "1.25kHz", "1.60kHz", "2.00kHz", "2.50kHz", "3.15kHz", "4.00kHz", "5.00kHz", "6.30kHz", "8.00kHz", "10.0kHz"};
  display_parameter(lcd, line, pos, freq[value]);
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

void knob20(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 126, -20, 20);
  display_parameter(lcd, line, pos, String(value)+" dB");
  label_delay(lcd, line, pos, label);
  prep_midi(address, value+20);
}

void knob100(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 126, 0, 100);                                                // this rescales the knob range 0~127 to a range of 0~100
  display_parameter(lcd, line, pos, value);
  label_delay(lcd, line, pos, label);                                                // label delay shows the parameter for 1.5 seconds then reverts back to the function label.
  prep_midi(address, value);                                                         // forward to address and value to 'Midi' for SysEx processing.
}

void knob50(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 126, 0, 100);
  display_parameter(lcd, line, pos, map(value, 0, 100, -50, 50));
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

void knob120(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 126, 0, 120);
  display_parameter(lcd, line, pos, value);
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

  void knob2000(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 126, 1, 2000);
  display_parameter(lcd, line, pos, value+String(" ms"));
  label_delay(lcd, line, pos, label);
  prep_3Byte(address, value);
}

  void knob3400(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 126, 1, 3374);
  display_parameter(lcd, line, pos, value+String(" ms"));
  label_delay(lcd, line, pos, label);
  prep_3Byte(address, value);
}

void knob07F(int lcd, int line, int pos, int value, String label, String address ){
  display_parameter(lcd, line, pos, map(value, 0, 126, 0, 100));
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

void knob17F(int lcd, int line, int pos, int value, String label, String address ){
  display_parameter(lcd, line, pos, map(value, 0, 126, -50, 50));
  label_delay(lcd, line, pos, label);
  if(value<1)value=1;
  prep_midi(address, value);
}

void cab_type(int lcd, int line, int pos, int value, String address ){
  value = map(value, 0, 126, 0, 8);
  String cab_type[] = {"Off", "Original", "1x8 open", "1x10open", "1x12open", "2x12open", "4x10encl", "4x12encl", "8x12encl"};
  display_parameter(lcd, line, pos, cab_type[value]);
  prep_midi(address, value);
}

void mic_pos(int lcd, int line, int pos, int value, String address ){
  value = map(value, 0, 126, 0, 10);
  String mic_pos[] = {"Centre", "1 cm", "2 cm", "3 cm", "4 cm", "5 cm", "6 cm", "7 cm", "8 cm", "9 cm", "10 cm", "over" };
  display_parameter(lcd, line, pos, mic_pos[value]);
  label_delay(lcd, line, pos, "Mic-Pos");
  prep_midi(address, value);
}

void gain_type(int lcd, int line, int pos, int value, String address ){
  value = map(value, 0, 126, 0, 2);
  String gain_type[] = {" Lo-Gain", " Md-Gain", " Hi-Gain"};
  display_parameter(lcd, line, pos, gain_type[value]);
  prep_midi(address, value);
}

void high_cut(int lcd, int line, int pos, int value, String address){
  value = map(value, 0, 126, 0, 14);
  String high_cut[] = {"630Hz", "800Hz", "1.00kHz", "1.25kHz", "1.60kHz", "2.00kHz", "2.50kHz", "3.15kHz", "4.00kHz", "6.00kHz", "6.30kHz", "8.00kHz", "10.0kHz", "12.5kHz", "Flat" };
  display_parameter(lcd, line, pos, high_cut[value]);
  label_delay(lcd, line, pos, "Hi-Cut");
  prep_midi(address, value);
}

void low_cut(int lcd, int line, int pos, int value, String address){
  value = map(value, 0, 126, 0, 17);
  String low_cut[] = {"Flat", "20.0Hz", "25.0Hz", "31.5Hz", "40.0Hz", "50.0Hz", "63.0Hz", "80.0Hz", "100Hz", "125Hz", "160Hz", "200Hz", "250Hz", "315Hz", "400Hz", "500Hz", "630Hz", "800HZ" };
  display_parameter(lcd, line, pos, low_cut[value]);
  label_delay(lcd, line, pos, "Lo-Cut");
  prep_midi(address, value);
}

void rv_time(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 126, 1, 100);
  String v = String(value);
  display_parameter(lcd, line, pos, String(value/10)+"."+v.remove(0,v.length()-1)+"s"); //cool way to convert a 1~100 string to display 0.1~10.0
  label_delay(lcd, line, pos, label);
  prep_midi(address, value-1);
}

void rotary20(int lcd, int line, int pos, int value, String label, String address ){
  if(value>40){ value=40; knob12_read=40; };
  if(value<0) { value=0;  knob12_read=0; };
  value = map(value, 0, 40, -20, 20);
  display_parameter(lcd, line, pos, String(value)+" dB");
  label_delay(lcd, line, pos, label);
  prep_midi(address, value+20);
}

  void rotary100(int lcd, int line, int pos, int value, String label, String address ){
 if(value>100) {value=100; knob12_read=100; };
 if(value<0) {value=0; knob12_read=0; };
  display_parameter(lcd, line, pos, value);
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

