#include <Arduino_LSM9DS1.h>
float aX, aY, aZ, gX, gY, gZ, mX, mY, mZ;
void setup() {
  Serial.begin(115200);
  while (!Serial);
  delay(200);
  IMU.begin();
  Serial.print("aX,aY,aZ,gX,gY,gZ,mX,mY,mZ");
}
void loop() {
  if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable() && IMU.magneticFieldAvailable()) {
      IMU.readAcceleration(aX, aY, aZ);
      IMU.readGyroscope(gX, gY, gZ);
      IMU.readMagneticField(mX, mY, mZ);
      Serial.print(aX, 3);Serial.print(',');
      Serial.print(aY, 3);Serial.print(',');
      Serial.print(aZ, 3);Serial.print(',');
      Serial.print(gX, 3);Serial.print(',');
      Serial.print(gY, 3);Serial.print(',');
      Serial.print(gZ, 3);
//      Serial.print(',');
//    Serial.print(mX, 3);Serial.print(',');
//    Serial.print(mY, 3);Serial.print(',');
//    Serial.print(mZ, 3);
      Serial.println();
      delay(10);
    }
}
