

void GR55_init(){
  clear_displays();
  if(device_mode == 1){  //amp/cab
  display_parameter(1, 0, 0, Amptype); //(lcd, line, position, label)
  display_parameter(1, 0, 1, Gainsw);
  display_parameter(2, 0, 0, Bass);
  display_parameter(2, 0, 1, Middle); 
  display_parameter(3, 0, 0, Treble);
  display_parameter(3, 0, 1, Presense);
  
  display_parameter(1, 1, 0, Gain); 
  display_parameter(1, 1, 1, Cabtype);  
  display_parameter(2, 1, 0, Micpos);
  display_parameter(2, 1, 1, Miclevl);   
  display_parameter(3, 1, 0, Sololvl);
  display_parameter(3, 1, 1, Level);
  };
  if(device_mode == 2){  //EQ
  display_parameter(1, 0, 0, LoGain); 
  display_parameter(1, 0, 1, HiMidFrq);
  display_parameter(2, 0, 0, HiMidQ);
  display_parameter(2, 0, 1, HiMidGn);
  display_parameter(3, 0, 0, HiGain);
  display_parameter(3, 0, 1, "Charactr");
  
  display_parameter(1, 1, 0, LoCut); 
  display_parameter(1, 1, 1, LoMidFrq);
  display_parameter(2, 1, 0, LoMidQ);
  display_parameter(2, 1, 1, LoMidGn);  
  display_parameter(3, 1, 0, HiCut);
  display_parameter(3, 1, 1, Level);
  };

  if(device_mode == 3){  //effects
  display_parameter(1, 0, 0, "OD-Type "); 
  display_parameter(1, 0, 1, " FL-Rate");
  display_parameter(2, 0, 0, "TremRate");
  display_parameter(2, 0, 1, " DD-Time");
  display_parameter(3, 0, 0, "Cho-Rate");
  display_parameter(3, 0, 1, " RV-Time");
  
  display_parameter(1, 1, 0, "OD-Drive"); 
  display_parameter(1, 1, 1, " FL-Dpth");
  display_parameter(2, 1, 0, "Trem-lvl");
  display_parameter(2, 1, 1, " DD-levl");  
  display_parameter(3, 1, 0, "Cho-levl");
  display_parameter(3, 1, 1, " RV-Levl");
  };

  if(device_mode == 4){  //mix/synth
  display_parameter(1, 0, 0, "NPU-lev "); 
  display_parameter(1, 0, 1, "PCM1-lev"); 
  display_parameter(2, 0, 0, "TVF1-Atk");
  display_parameter(2, 0, 1, " TVF1dec");
  display_parameter(3, 0, 0, "TVA1-Atk");
  display_parameter(3, 0, 1, " TVA1dec");
  
  display_parameter(1, 1, 0, "MOD-lev "); 
  display_parameter(1, 1, 1, "PCM2-lev");
  display_parameter(2, 1, 0, "TVF2-Atk");
  display_parameter(2, 1, 1, " TVF2dec");  
  display_parameter(3, 1, 0, "TVA2-Atk");
  display_parameter(3, 1, 1, " TVA2dec");
  };
}

