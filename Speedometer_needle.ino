#include <Servo.h>

Servo myservo; // Create a servo object

// Define the input pins for the circuit
const int input1 = 2;
const int input2 = 3;
const int input3 = 4;
const int input4 = 5;

// Define the servo angles for specific inputs
const int angle_0000 = 0;   // For input 0000
const int angle_0001 = 30;  // For input 0001
const int angle_0011 = 70;  // For input 0011
const int angle_0111 = 110; // For input 0111
const int angle_1111 = 150; // For input 1111

void setup() {
  myservo.attach(9); // Attach the servo to pin 9

  // Set input pins as inputs
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);

  // Initialize servo to 0 degrees
  myservo.write(angle_0000);
}

void loop() {
  // Read the inputs
  int bit1 = digitalRead(input1);
  int bit2 = digitalRead(input2);
  int bit3 = digitalRead(input3);
  int bit4 = digitalRead(input4);

  // Determine the binary value from the inputs
  int binaryValue = (bit4 << 3) | (bit3 << 2) | (bit2 << 1) | bit1;

  // Set the servo angle based on the binary value
  switch (binaryValue) {
    case 0b0000:
      myservo.write(angle_0000);
      break;
    case 0b0001:
      myservo.write(angle_0001);
      break;
    case 0b0011:
      myservo.write(angle_0011);
      break;
    case 0b0111:
      myservo.write(angle_0111);
      break;
    case 0b1111:
      myservo.write(angle_1111);
      break;
    default:
      // Optional: handle invalid inputs (do nothing)
      break;
  }

  // Delay for 500 ms
  delay(500);
}
