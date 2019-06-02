#include <MPU9250_asukiaaa.h>
#include <SoftwareSerial.h>

#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 26
#define SCL_PIN 25
#endif

MPU9250 mySensor;

SoftwareSerial bluetoothDevice(11, 10); // RX, TX
#define baud_rate 9600

uint8_t sensorId;
float aX, aY, aZ;

void setup() {
  while(!Serial);
  Serial.begin(115200);
  bluetoothDevice.begin(9600);
  bluetoothDevice.println("We are ready");
#ifdef _ESP32_HAL_I2C_H_ // For ESP32
  Wire.begin(SDA_PIN, SCL_PIN); // SDA, SCL
#else
  Wire.begin();
#endif
  
  mySensor.setWire(&Wire);
  mySensor.beginAccel();
  sensorId = mySensor.readId();
}



void loop() {
  mySensor.accelUpdate();
  aX = mySensor.accelX() - (0.12);
  aY = mySensor.accelY() - (-0.02); 
  aZ = mySensor.accelZ();

  bluetoothDevice.print(aX);
  bluetoothDevice.print(" ");
  bluetoothDevice.print(aY);
  bluetoothDevice.print(" ");
  bluetoothDevice.print(aZ);
  bluetoothDevice.println();
  
  Serial.print(aX);
  Serial.print(" ");
  Serial.print(aY);
  Serial.print(" ");
  Serial.print(aZ);
  Serial.println();
  delay(1000);
}
