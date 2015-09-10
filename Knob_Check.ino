





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

void setup_variables(){
  read_input();
  knob1_previous=knob1_read;
  knob2_previous=knob2_read;
  knob3_previous=knob3_read;
  knob4_previous=knob4_read;
  knob5_previous=knob5_read;
  knob6_previous=knob6_read;
  knob7_previous=knob7_read;
  knob8_previous=knob8_read;
  knob9_previous=knob9_read;
  knob10_previous=knob10_read;
  knob11_previous=knob11_read;
  knob12_previous=knob12_read;
}

void read_input(){
knob1_read = analogRead(knob1)/8;
knob2_read = analogRead(knob2)/8;
knob3_read = analogRead(knob3)/8;
knob4_read = analogRead(knob4)/8;
knob5_read = analogRead(knob5)/8;
knob6_read = analogRead(knob6)/8;
knob7_read = analogRead(knob7)/8;
knob8_read = analogRead(knob8)/8;
knob9_read = analogRead(knob9)/8;
knob10_read = analogRead(knob10)/8;
knob11_read = analogRead(knob11)/8;
knob12_read = analogRead(knob12)/8;
}

void process_analog(){
if(knob1_read!=knob1_previous){/*Serial.print("knob1 value = "+ String(knob1_read)); Serial.println();*/ knob1_previous=knob1_read; data_change(knob1, knob1_read); };
if(knob2_read!=knob2_previous){/*Serial.print("knob2 value = "+ String(knob2_read)); Serial.println();*/ knob2_previous=knob2_read; data_change(knob2, knob2_read); };
if(knob3_read!=knob3_previous){/*Serial.print("knob3 value = "+ String(knob3_read)); Serial.println();*/ knob3_previous=knob3_read; data_change(knob3, knob3_read); };
if(knob4_read!=knob4_previous){/*Serial.print("knob4 value = "+ String(knob4_read)); Serial.println();*/ knob4_previous=knob4_read; data_change(knob4, knob4_read); };
if(knob5_read!=knob5_previous){/*Serial.print("knob5 value = "+ String(knob5_read)); Serial.println();*/ knob5_previous=knob5_read; data_change(knob5, knob5_read); };
if(knob6_read!=knob6_previous){/*Serial.print("knob6 value = "+ String(knob6_read)); Serial.println();*/ knob6_previous=knob6_read; data_change(knob6, knob6_read); };
if(knob7_read!=knob7_previous){/*Serial.print("knob7 value = "+ String(knob7_read)); Serial.println();*/ knob7_previous=knob7_read; data_change(knob7, knob7_read); };
if(knob8_read!=knob8_previous){/*Serial.print("knob8 value = "+ String(knob8_read)); Serial.println();*/ knob8_previous=knob8_read; data_change(knob8, knob8_read); };
if(knob9_read!=knob9_previous){/*Serial.print("knob9 value = "+ String(knob9_read)); Serial.println();*/ knob9_previous=knob9_read; data_change(knob9, knob9_read); };
if(knob10_read!=knob10_previous){/*Serial.print("knob10 value = "+ String(knob10_read)); Serial.println();*/ knob10_previous=knob10_read; data_change(knob10, knob10_read); };
if(knob11_read!=knob11_previous){/*Serial.print("knob11 value = "+ String(knob11_read)); Serial.println();*/ knob11_previous=knob11_read; data_change(knob11, knob11_read); };
if(knob12_read!=knob12_previous){/*Serial.print("knob12 value = "+ String(knob12_read)); Serial.println();*/ knob12_previous=knob12_read; data_change(knob12, knob12_read); };
}
