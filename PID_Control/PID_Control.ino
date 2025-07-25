#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

float prev = 0;
float target = 0;
float kP = 3;
float kD = 450  ;
unsigned long t;
float lowBound = 15;

#define L1 8
#define L2 9
#define R1 12
#define R2 13
#define LS 10
#define RS 11

void setup() {
  Serial.begin(9600);
  //pinmodes
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(LS, OUTPUT);
  pinMode(RS, OUTPUT);

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
  //mpu.update();
  
  while(true){
  mpu.update();
  float current = float(mpu.getAngleX()); //read mpu
  int timestep = millis()-t;
  t = millis();
  //error
  float error = target-current;
  //P
  float P = error * kP;
  //D
  float D = kD * (error-prev)/timestep;
  //overall
  float motorInput = P + D ;//later
  Serial.print(t);
  Serial.print(",");
  Serial.print (error);
  Serial.print(",");
  Serial.print (current) ;
  Serial.print(",");
  Serial.print (P) ;
  Serial.print(",");
  Serial.print (D) ;
  Serial.print(",");
  Serial.println (motorInput );

  if(motorInput >= lowBound){
    motorInput = constrain(motorInput,lowBound,255);
    motorMove(motorInput,false);
  }else if (motorInput <= -lowBound){
    motorInput = constrain(motorInput,-255,-lowBound);
    motorMove(abs(motorInput),true);
  }else{
    motorInput = 0;
    motorStop();
  }
  prev = error; //for next cycle
  if (abs(current) >= 25){
    break;
  }
  }
  motorStop();
  while(true){}
}

void motorMove(int input, bool dir){
  if(dir){ //forward
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
  }else{
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
  }
  analogWrite(LS, input);
  analogWrite(RS, input);
}

void motorStop(){
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
}