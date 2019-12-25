#include <HardwareSerial.h>

HardwareSerial MySerial(1);

void setup() {
  Serial.begin(115200);
  MySerial.begin(115200, SERIAL_8N1, 9, 10);

  Serial.println("\nSoftware serial test started");
}

void loop() {
  int incoming;
  char buf[10];
  while (Serial.available() > 0) {
    MySerial.write(Serial.read());
  }
    
  while (MySerial.available() > 0) {
    incoming = MySerial.read();
    if (incoming == 0x0D)
      sprintf(buf, "CR  %02X", incoming);
    else if (incoming == 0x0A)
      sprintf(buf, "LF  %02X", incoming);
    else
      sprintf(buf, "%c  %02X", incoming, incoming);
    Serial.println(buf);
  }

}
