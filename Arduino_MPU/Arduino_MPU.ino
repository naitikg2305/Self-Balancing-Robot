#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

void setup() {
  Serial.begin(9600);
  delay(1000);
  Wire.begin();  // On Uno: SDA = A4, SCL = A5

  byte status = mpu.begin();
  Serial.print("MPU6050 status: ");
  Serial.println(status);
  while (status != 0) {
    delay(1000);
    Serial.println("MPU not connected...");
  }

  Serial.println("Calibrating gyro...");
  delay(1000);
  mpu.calcOffsets(); // gyro and accel calibration
  Serial.println("Done!");
}

void loop() {
  mpu.update();

  // Angle in X-axis (pitch) for balancing
  Serial.print("Angle X (Pitch): ");
  Serial.print(mpu.getAngleX());
  Serial.print("\t");

  // Raw acceleration and gyro
  Serial.print("Accel Z: ");
  Serial.print(mpu.getAccZ());
  Serial.print("\tGyro Y: ");
  Serial.println(mpu.getGyroY());

  delay(100);
}
