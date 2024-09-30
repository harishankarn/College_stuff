

//Right motor

int rightMotorPin1 = 7;
int rightMotorPin2 = 8;

//Left motor

int leftMotorPin1 = 9;
int leftMotorPin2 = 10;

char command;

void setup()
{
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.
    //Serial.println(command);
    switch (command) {
      case 'F':
        forward();

        break;
      case 'B':

        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();

        break;
    }
  }
}

void forward()
{
  digitalWrite(8, LOW);                              //       If you dont get proper movements of your robot,
  digitalWrite(7, HIGH);                              //        then alter the pin numbers
  digitalWrite(9, HIGH);                              //
  digitalWrite(10, LOW);                             //
}

void back()
{
  digitalWrite(8, HIGH);                              //       If you dont get proper movements of your robot,
  digitalWrite(7, LOW);                              //        then alter the pin numbers
  digitalWrite(9, LOW);                              //
  digitalWrite(10, HIGH);
}

void left()
{
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(9, HIGH);                                 //HIGH
  digitalWrite(10, LOW);
}

void right()
{
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(9, LOW);                                 //HIGH
  digitalWrite(10, HIGH);
}

void Stop()
{
  digitalWrite(8, LOW);                              //       If you dont get proper movements of your robot,
  digitalWrite(7, LOW);                              //        then alter the pin numbers
  digitalWrite(9, LOW);                              //
  digitalWrite(10, LOW);
}
