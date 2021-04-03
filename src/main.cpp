#include <Arduino.h>
#include <IRremote.h>
int IR_RECEIVE_PIN = 11; // Receive on pin 11

int index = 0;
decode_results results;


void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver, enable feedback LED, take LED feedback pin from the internal boards definition

}

void loop() {

  
  if (IrReceiver.decode()) {

    uint16_t kommando = IrReceiver.decodedIRData.command;
    decode_type_t protokol = IrReceiver.decodedIRData.protocol;
    
    if(kommando == 0x1D && protokol == RC5) {
      Serial.println(index);
      index++;
    } else {
    }
    
  //Show debug info in terminal
  //IrReceiver.printIRResultShort(&Serial);


    IrReceiver.resume(); // Continue receiving
  }
}