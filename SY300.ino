


void SY300_init(){
  clear_displays();
  if(device_mode == 1 || device_mode == 3){
  display_parameter(1, 0, 0, Amptype); //(lcd, line, position, label)
  display_parameter(1, 0, 1, Gainsw);
  display_parameter(1, 1, 0, Gain); 
  display_parameter(1, 1, 1, Cabtype);

  display_parameter(2, 0, 0, Bass);
  display_parameter(2, 0, 1, Middle);   
  display_parameter(2, 1, 0, Micpos);
  display_parameter(2, 1, 1, Miclevl);  

  display_parameter(3, 0, 0, Treble);
  display_parameter(3, 0, 1, Presense); 
  display_parameter(3, 1, 0, Sololvl);
  display_parameter(3, 1, 1, Level);
  };
  if(device_mode == 2 || device_mode == 4){
  display_parameter(1, 0, 0, LoGain); 
  display_parameter(1, 0, 1, HiMidFrq); 
  display_parameter(1, 1, 0, LoCut); 
  display_parameter(1, 1, 1, LoMidFrq);
 
  display_parameter(2, 0, 0, HiMidQ);
  display_parameter(2, 0, 1, HiMidGn);
  display_parameter(2, 1, 0, LoMidQ);
  display_parameter(2, 1, 1, LoMidGn);  
 
  display_parameter(3, 0, 0, HiGain);
  //display_parameter(3, 0, 1, "Charactr");
  display_parameter(3, 1, 0, HiCut);
  display_parameter(3, 1, 1, Level);
  };
}

void SY300_data_change(int input_source, int value){
  if(device_mode == 1 || device_mode == 3){
  if(input_source == 1) {SY300_amp_type(value); };
  if(input_source == 2) {gain_type(1, 0, 1, value, "0704"); };
  if(input_source == 3) {knob100(2, 0, 0, value, Bass, "0707"); };
  if(input_source == 4) {knob100(2, 0, 1, value, Middle, "0708"); };
  if(input_source == 5) {knob100(3, 0, 0, value, Treble, "0709"); };
  if(input_source == 6) {knob100(3, 0, 1, value, Presense, "070A"); };
  if(input_source == 7) {knob120(1, 1, 0, value, Gain, "0702"); };
  if(input_source == 8) {cab_type(1, 1, 1, value, "070C"); };
  if(input_source == 9) {mic_pos(2, 1, 0, value, "070F"); };
  if(input_source == 10) {knob100(2, 1, 1, value, Miclevl, "0710"); };
  if(input_source == 11) {knob100(3, 1, 0, value, Sololvl, "0706"); };
  if(input_source == 12) {knob100(3, 1, 12, value, Level, "0703"); };
  };
  if(device_mode == 2 || device_mode == 4){
  if(input_source == 1) {knob20(1, 0, 0, value, LoGain, "0613"); };
  if(input_source == 2) {mid_freq(1, 0, 1, value, HiMidFrq, "0617"); };
  if(input_source == 3) {mid_q(2, 0, 0, value, HiMidQ, "0618"); };
  if(input_source == 4) {knob20(2, 0, 1, value, HiMidGn, "0619"); };
  if(input_source == 5) {knob20(3, 0, 0, value, HiGain, "061B"); };
  //if(input_source == 6) {character(3, 0, 1, value, "Charactr", "061D"); };
  //if(input_source == 7) {GP10_low_cut(value); };
  if(input_source == 8) {mid_freq(1, 1, 1, value, LoMidFrq, "0614"); };
  if(input_source == 9) {mid_q(2, 1, 0, value, LoMidQ, "0615"); };
  if(input_source == 10) {knob20(2, 1, 1, value, LoMidGn, "0616"); };
//  if(input_source == 11) {GP10_high_cut(value); };
  if(input_source == 12) {knob20(3, 1, 10, value, Level, "0703"); };
  };
}

void SY300_amp_type(int value){
  value = map(value, 0, 127, 0, 41);
  String amp[] = {"Ntrl Cln", "Full Rng", "CombCnch" "Stk Cnch", "HiGn Stk", "PowerDrv", "ExtrmLead" 
  "Core Mtl", "JC-120", "Cln Twin", "Pro Cnch", "Tweed", "Dlx Cnch",
  "VO Drive", "VO Lead", "MatchDrv", "BG Lead", "BG Drive", "MS1959 I", "MS1959II", "RFierVnt", 
  "RFierMdn", "TAmpLead", "SLDN", "5150 Drv",
  "BognerUB", "OrangeRR", "Bass Cln", "BassCnch", "BassHiGn"};
  display_parameter(1, 0, 0, amp[value]);
  prep_midi("0701", value);
}





