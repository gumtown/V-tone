

void GP10_init(){
  clear_displays();
 if(device_mode == 1){
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
  if(device_mode == 2){
  display_parameter(1, 0, 0, LoGain); 
  display_parameter(1, 0, 1, HiMidFrq); 
  display_parameter(2, 0, 0, HiMidQ);
  display_parameter(2, 0, 1, HiMidGn);
  display_parameter(3, 0, 0, HiGain);
  //display_parameter(3, 0, 1, "Charactr");
  
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
  display_parameter(1, 0, 1, " StrLev1"); 
  display_parameter(2, 0, 0, "StrLev2 ");
  display_parameter(2, 0, 1, "StrLev3 ");
  display_parameter(3, 0, 0, "OSCfltAk");
  display_parameter(3, 0, 1, "OSCfltDy");
  
  display_parameter(1, 1, 0, "MOD-lev "); 
  display_parameter(1, 1, 1, " StrLev4");
  display_parameter(2, 1, 0, "StrLev5 ");
  display_parameter(2, 1, 1, " StrLev6");  
  display_parameter(3, 1, 0, "OSCampAk");
  display_parameter(3, 1, 1, "OSCampDy");
  };
}

void GP10_data_change(int input_source, int value){
  if(device_mode == 1){                               //Amp/Cab
  if(input_source == 1) {GP10_amp_type(value); };
  if(input_source == 2) {gain_type(1, 0, 1, value, "2000500A"); };  //(lcd, line, position, knob value, address)
  if(input_source == 3) {knob100(2, 0, 0, value, Bass, "20005005"); };
  if(input_source == 4) {knob100(2, 0, 1, value, Middle, "20005006"); };
  if(input_source == 5) {knob100(3, 0, 0, value, Treble, "20005007"); };
  if(input_source == 6) {knob100(3, 0, 1, value, Presense, "20005008"); };
  if(input_source == 7) {knob120(1, 1, 0, value, Gain, "20005002"); };
  if(input_source == 8) {cab_type(1, 1, 1, value, "2000500E"); };
  if(input_source == 9) {mic_pos(2, 1, 0, value, "20005011"); };
  if(input_source == 10) {knob100(2, 1, 1, value, Miclevl, "20005012"); };
  if(input_source == 11) {knob100(3, 1, 0, value, Sololvl, "2000500C"); };
  if(input_source == 12) {rotary100(3, 1, 12, value, Level, "20005004"); };
  };
  if(device_mode == 2){                               //Equalizer
  if(input_source == 1) {knob20(1, 0, 0, value, LoGain, "20020002"); };
  if(input_source == 2) {mid_freq(1, 0, 1, value, HiMidFrq, "20020007"); };
  if(input_source == 3) {mid_q(2, 0, 0, value, HiMidQ, "20020008"); };
  if(input_source == 4) {knob20(2, 0, 1, value, HiMidGn, "20020006"); };
  if(input_source == 5) {knob20(3, 0, 0, value, HiGain, "20020009"); };
 // if(input_source == 6) {character(3, 0, 1, value, "Charactr", "061D"); };
  if(input_source == 7) {low_cut(1, 1, 0, value, "20020001"); };
  if(input_source == 8) {mid_freq(1, 1, 1, value, LoMidFrq, "20020004"); };
  if(input_source == 9) {mid_q(2, 1, 0, value, LoMidQ, "20020005"); };
  if(input_source == 10) {knob20(2, 1, 1, value, LoMidGn, "20020003"); };
  if(input_source == 11) {high_cut(3, 1, 0, value, "2002000A"); };
  if(input_source == 12) {knob20(3, 1, 10, value, Level, "2002000B"); };
  };
  if(device_mode == 3){                              // mode 3 = multi
  if(input_source == 1) {GP10_od_type(value); };                            //OD/DS type
  if(input_source == 2) {knob100(1, 0, 12, value, Bass, "20007000"); };     //flange rate FX
  if(input_source == 3) {knob100(2, 0, 0, value, Bass, "20007800"); };      //tremolo rate FX
  if(input_source == 4) {knob2000(2, 0, 12, value, Bass, "20017002"); };    //DD time    
  if(input_source == 5) {knob100(3, 0, 0, value, Bass, "20016802"); };      //chorus rate
  if(input_source == 6) {rv_time(3, 0, 11, value, Bass, "20017801"); };     //reverb time
  if(input_source == 7) {knob120(1, 1, 0, value, Bass, "20006001"); };      //OD/DS drive
  if(input_source == 8) {knob100(1, 1, 12, value, Bass, "20007001"); };     //FL depth FX
  if(input_source == 9) {knob100(2, 1, 0, value, Bass, "20007801"); };      //tremolo depth FX
  if(input_source == 10) {knob120(2, 1, 12, value, Bass, "20017007"); };    //DD level
  if(input_source == 11) {knob100(3, 1, 0, value, Bass, "20016807"); };     //Chorus level
  if(input_source == 12) {rotary100(3, 1, 12, value, Level, "2001780A"); }; //reverb level
  };
  if(device_mode == 4){                             // mode 4 = mix/PCM
  if(input_source == 1) {knob100(1, 0, 0, value, Bass, "20000805");};    //NPU      //knob100(lcd, line, position, label, address)
  if(input_source == 2) {knob100(1, 0, 12, value, Bass, "20001005"); };  //String level 1
  if(input_source == 3) {knob100(2, 0, 0, value, Bass, "20001006"); };   //String level 2     
  if(input_source == 4) {knob100(2, 0, 12, value, Bass, "20001007"); };  //String level 3
  if(input_source == 5) {knob50(3, 0, 0, value, Bass, "20003033"); };   //OSCfltAk 
  if(input_source == 6) {knob50(3, 0, 12, value, Bass, "20003034"); };  //OSCfltDy
  if(input_source == 7) {knob100(1, 1, 0, value, Bass, "20001801");};    //Modeling lev electric
  if(input_source == 7) {knob100(1, 1, 0, value, Bass, "20002001");};    //Modeling lev acoustic
  if(input_source == 7) {knob100(1, 1, 0, value, Bass, "20002801");};    //Modeling lev bass
  if(input_source == 7) {knob100(1, 1, 0, value, Bass, "20003002");};    //Modeling lev GR300
  if(input_source == 7) {knob100(1, 1, 0, value, Bass, "2000301A");};    //Modeling lev OSC
  if(input_source == 7) {knob100(1, 1, 0, value, Bass, "20003059");};    //Modeling lev WAV
  if(input_source == 7) {knob100(1, 1, 0, value, Bass, "20003801");};    //Modeling lev Poly FX
  if(input_source == 8) {knob100(1, 1, 12, value, Bass, "20001008"); };  //String level 4
  if(input_source == 9) {knob100(2, 1, 0, value, Bass, "20001009"); };   //String level 5
  if(input_source == 10){knob100(2, 1, 12, value, Bass, "2000100A"); };  //String level 6
  if(input_source == 11){knob50(3, 1, 0, value, Bass, "20003039"); };   //OSCampAk
  if(input_source == 12){knob50(3, 1, 12, value, Bass, "2000303A"); };  //OSCampDy
  };
}

void GP10_amp_type(int value){
  value = map(value, 0, 126, 0, 29);
  String amp[] = {"Ntrl Cln", "Full Rng", "CombCnch", "Stk Cnch", "HiGn Stk", "PowerDrv", "ExtremLd", "Core Mtl", "JC-120", "Cln Twin", "Pro Cnch", "Tweed", "Dlx Cnch",
  "VO Drive", "VO Lead", "MatchDrv", "BG Lead", "BG Drive", "MS1959 I", "MS1959II", "RFierVnt", "RFierMdn", "TAmpLead", "SLDN", "5150 Drv", "BognerUB", "OrangeRR", "Bass Cln", "BassCnch", "BassHiGn"};
  display_parameter(1, 0, 0, amp[value]);
  prep_midi("20005001", value);
}

void GP10_od_type(int value){
  value = map(value, 0, 126, 0, 20);
  String od[] = {"MidBoost", "ClnBoost", "TblBoost", "Crunch", "Natrl OD", "Warm OD", "Fat DS", "Lead DS", "Metal DS", "Oct Fuzz", "Blues OD", "OD-1", "TubeScmr", "Turbo OD", "Distortn", "RAT",
  "GuV DS", "DST+", "Metal Zn", "60'sFuzz", "MuffFuzz" };
  display_parameter(1, 0, 0, od[value]);
  label_delay(1, 0, 0, HiCut);
  prep_midi("20006000", value);
}






