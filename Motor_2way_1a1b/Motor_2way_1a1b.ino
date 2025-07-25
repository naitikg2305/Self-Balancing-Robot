// Motor 1 (Left or A)
#define INA1 18   // Direction 1
#define INB1 5    // Direction 2
#define PWM1 25   // Speed PWM

// Motor 2 (Right or B)
#define INA2 19   // Direction 1
#define INB2 4    // Direction 2
#define PWM2 26   // Speed PWM

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
  analogWrite(PWM1, 200);

  digitalWrite(INA2, LOW);
  digitalWrite(INB2, HIGH);
  analogWrite(PWM2, 200);
  delay(2000);

  Serial.println("Reverse");
  digitalWrite(INA1, LOW);
  digitalWrite(INB1, HIGH);
  analogWrite(PWM1, 200);

  digitalWrite(INA2,  HIGH);
  digitalWrite(INB2, LOW);
  analogWrite(PWM2, 200);
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
  digitalWrite(INB2, LOW);x`
  analogWrite(PWM2, 0);
  delay(2000);
}
