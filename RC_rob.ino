#include <Servo.h>
#include <SoftwareSerial.h>
Servo myServo;
Servo myServo1;
int bluetoothTx = 10;
int bluetoothRx = 11;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void manualControlBluetooth(char command)
{
  switch (command)
  {
    case 'A': 
    myServo.write(180);
    myServo1.write(0);
      break;
    case 'B':
    myServo.write(0);
    myServo1.write(180);
      break;
    case 'C':
      break;
    case 'D':
      break;
    case 'E':
      break;
    case 'F':
    myServo.write(90);
    myServo1.write(90);
      break;
    case 'G':
      break;
    case 'H':
      break;
    case 'I':
      break;
  }
}
void setup()
{
  myServo.attach(6);
  myServo1.attach(7);
  Serial.begin(9600);
  Serial.println("Start");
  bluetooth.begin(9600);
}
void loop()
{
  {
    if (Serial.available() > 0)
    {
      char command = Serial.read();
      manualControlBluetooth(command);
      delay(20);
    }
    if (bluetooth.available() > 0)
    {
      char command = bluetooth.read();
      manualControlBluetooth(command);
      delay(20);
    }
  }
}
