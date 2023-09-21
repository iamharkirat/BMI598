#include <Arduino_LSM9DS1.h>

void setup() {
  // Initialize Serial communication
  Serial.begin(115200);

  // Initialize the IMU sensor
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
}

void loop() {
  // Read accelerometer data
  float ax, ay, az;
  IMU.readAcceleration(ax, ay, az);

  // Read gyroscope data
  float gx, gy, gz;
  IMU.readGyroscope(gx, gy, gz);

  // Send accelerometer data to Serial for plotting
  Serial.print(ax);
  Serial.print("\t");
  Serial.print(ay);
  Serial.print("\t");
  Serial.print(az);
  Serial.print("\t");

  // Send gyroscope data to Serial for plotting
  Serial.print(gx);
  Serial.print("\t");
  Serial.print(gy);
  Serial.print("\t");
  Serial.println(gz);

  delay(500); // 500 ms delay for a 2Hz sampling rate, adjust as needed
}