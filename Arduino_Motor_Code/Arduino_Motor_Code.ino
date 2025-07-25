
#define INA1 8   // Direction 1
#define INB1 9    // Direction 2
#define PWM1 10   // Speed PWM

// Motor 2 (Right or B)
#define INA2 13  // Direction 1
#define INB2 12    // Direction 2
#define PWM2 11  
void setup() {

  Serial.begin(115200);
  Serial.println("Starting Motor Test...");

  pinMode(INA1, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(PWM1, OUTPUT);

  pinMode(INA2, OUTPUT);
  pinMode(INB2, OUTPUT);
  pinMode(PWM2, OUTPUT);
}

void loop() {
  Serial.println("Forward");
  digitalWrite(INA1, HIGH);
  digitalWrite(INB1, LOW);
  analogWrite(PWM1, 16);

  digitalWrite(INA2, LOW);
  digitalWrite(INB2, HIGH);
  analogWrite(PWM2, 16);
  delay(2000);

  Serial.println("Reverse");
  digitalWrite(INA1, LOW);
  digitalWrite(INB1, HIGH);
  analogWrite(PWM1, 17);

  digitalWrite(INA2,  HIGH);
  digitalWrite(INB2, LOW);
  analogWrite(PWM2, 17);
  delay(2000);

  Serial.println("Brake");
  digitalWrite(INA1, HIGH);
  digitalWrite(INB1, HIGH);
  analogWrite(PWM1, 0);

  digitalWrite(INA2, HIGH);
  digitalWrite(INB2, HIGH);
  analogWrite(PWM2, 0);
  delay(2000);

  Serial.println("Coast");
  digitalWrite(INA1, LOW);
  digitalWrite(INB1, LOW);
  analogWrite(PWM1, 0);

  digitalWrite(INA2, LOW);
  digitalWrite(INB2, LOW);
  analogWrite(PWM2, 0);
  delay(2000);
}
