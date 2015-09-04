

void mid_q(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 127, 0, 5);
  String mid_q[] = {"0.5", "1", "2", "4", "8", "16"};
   display_parameter(lcd, line, pos, mid_q[value]);
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

void mid_freq(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 127, 0, 27);
  String freq[] = {"20.0Hz", "25.0Hz", "31.5Hz", "40.0Hz", "50.0Hz", "63.0Hz", "80.0Hz", "100Hz", "125Hz", "160Hz", "200Hz", "250Hz", "315Hz",
  "400Hz", "500Hz", "630Hz", "800HZ", "1.00kHz", "1.25kHz", "1.60kHz", "2.00kHz", "2.50kHz", "3.15kHz", "4.00kHz", "5.00kHz", "6.30kHz", "8.00kHz", "10.0kHz"};
  display_parameter(lcd, line, pos, freq[value]);
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

void knob20(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 127, -20, 20);
  display_parameter(lcd, line, pos, String(value)+" dB");
  label_delay(lcd, line, pos, label);
  prep_midi(address, value+20);
}

void knob100(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 127, 0, 100);
  display_parameter(lcd, line, pos, value);
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

void knob120(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 127, 0, 120);
  display_parameter(lcd, line, pos, value);
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

void cab_type(int lcd, int line, int pos, int value, String address ){
  value = map(value, 0, 127, 0, 8);
  String cab_type[] = {"Off", "Original", "1x8 open", "1x10open", "1x12open", "2x12open", "4x10encl", "4x12encl", "8x12encl"};
  display_parameter(lcd, line, pos, cab_type[value]);
  prep_midi(address, value);
}

void mic_pos(int lcd, int line, int pos, int value, String address ){
  value = map(value, 0, 127, 0, 10);
  String mic_pos[] = {"Centre", "1 cm", "2 cm", "3 cm", "4 cm", "5 cm", "6 cm", "7 cm", "8 cm", "9 cm", "10 cm", "over" };
  display_parameter(lcd, line, pos, mic_pos[value]);
  label_delay(2, 1, 0, "Mic-Pos");
  prep_midi(address, value);
}

void gain_type(int lcd, int line, int pos, int value, String address ){
  value = map(value, 0, 127, 0, 2);
  String gain_type[] = {" Lo-Gain", " Md-Gain", " Hi-Gain"};
  display_parameter(lcd, line, pos, gain_type[value]);
  prep_midi(address, value);
}

