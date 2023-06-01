#define LEFT_2 A3
#define LEFT_1 A2
#define RIGHT_1 A1
#define RIGHT_2 A0
#define MOTOR_L 5
#define MOTOR_R 6
#define BUTTON A5
int mx = INT8_MIN;
int button = 0;
int kp = 225 / 2;

void setup()
{
  pinMode(MOTOR_L, OUTPUT);
  pinMode(MOTOR_R, OUTPUT);
  while (button < 100) {
    button = analogRead(BUTTON);
  }
  button = 0;
  calibrate();
  mx -= 50;
  while (button < 100) {
    button = analogRead(BUTTON);
  }
}

void loop()
{
  int error = position();
  int output = min(0, 225 - abs(error) * kp);
  if (error == 0) {
    analogWrite(MOTOR_R, 255);
    analogWrite(MOTOR_L, 255);
  } else if (error < 0 ) {
    analogWrite(MOTOR_L, output);
  } else {
    analogWrite(MOTOR_R, output);
  }
}

void calibrate() {
  while (button < 100) {
    int val = analogRead(LEFT_2);
    mx = max(mx, val);
    val = analogRead(LEFT_1);
    mx = max(mx, val);
    val = analogRead(RIGHT_1);
    mx = max(mx, val);
    val = analogRead(RIGHT_2);
    mx = max(mx, val);
    button = analogRead(BUTTON);
  }
  button = 0;
}

int position() {
  int left2 = analogRead(LEFT_2);
  int left1 = analogRead(LEFT_1);
  int right1 = analogRead(RIGHT_1);
  int right2 = analogRead(RIGHT_2);
  return (left1 >= mx) * (-1) + (left2 >= mx) * (-1) + (right1 >= mx) + (right2 >= mx);
}
