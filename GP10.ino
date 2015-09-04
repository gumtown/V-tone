

void GP10_init(){
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

void GP10_data_change(int input_source, int value){
  if(device_mode == 1 || device_mode == 3){
  if(input_source == knob1) {GP10_amp_type(value); };
  if(input_source == knob2) {gain_type(1, 0, 1, value, "2000500A"); };
  if(input_source == knob3) {knob100(2, 0, 0, value, "Bass", "20005005"); };
  if(input_source == knob4) {knob100(2, 0, 1, value, "Middle", "20005006"); };
  if(input_source == knob5) {knob100(3, 0, 0, value, "Treble", "20005007"); };
  if(input_source == knob6) {knob100(3, 0, 1, value, "Presense", "20005008"); };
  if(input_source == knob7) {knob120(1, 1, 0, value, "Gain", "20005002"); };
  if(input_source == knob8) {cab_type(1, 1, 1, value, "2000500E"); };
  if(input_source == knob9) {mic_pos(2, 1, 0, value, "20005011"); };
  if(input_source == knob10) {knob100(2, 1, 1, value, "Mic-Levl", "20005012"); };
  if(input_source == knob11) {knob100(3, 1, 0, value, "SOLO", "2000500C"); };
  if(input_source == knob12) {knob100(3, 1, 1, value, "Level", "20005004"); };
  };
  if(device_mode == 2 || device_mode == 4){
  if(input_source == knob1) {knob20(1, 0, 0, value, "Lo-Gain", "20020001"); };
  if(input_source == knob2) {mid_freq(1, 0, 1, value, "HiMidFrq", "20020006"); };
  if(input_source == knob3) {mid_q(2, 0, 0, value, "HiMid-Q", "20020007"); };
  if(input_source == knob4) {knob20(2, 0, 1, value, "HiMid-Gn", "20020005"); };
  if(input_source == knob5) {knob20(3, 0, 0, value, "Hi-Gain", "20020008"); };
 // if(input_source == knob6) {character(3, 0, 1, value, "Charactr", "061D"); };
  if(input_source == knob7) {GP10_low_cut(value); };
  if(input_source == knob8) {mid_freq(1, 1, 1, value, "LoMidFrq", "20020003"); };
  if(input_source == knob9) {mid_q(2, 1, 0, value, "LoMid-Q", "20020004"); };
  if(input_source == knob10) {knob20(2, 1, 1, value, "LoMid-Gn", "20020002"); };
  if(input_source == knob11) {GP10_high_cut(value); };
  if(input_source == knob12) {knob20(3, 1, 1, value, "Level", "2002000A"); };
  };
}

void GP10_amp_type(int value){
  value = map(value, 0, 127, 0, 29);
  String amp[] = {"Ntrl Cln", "Full Rng", "CombCnch", "Stk Cnch", "HiGn Stk", "PowerDrv", "ExtremLd", "Core Mtl", "JC-120", "Cln Twin", "Pro Cnch", "Tweed", "Dlx Cnch",
  "VO Drive", "VO Lead", "MatchDrv", "BG Lead", "BG Drive", "MS1959 I", "MS1959II", "RFierVnt", "RFierMdn", "TAmpLead", "SLDN", "5150 Drv", "BognerUB", "OrangeRR", "Bass Cln", "BassCnch", "BassHiGn"};
  display_parameter(1, 0, 0, amp[value]);
  prep_midi("20005001", value);
}

void GP10_low_cut(int value){
  value = map(value, 0, 127, 0, 17);
  String low_cut[] = {"Flat", "20.0Hz", "25.0Hz", "31.5Hz", "40.0Hz", "50.0Hz", "63.0Hz", "80.0Hz", "100Hz", "125Hz", "160Hz", "200Hz", "250Hz", "315Hz", "400Hz", "500Hz", "630Hz", "800HZ" };
  display_parameter(1, 1, 0, low_cut[value]);
  label_delay(1, 1, 0, "Lo-Cut");
  prep_midi("20020000", value);
}

void GP10_high_cut(int value){
  value = map(value, 0, 127, 0, 14);
  String high_cut[] = {"630Hz", "800Hz", "1.00kHz", "1.25kHz", "1.60kHz", "2.00kHz", "2.50kHz", "3.15kHz", "4.00kHz", "6.00kHz", "6.30kHz", "8.00kHz", "10.0kHz", "12.5kHz", "Flat" };
  display_parameter(3, 1, 0, high_cut[value]);
  label_delay(3, 1, 0, "Hi-Cut");
  prep_midi("20020009", value);
}





