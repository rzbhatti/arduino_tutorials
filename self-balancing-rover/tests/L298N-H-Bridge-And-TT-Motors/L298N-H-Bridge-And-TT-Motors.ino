#include <L298NX2.h>

// Pin definition
#define EN_A 5
#define IN1_A 6
#define IN2_A 7
#define IN1_B 2
#define IN2_B 4
#define EN_B 3

// Initialize both motors
L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

void setup()
{
  // Used to display information
  Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }

  // Set initial speed for both motors
  motors.setSpeed(80);
}

void loop()
{
  // Tell both motors to go forward (may depend by your wiring)
  motors.forward();

  // Alternative method:
  // motors.run(L298N::FORWARD);

  //print the motor status in the serial monitor
  printSomeInfo();

  delay(3000);

  // Stop
  motors.stop();

  // Alternative method:
  // motors.run(L298N::STOP);

  printSomeInfo();

  delay(3000);

  // Change individual speeds
  motors.setSpeedA(255);
  motors.setSpeedB(90);

  // Tell motor A to go back (may depend by your wiring)
  motors.backwardA();

  // Alternative method:
  // motors.runA(L298N::BACKWARD);

  // Tell motor B to go forward (may depend by your wiring)
  motors.backwardB();

  // Alternative method:
  // motors.runB(L298N::FORWARD);

  printSomeInfo();

  delay(3000);

  // Stop
  motors.stop();

  printSomeInfo();

  // Change individual speeds
  motors.setSpeedA(90);
  motors.setSpeedB(255);

  delay(5000);
}

/*
Print some informations in Serial Monitor
*/
void printSomeInfo()
{
  Serial.print("Motor A is moving = ");
  Serial.print(motors.isMovingA() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(motors.getSpeedA());
  Serial.print("Motor B is moving = ");
  Serial.print(motors.isMovingB() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(motors.getSpeedB());
}