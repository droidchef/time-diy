#include <MPU9250_asukiaaa.h>

#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 26
#define SCL_PIN 25
#endif

MPU9250 mySensor;

uint8_t sensorId;
float aX, aY, aZ, aSqrt, gX, gY, gZ, mDirection, mX, mY, mZ;

void setup() {
  while(!Serial);
  Serial.begin(115200);
  //Serial.println("started");

#ifdef _ESP32_HAL_I2C_H_ // For ESP32
  Wire.begin(SDA_PIN, SCL_PIN); // SDA, SCL
#else
  Wire.begin();
#endif

  mySensor.setWire(&Wire);
  mySensor.beginAccel();
  mySensor.beginGyro();
  mySensor.beginMag();

  // You can set your own offset for mag values
  // mySensor.magXOffset = -50;
  // mySensor.magYOffset = -55;
  // mySensor.magZOffset = -10;

  sensorId = mySensor.readId();
  //Serial.println();
}



void loop() {
//  Serial.println("sensorId: " + String(sensorId));
//
  mySensor.accelUpdate();
//  aX = mySensor.accelX();
//  aY = mySensor.accelY();
//  aZ = mySensor.accelZ();

  aX = mySensor.accelX() - (0.12);
  aY = mySensor.accelY() - (-0.02); 
  aZ = mySensor.accelZ();

  
  Serial.print(aX);
  Serial.print(" ");
  Serial.print(aY);
  Serial.print(" ");
  Serial.print(aZ);
  Serial.print(" ");
//  aSqrt = mySensor.accelSqrt();
//  Serial.println("accelX:s " + String(aX));
//  Serial.println("accelY: " + String(aY));
//  Serial.println("accelZ: " + String(aZ));
//  Serial.println("accelSqrt: " + String(aSqrt));
//
  mySensor.gyroUpdate();
  gX = mySensor.gyroX() - (-0.26); // THis is the offset subtracted for gX
  gY = mySensor.gyroY() - (0.19); // THis is the offset subtracted for gY
  gZ = mySensor.gyroZ() - (1.42); // THis is the offset subtracted for gX

//  gX = mySensor.gyroX() ;
//  gY = mySensor.gyroY() ;
//  gZ = mySensor.gyroZ() ; 
  
  Serial.print(gX);
  Serial.print(" ");
  Serial.print(gY);
  Serial.print(" ");
  Serial.print(gZ);
  Serial.print(" ");
//  Serial.println("gyroX: " + String(gX));
//  Serial.println("gyroY: " + String(gY));
//  Serial.println("gyroZ: " + String(gZ));
//
  mySensor.magUpdate();
  mX = mySensor.magX();
  mY = mySensor.magY();
  mZ = mySensor.magZ();
  Serial.print(mX);
  Serial.print(" ");
  Serial.print(mY);
  Serial.print(" ");
  Serial.println(mZ);
  //mDirection = mySensor.magHorizDirection();
//  Serial.println("magX: " + String(mX));
//  Serial.println("maxY: " + String(mY));
//  Serial.println("magZ: " + String(mZ));
  //Serial.println("horizontal direction: " + String(mDirection));
//
//  Serial.println("at " + String(millis()) + "ms");
//  Serial.println(""); // Add an empty line
  delay(64);
}
