#include <SoftwareSerial.h>

SoftwareSerial bluetoothDevice(10, 11); // RX, TX
#define baud_rate 9600
#define LED 13
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(baud_rate);
  while(!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("We are ready!");

  // set the data rate for the SoftwareSerial port
  bluetoothDevice.begin(baud_rate);
  bluetoothDevice.println("We are ready");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetoothDevice.available()) {
    char input = bluetoothDevice.read();
    if (input == '1') {
      digitalWrite(LED, HIGH);
    } else if (input == '0') {
      digitalWrite(LED, LOW);
    }
    Serial.write(input);
  }
  if (Serial.available()) {
    bluetoothDevice.write(Serial.read());
  }
  delay(60);
}
