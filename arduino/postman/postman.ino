#include <SakuraAlpha.h>

SakuraAlphaI2C sakura;

#define SWITCH_PIN 8
uint8_t POST_OPEN_CHANNEL = 0;
//uint32_t DELAY_POST_OPEN = 5 * 60 * 1000;



void setup() {
  pinMode(SWITCH_PIN, INPUT);
  Serial.begin(9600);

  Serial.println("Waiting to come online ... ");
  while (sakura.getNetworkStatus() != 1) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  Serial.println("Connected!");

}

uint32_t before = 0;
void loop() {
  if (digitalRead(SWITCH_PIN) == 1) {
    uint32_t value  = 1;
    if(before != value){
    sakura.writeChannel(POST_OPEN_CHANNEL, value);
    sakura.transmit(TRANSMIT_ONCE);
    Serial.println("Send!");
      
    }
    before = value;
    delay(10000);
  }
  before = 0;
  delay(200);
}
