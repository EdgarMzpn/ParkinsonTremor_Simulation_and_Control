// Define PWM pins for motor controll
const int right_wheel_f = 5;
const int right_wheel_b = 4;

const int left_wheel_f = 3;
const int left_wheel_b = 2;

// Random variables to simulate vibration
int motor_speed = 0;
int sleep = 0;
int go_forward;

void move_forward(int motor_speed){
  analogWrite(right_wheel_f, motor_speed);
  analogWrite(right_wheel_b, 0);

  analogWrite(left_wheel_f, motor_speed);
  analogWrite(left_wheel_b, 0);
}

void move_backwards(int motor_speed){
  analogWrite(right_wheel_f, 0);
  analogWrite(right_wheel_b, motor_speed);

  analogWrite(left_wheel_f, 0);
  analogWrite(left_wheel_b, motor_speed);
}

void setup() {
  // Initialize the PWM pin as an output
  pinMode(right_wheel_f, OUTPUT);
  pinMode(right_wheel_b, OUTPUT);
}

void loop() {
  motor_speed = random(150, 255);
  sleep = random(50, 250);

  if (go_forward == 1){
    move_forward(motor_speed);
    go_forward = 0;
  }
  else{
    move_backwards(motor_speed);
    go_forward = 1;
  }

  delay(sleep);
}
