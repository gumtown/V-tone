
#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI1); //Enables serial1 port for MIDI communication!
#define USBMIDI_PORT 0
#define MIDI1_PORT 1

uint8_t Current_MIDI_port;


void OnSysEx(const unsigned char* sxdata, short unsigned int sxlength, bool sx_comp)
{

  if ((sxdata[1] == 0x41) && sx_comp) { //Check if it is a message from a Roland device

  }


}

void OnSerialSysEx(byte *sxdata, unsigned sxlength)
{

}

void setup_MIDI_common()
{
  usbMIDI.setHandleSysEx(OnSysEx);

  MIDI1.begin(MIDI_CHANNEL_OMNI);
  MIDI1.setHandleSystemExclusive(OnSerialSysEx);

}

void main_MIDI_common()
{
  Current_MIDI_port = USBMIDI_PORT;
  usbMIDI.read();
  Current_MIDI_port = MIDI1_PORT;
  MIDI1.read();
}

void prep_midi(String address, int value) {
  String lsb = String(value, HEX); if (value < 16) {
    lsb = String("0") + lsb;
};
String message = address + lsb;
sysex_prep(message);
};

void prep_2Byte(String address, int value){
  String lsb;
  String msb;
  int m = value / 128;
  int l = value - (m * 128);
    msb = String(m, HEX); if (m < 16) {
    msb = String("0") + msb;
  };
    lsb = String(l, HEX); if (value < 16) {
    lsb = String("0") + lsb;
  };
String message = address + msb + lsb;
sysex_prep(message);
};

void prep_3Byte(String address, int value){
  String lsb = String(value, HEX); 
    if (value < 256) {
    lsb = String("0") + lsb; 
    };
    if (value < 16) {
    lsb = String("0") + lsb;
  };
   String message = address+"0"+String(lsb[0])+"0"+String(lsb[1])+"0"+String(lsb[2]);
  sysex_prep(message);
};

void sysex_prep(String message){
String new_message;
int len = message.length();
int data_size = 0;
for (int x = 0; x < len; ++x)
{
  int a = String(message[x], 16).toInt() - 30; //convert char nibble to int
  if (a > 9) {
    a = a - 1;
  };                            // A~F seem to be off by 1
  int b = String(message[x + 1], 16).toInt() - 30; //convert char nibble to int
  if (b > 9) {
    b = b - 1;
  };                            // A~F seem to be off by 1 (B~G)
  data_size = data_size + ((a * 16) + b);
  a = a + 48; if (a > 57) {
    a = a + 7;
  };                   //ASCII table lookup - this is a retarded way to do it - but it works.
  b = b + 48; if (b > 57) {
    b = b + 7;
  };
  new_message.append(char(a)).append(char(b));    // rebuild message with missing A's
  ++x;
};
int sum = 128 - (data_size % 128);
if (sum == 128) {
  sum = 0;
};
String checksum = String(sum, 16); if (sum < 16) {
  checksum = String(("0") + checksum);
};
String header = String("F041100000000512");  //GP-10
if (device_type == 2)(header = String("F0411000005312")); //GR-55
if (device_type == 3)(header = String("F0411000006012")); //GT-100
if (device_type == 4)(header = String("F0411000005312")); //SY-300
if (device_type >= 5)(header = String("F0411000005312")); //VG-99
message = header + new_message + checksum + String("F7");
if (message != previous_value) {
  send_sysx(message);
  previous_value = message;
};
/*Serial.print("pre "+message);
Serial.println();*/
}

void send_sysx(String message) {
  int len = message.length();                 // sysx data can be any size
  uint8_t array[len / 2];                     // array length calculated in 1 byte blocks
  for (int x = 0; x < len; ++x)
  {
    int a = String(message[x], 16).toInt() - 30; //convert char nibble to int
    if (a > 9) {
      a = a - 1;
    };                           // A~F seem to be off by 1
    int b = String(message[x + 1], 16).toInt() - 30; //convert char nibble to int
    if (b > 9) {
      b = b - 1;
    };                           // A~F seem to be off by 1
    int c = (a * 16) + b;
    array[x / 2] = c;
    ++x;
  };
  Serial.print("out ");
  for (unsigned int i = 0; i < sizeof(array); i++) {
    String h = String(array[i], HEX);
    if (h.length() < 2) {
      h = String("0") + h;
    };
    Serial.print(h);
  }
  Serial.println();

  usbMIDI.sendSysEx(len / 2, array );
  MIDI1.sendSysEx(len / 2, array );
}
