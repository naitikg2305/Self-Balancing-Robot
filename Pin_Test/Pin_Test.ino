#include <dummy.h>

#include <dummy.h>

void setup() {
  delay(1000);  // Add this line
  Serial.begin(115200);
  Serial.println("LedBlink started");

  pinMode(2, OUTPUT);  // GPIO 2 is the onboard LED
}

void loop() {
  Serial.println("LedBlink");
  digitalWrite(2, HIGH);   // Turn LED on
  delay(500);              // Wait 500ms
  digitalWrite(2, LOW);    // Turn LED off
  delay(500);              // Wait 500ms
}
