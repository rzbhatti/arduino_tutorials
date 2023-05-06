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

int speed;
char receivedChar;
boolean newData = false;

bool f = true;

void setup()
{
  // Used to display information
  Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }
  speed = 255;
  // Set initial speed for both motors
  motors.setSpeed(speed);
  Serial.println("Motors read....");
}

void loop()
{
  recvOneChar();
  if (newData == true) {
    switch (receivedChar) {
      case 's':
        motors.stop();
        Serial.println("Motors stopped...");
        break;
      case 'b':
        motors.stop();
        delay(1000);
        motors.setSpeed(speed);
        f = false;
        motors.backward();
        Serial.print("Backward, @ Speed :"); Serial.println(speed);
        break;
      case 'f':
        motors.stop();
        delay(1000);
        motors.setSpeed(speed);
        f = true;
        motors.forward();
        Serial.print("Forward, @ Speed :"); Serial.println(speed);
        break;
        break;
      case 'r':
        motors.stop();
        delay(1000);
        Serial.print("Speed reset, @ Speed :"); Serial.println(speed);
        speed = 255;
        motors.setSpeed(speed);
        break;
      case 'i':
        if (speed <= 245){
          speed += 10;
          Serial.print("Speed increased, @ Speed :"); Serial.println(speed);
          motors.setSpeed(speed);
          if (f) 
            motors.forward();
          else
            motors.backward();

        }
        break;
      case 'd':
        if (speed > 80){
          speed -= 10;
          Serial.print("Speed decreades, @ Speed :"); Serial.println(speed);
          motors.setSpeed(speed);
          if (f) 
            motors.forward();
          else
            motors.backward();
        }
        break;
      default:
        break;
    }
    newData = false;
  }

}


void recvOneChar() {
    if (Serial.available() > 0) {
        receivedChar = Serial.read();
        newData = true;
    }
}


