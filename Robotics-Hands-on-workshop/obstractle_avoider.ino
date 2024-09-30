#define MOTOR_SPEED 180
int trigPin = 5;
int echoPin = 6;
int rightMotorPin1 = 7;
int rightMotorPin2 = 8;

int leftMotorPin1 = 9;
int leftMotorPin2 = 10;

int c = 0;

void setup() {
  //Serial.begin(9600);
  //pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  Serial.begin(9600);
  //pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:


}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration) / 58.2;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
  Serial.println(distance);


  if ((distance > 20))
  {
    Serial.println("20000000");
    digitalWrite(8, LOW);                              //       If you dont get proper movements of your robot,
    digitalWrite(7, HIGH);                              //        then alter the pin numbers
    digitalWrite(9, HIGH);                              //
    digitalWrite(10, LOW);                             //
  }

  else if (distance < 18)
  {
    Serial.println("180000000");
    digitalWrite(8, LOW);                              //       If you dont get proper movements of your robot,
    digitalWrite(7, LOW);                              //        then alter the pin numbers
    digitalWrite(9, LOW);                              //
    digitalWrite(10, LOW);
    delay(500);
    digitalWrite(8, HIGH);                              //       If you dont get proper movements of your robot,
    digitalWrite(7, LOW);                              //        then alter the pin numbers
    digitalWrite(9, LOW);                              //
    digitalWrite(10, HIGH);
    delay(1000);
    digitalWrite(8, LOW);                              //       If you dont get proper movements of your robot,
    digitalWrite(7, LOW);                              //        then alter the pin numbers
    digitalWrite(9, LOW);                              //
    digitalWrite(10, LOW);
    delay(100);
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(9, HIGH);                                 //HIGH
    digitalWrite(10, LOW);
    delay(500);

  }

}