void GR55_data_change(int input_source, int value){
  if(device_mode <= 1){                                                 // mode 1 = Amp/Cab
  if(input_source == 1) {amp_type(value); };
  if(input_source == 2) {gain_type(1, 0, 1, value, "18000704"); };
  if(input_source == 3) {knob100(2, 0, 0, value, "Bass", "18000707"); };
  if(input_source == 4) {knob100(2, 0, 12, value, "Middle", "18000708"); };
  if(input_source == 5) {knob100(3, 0, 0, value, "Treble", "18000709"); };
  if(input_source == 6) {knob100(3, 0, 12, value, "Presense", "1800070A"); };
  if(input_source == 7) {knob120(1, 1, 0, value, "Gain", "18000702"); };
  if(input_source == 8) {cab_type(1, 1, 1, value, "1800070C"); };
  if(input_source == 9) {mic_pos(2, 1, 0, value, "1800070F"); };
  if(input_source == 10) {knob100(2, 1, 12, value, "Mic-Levl", "18000710"); };
  if(input_source == 11) {knob100(3, 1, 0, value, "SOLO", "18000706"); };
  if(input_source == 12) {rotary100(3, 1, 12, value, "Level", "18000703"); };
  };
  if(device_mode == 2){                                                //mode 2 = EQ
  if(input_source == 1) {knob20(1, 0, 0, value, LoGain, "18000613"); };
  if(input_source == 2) {mid_freq(1, 0, 9, value, HiMidFrq, "18000617"); };
  if(input_source == 3) {mid_q(2, 0, 0, value, HiMidQ, "18000618"); };
  if(input_source == 4) {knob20(2, 0, 10, value, HiMidGn, "18000619"); };
  if(input_source == 5) {knob20(3, 0, 0, value, HiGain, "1800061B"); };
  if(input_source == 6) {character(3, 0, 10, value, "Charactr", "1800061D"); };
  if(input_source == 7) {GR55_low_cut(value); };
  if(input_source == 8) {mid_freq(1, 1, 9, value, LoMidFrq, "18000614"); };
  if(input_source == 9) {mid_q(2, 1, 0, value, LoMidQ, "18000615"); };
  if(input_source == 10) {knob20(2, 1, 10, value, LoMidGn, "18000616"); };
  if(input_source == 11) {GR55_high_cut(value); };
  if(input_source == 12) {rotary20(3, 1, 10, value, Level, "18000703"); };
  };
   if(device_mode == 3){                                           // mode 3 = multi
  if(input_source == 1) {GR55_od_type(value); };                            //OD/DS type
  if(input_source == 2) {knob100(1, 0, 12, value, Bass, "18000403"); };     //flange rate MFX
  if(input_source == 3) {knob100(2, 0, 0, value, Bass, "18000345"); };      //tremolo rate MFX
  if(input_source == 4) {knob3400(2, 0, 9, value, Bass, "18000607"); };    //DD time    
  if(input_source == 5) {knob100(3, 0, 0, value, Bass, "18000602"); };      //chorus rate
  if(input_source == 6) {rv_time(3, 0, 11, value, Bass, "1800060E"); };     //reverb time
  if(input_source == 7) {knob120(1, 1, 0, value, Bass, "18000719"); };      //OD/DS drive
  if(input_source == 8) {knob100(1, 1, 12, value, Bass, "18000405"); };     //FL depth MFX
  if(input_source == 9) {knob100(2, 1, 0, value, Bass, "18000347"); };      //tremolo depth MFX
  if(input_source == 10) {knob120(2, 1, 12, value, Bass, "1800060B"); };    //DD level
  if(input_source == 11) {knob100(3, 1, 0, value, Bass, "18000604"); };     //Chorus level
  if(input_source == 12) {rotary100(3, 1, 10, value, Level, "18000610"); };  // reverb level
  };
   if(device_mode == 4){                                           // mode 4 = mix/PCM
  if(input_source == 1) {knob100(1, 0, 0, value, Bass, "18000233");};    //NPU
  if(input_source == 2) {knob07F(1, 0, 12, value, Bass, "18002004"); };  //PCM1 lev
  if(input_source == 3) {knob17F(2, 0, 0, value, Bass, "18003008"); };   //TVF atk       //knob100(lcd, line, position, label, address)
  if(input_source == 4) {knob17F(2, 0, 12, value, Bass, "18003009"); };  //TVF1 dec
  if(input_source == 5) {knob17F(3, 0, 0, value, Bass, "18003010"); };   //TVA1 atk
  if(input_source == 6) {knob17F(3, 0, 12, value, Bass, "18003011"); };  //TVA1 dec
  if(input_source == 7) {knob100(1, 1, 0, value, Bass, "18001009");};    //Modeling lev
  if(input_source == 8) {knob07F(1, 1, 12, value, Bass, "18002104"); };  //PCM2 lev
  if(input_source == 9) {knob17F(2, 1, 0, value, Bass, "18003108"); };   //TVF atk
  if(input_source == 10){knob17F(2, 1, 12, value, Bass, "18003109"); };  //TVF1 dec
  if(input_source == 11){knob17F(3, 1, 0, value, Bass, "18003110"); };   //TVA1 atk
  if(input_source == 12){rotary100(3, 1, 12, value, Bass, "18003111"); };  //TVA1 dec
  };
}

void amp_type(int value){
  value = map(value, 0, 126, 0, 41);
  String amp[] = {"Boss Cln", "JC-120", "Jazz Com", "Full Rng", "Cln Twin", "Pro Cnch", "Tweed", "Dlx Cnch", "BossCnch", "Blues", "WildCnch", 
  "Stk Cnch", "VO Drive", "VO Lead", "VO Clean", "MatchDrv", "FatMatch", "Match Ld", "BG Lead", "BG Drive", "BG Rhytm", "MS1959 I", "MS1959II", "MS HiGn", "MS Scoop", "RFierVnt", 
  "RFierMdn", "RFierCln", "TAmpLead", "TAmpCnch", "TAmp Cln", "Boss Drv", "SLDN", "Lead Stk", "Hvy Lead", "Boss Mtl", "5150 Drv",
  "Mtl Lead", "EdgeLead", "Bass Cln", "BassCnch", "BassHiGn"};
  display_parameter(1, 0, 0, amp[value]);
  prep_midi("18000701", value);
}

void GR55_low_cut(int value){
  value = map(value, 0, 126, 0, 10);
  String low_cut[] = {"Flat", "55.0Hz", "110Hz", "165Hz", "200Hz", "280Hz", "340Hz", "400Hz", "500Hz", "630Hz", "800HZ" };
  display_parameter(1, 1, 0, low_cut[value]);
  label_delay(1, 1, 0, LoCut);
  prep_midi("18000612", value);
}

void GR55_high_cut(int value){
  value = map(value, 0, 126, 0, 9);
  String high_cut[] = {"700Hz", "1.00kHz", "1.40kHz", "2.00kHz", "3.00kHz", "4.00kHz", "6.00kHz", "8.00kHz", "11.0kHz", "Flat" };
  display_parameter(3, 1, 0, high_cut[value]);
  label_delay(3, 1, 0, HiCut);
  prep_midi("1800061A", value);
}

void character(int lcd, int line, int pos, int value, String label, String address ){
  value = map(value, 0, 126, 0, 6);
  String character[] = {"-3", "-2", "-1", "0", "+1", "+2", "+3"};
   display_parameter(lcd, line, pos, character[value]);
  label_delay(lcd, line, pos, label);
  prep_midi(address, value);
}

void GR55_od_type(int value){
  value = map(value, 0, 126, 0, 24);
  String od[] = {"MidBoost", "ClnBoost", "TblBoost", "Blues OD", "Crunch", "Natrl OD", "OD-1", "TubeScmr", "Turbo OD", "Warm OD", "Distortn", "Mild DS", "Mid DS", "RAT",
  "GuV DS", "DST+", "ModernDS", "Solid DS", "Stack", "LOUD", "Metal Zn", "Lead", "60'sFuzz", "Oct Fuzz", "MuffFuzz" };
  display_parameter(1, 0, 0, od[value]);
  label_delay(1, 0, 0, HiCut);
  prep_midi("18000718", value);
}

