#include <Arduino_LSM9DS1.h>
const int ledPin = 13;

void setup() {
  // Initialize Serial communication
  Serial.begin(115200);


  // Initialize the IMU sensor
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read accelerometer data
  float ax, ay, az;
  IMU.readAcceleration(ax, ay, az);

  // Read gyroscope data
  float gx, gy, gz;
  IMU.readGyroscope(gx, gy, gz);

  if (az>=0.8 && az <=1.2)
      {
          Serial.println("supine") ;
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
      }
  else if ((ay>=0.8 && az <=1.2) || (ay<= -0.8 && az >= -1.2))
      {
          Serial.println("side") ;
          digitalWrite(ledPin, HIGH);
          delay(100);
          digitalWrite(ledPin, LOW);
          delay(100);
          digitalWrite(ledPin, HIGH);
          delay(100);
          digitalWrite(ledPin, LOW);
          delay(100);
          digitalWrite(ledPin, HIGH);
          delay(100);
          digitalWrite(ledPin, LOW);

      }
  else if (az<= -0.8 && az >= -1.2)
      {
          Serial.println("prone") ;
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(100);
          digitalWrite(ledPin, HIGH);
          delay(100);
          digitalWrite(ledPin, LOW);
      }
  delay(500); // 500 ms delay for a 2Hz sampling rate, adjust as needed
}