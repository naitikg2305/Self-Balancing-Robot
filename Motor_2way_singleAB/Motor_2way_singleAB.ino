// Motor A control
#define DIR_A 18  // Connected to 1INA
#define PWM_A 25  // Connected to 1PWM

// Motor B control
#define DIR_B 19  // Connected to 2INA
#define PWM_B 26  // Connected to 2PWM

void setup() {
  // Setup direction and speed pins
  pinMode(DIR_A, OUTPUT);
  pinMode(PWM_A, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(PWM_B, OUTPUT);

  Serial.begin(115200);
  Serial.println("Starting motor test...");
}

void loop() {
  Serial.println("Forward...");

  // Both motors forward at 75% speed
  digitalWrite(DIR_A, HIGH);
  analogWrite(PWM_A, 192);  // 192/255 ~ 75% duty cycle

  digitalWrite(DIR_B, HIGH);
  analogWrite(PWM_B, 192);

  delay(2000);

  Serial.println("Reverse...");

  // Reverse both motors at 75% speed
  digitalWrite(DIR_A, LOW);
  analogWrite(PWM_A, 192);

  digitalWrite(DIR_B, LOW);
  analogWrite(PWM_B, 192);

  delay(2000);

  Serial.println("Brake...");
  // Brake: no PWM output (set to 0)
  analogWrite(PWM_A, 0);
  analogWrite(PWM_B, 0);

  delay(2000);
}
