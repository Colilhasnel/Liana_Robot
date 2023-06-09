#define right_1 A2
#define center_1 A1
// #define right_2 A1
// #define right_3 A6
// #define right_4 A2
#define left_1 A0
// #define left_2 A4
// #define left_3 A7
// #define left_4 A5
#define built_in 13
#define motor_right_forward 3
#define motor_right_backward 5
#define motor_left_forward 6
#define motor_left_backward 9
int c1, l1, r1;

// 0 -> left , 1 -> right, 3 -> center
int minValues[3], maxValues[3];

int P, D, I, previousError = 0, PIDvalue, error;
int lsp, rsp;
int lfspeed = 175;

float Kp = 2;
float Kd = 0;
float Ki = 0;

int time_global;

void setup() {
  Serial.begin(9600);
  pinMode(built_in, OUTPUT);
  pinMode(motor_right_forward, OUTPUT);
  pinMode(motor_right_backward, OUTPUT);
  pinMode(motor_left_forward, OUTPUT);
  pinMode(motor_left_backward, OUTPUT);
  time_global = millis();
  delay(3000);
  blink_it(4, 200);
  calibrate(4000);
  delay(2000);
  blink_it(4, 500);
}

void loop() {
  l1 = analogRead(left_1);
  c1 = analogRead(center_1);
  r1 = analogRead(right_1);

  l1 = (1023 * (l1 - minValues[0])) / (maxValues[0] - minValues[0]);
  r1 = (1023 * (r1 - minValues[1])) / (maxValues[1] - minValues[1]);
  c1 = (1023 * (c1 - minValues[2])) / (maxValues[2] - minValues[2]);

  while (c1 > 512) {
    motor_control(-125, -125);
  }
  while (c1 <= 512) {

    error = l1 - r1;
    P = error;
    I = I + error;
    D = error - previousError;

    PIDvalue = (Kp * P) + (Kd * D) + (Ki * I);
    previousError = error;

    lsp = lfspeed - PIDvalue;
    rsp = lfspeed + PIDvalue;

    if (lsp > 255) {
      lsp = 255;
    }
    if (lsp < 0) {
      lsp = 0;
    }
    if (rsp > 255) {
      rsp = 255;
    }
    if (rsp < 0) {
      rsp = 0;
    }

    motor_control(lsp, rsp);
    // }
    // derivative = derivative - error * time;
    // integral = integral + error * time;

    // output = kp * error + ki * integral + kd * derivative;

    // if (output < 0)
    //   analogWrite(motor_left_forward, min((-1) * output, 225));
    // else
    //   analogWrite(motor_right_forward, min(225, output));
  }
}

void motor_control(int left, int right) {
  analogWrite(motor_right_forward, 0);
  analogWrite(motor_right_backward, 0);
  analogWrite(motor_left_forward, 0);
  analogWrite(motor_left_backward, 0);
  if (left < 0)
    analogWrite(motor_left_backward, (-1) * left);
  else
    analogWrite(motor_left_forward, left);
  if (right < 0)
    analogWrite(motor_right_backward, (-1) * right);
  else
    analogWrite(motor_right_forward, right);
}

void blink_it(int num, int time) {
  digitalWrite(built_in, LOW);
  for (int i = 0; i < num; i++) {
    digitalWrite(built_in, HIGH);
    delay(time);
    digitalWrite(built_in, LOW);
    delay(time);
  }
}

void calibrate(int time_calibrate) {
  for (int i = 0; i < 3; i++) {
    minValues[i] = INT32_MAX;
    maxValues[i] = INT32_MIN;
  }
  motor_control(200, -200);
  int local_time = millis();
  int elapsed_time;

  do {
    r1 = analogRead(right_1);
    l1 = analogRead(left_1);
    c1 = analogRead(center_1);
    minValues[0] = min(minValues[0], l1);
    minValues[1] = min(minValues[1], r1);
    minValues[2] = min(minValues[2], c1);


    maxValues[0] = max(maxValues[0], l1);
    maxValues[1] = max(maxValues[1], r1);
    maxValues[2] = max(maxValues[2], c1);

    elapsed_time = millis() - local_time;
  } while (elapsed_time < time_calibrate);

  motor_control(0, 0);
}