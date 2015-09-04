

void GR55_init(){
  clear_displays();
  if(device_mode == 1 || device_mode == 3){
  lcd1.print("Amp-type Gain-sw"); 
  display_parameter(1, 1, 0, "Gain"); 
  display_parameter(1, 1, 1, "Cab-type");
  lcd2.print("Bass    Middle");  
  display_parameter(2, 1, 0, "Mic-Pos");
  display_parameter(2, 1, 1, "Mic-Levl");  
  lcd3.print("Treble  Presense"); 
  display_parameter(3, 1, 0, "Solo-Lvl");
  display_parameter(3, 1, 1, " Level");
  };
  if(device_mode == 2 || device_mode == 4){
  lcd1.print("Lo-Gain HiMidFrq"); 
  display_parameter(1, 1, 0, "Lo-Cut"); 
  display_parameter(1, 1, 1, "LoMidFrq");
  lcd2.print("HiMid-Q HiMid-Gn");  
  display_parameter(2, 1, 0, "LoMid-Q");
  display_parameter(2, 1, 1, "LoMid-Gn");  
  lcd3.print("Hi-Gain Charactr"); 
  display_parameter(3, 1, 0, "Hi-Cut");
  display_parameter(3, 1, 1, "Level");
  };
}

void GR55_data_change(int input_source, int value){
  if(device_mode <= 1 || device_mode == 3){
  if(input_source == knob1) {amp_type(value); };
  if(input_source == knob2) {gain_type(1, 0, 1, value, "18000704"); };
  if(input_source == knob3) {knob100(2, 0, 0, value, "Bass", "18000707"); };
  if(input_source == knob4) {knob100(2, 0, 1, value, "Middle", "18000708"); };
  if(input_source == knob5) {knob100(3, 0, 0, value, "Treble", "18000709"); };
  if(input_source == knob6) {knob100(3, 0, 1, value, "Presense", "1800070A"); };
  if(input_source == knob7) {knob120(1, 1, 0, value, "Gain", "18000702"); };
  if(input_source == knob8) {cab_type(1, 1, 1, value, "1800070C"); };
  if(input_source == knob9) {mic_pos(2, 1, 0, value, "1800070F"); };
  if(input_source == knob10) {knob100(2, 1, 1, value, "Mic-Levl", "18000710"); };
  if(input_source == knob11) {knob100(3, 1, 0, value, "SOLO", "18000706"); };
  if(input_source == knob12) {knob100(3, 1, 1, value, "Level", "18000703"); };
  };
  if(device_mode == 2 || device_mode >= 4){
  if(input_source == knob1) {knob20(1, 0, 0, value, "Lo-Gain", "18000613"); };
  if(input_source == knob2) {mid_freq(1, 0, 1, value, "HiMidFrq", "18000617"); };
  if(input_source == knob3) {mid_q(2, 0, 0, value, "HiMid-Q", "18000618"); };
  if(input_source == knob4) {knob20(2, 0, 1, value, "HiMid-Gn", "18000619"); };
  if(input_source == knob5) {knob20(3, 0, 0, value, "Hi-Gain", "1800061B"); };
  if(input_source == knob6) {character(3, 0, 1, value, "Charactr", "1800061D"); };
  if(input_source == knob7) {low_cut(value); };
  if(input_source == knob8) {mid_freq(1, 1, 1, value, "LoMidFrq", "18000614"); };
  if(input_source == knob9) {mid_q(2, 1, 0, value, "LoMid-Q", "18000615"); };
  if(input_source == knob10) {knob20(2, 1, 1, value, "LoMid-Gn", "18000616"); };
  if(input_source == knob11) {high_cut(value); };
  if(input_source == knob12) {knob20(3, 1, 1, value, "Level", "18000703"); };
  };
}

void amp_type(int value){
  value = map(value, 0, 127, 0, 41);
  String amp[] = {"Boss Cln", "JC-120", "Jazz Com", "Full Rng", "Cln Twin", "Pro Cnch", "Tweed", "Dlx Cnch", "BossCnch", "Blues", "WildCnch", 
  "Stk Cnch", "VO Drive", "VO Lead", "VO Clean", "MatchDrv", "FatMatch", "Match Ld", "BG Lead", "BG Drive", "BG Rhytm", "MS1959 I", "MS1959II", "MS HiGn", "MS Scoop", "RFierVnt", 
  "RFierMdn", "RFierCln", "TAmpLead", "TAmpCnch", "TAmp Cln", "Boss Drv", "SLDN", "Lead Stk", "Hvy Lead", "Boss Mtl", "5150 Drv",
  "Mtl Lead", "EdgeLead", "Bass Cln", "BassCnch", "BassHiGn"};
  display_parameter(1, 0, 0, amp[value]);
  prep_midi("18000701", value);
}

void low_cut(int value){
  value = map(value, 0, 127, 0, 10);
  String low_cut[] = {"Flat", "55.0Hz", "110Hz", "165Hz", "200Hz", "280Hz", "340Hz", "400Hz", "500Hz", "630Hz", "800HZ" };
  display_parameter(1, 1, 0, low_cut[value]);
  label_delay(1, 1, 0, "Lo-Cut");
  prep_midi("18000612", value);
}

void high_cut(int value){
  value = map(value, 0, 127, 0, 9);
  String high_cut[] = {"700Hz", "1.00kHz", "1.40kHz", "2.00kHz", "3.00kHz", "4.00kHz", "6.00kHz", "8.00kHz", "11.0kHz", "Flat" };
  display_parameter(3, 1, 0, high_cut[value]);
  label_delay(3, 1, 0, "Hi-Cut");
  prep_midi("1800061A", value);
}

void character(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 127, 0, 6);
  String character[] = {"-3", "-2", "-1", "0", "+1", "+2", "+3"};
   display_parameter(lcd, line, pos, character[value]);
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}



