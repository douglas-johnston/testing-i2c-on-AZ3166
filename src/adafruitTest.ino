#include <Wire.h>


float read16() {
  uint16_t ret;
  Wire.beginTransmission(0x5A); // start transmission to device 
  Wire.write(0x07); // sends register address to read from
  Wire.endTransmission(false); // end transmission
  Serial.println(Wire.requestFrom(0x5A, (uint8_t)3), false);// send data n-bytes read
  
  ret = Wire.read(); // receive DATA
  ret |= Wire.read() << 8; // receive DATA
  uint8_t pec = Wire.read();
  Serial.println(ret, HEX);
  float processed = (ret * 0.02) - 273.15;
  return processed;
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(20000);
  float temp = read16();
  Serial.print("Ambient = ");
  Serial.print(temp); 
  //Serial.println(read16());
}

void loop() {
}
