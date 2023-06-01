#define motor_right_forward 3
#define motor_right_backward 5
#define motor_left_forward 6
#define motor_left_backward 9
#define built_in 13


void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);
  digitalWrite(13, LOW);

  analogWrite(motor_left_forward, 255);

  // delay(2000);
  // blink_it(4, 300);
  // for (int i = 100; i <= 255; i += 25) {
  //   motor_control(i, i);
  //   delay(3000);
  //   blink_it(3, 200);
  // }
  // motor_control(0, 0);
}

//   delay(2000);
//   blink_it(4, 300);
//   for (int i = 100; i <= 255; i += 25) {
//     motor_control(-i, i);
//     delay(3000);
//     blink_it(3, 200);
//   }
//   motor_control(0, 0);

//   delay(2000);
//   blink_it(4, 300);
//   for (int i = 100; i <= 255; i += 25) {
//     motor_control(i, -i);
//     delay(3000);
//     blink_it(3, 200);
//   }
//   motor_control(0, 0);

//   delay(2000);
//   blink_it(4, 300);
//   for (int i = 100; i <= 255; i += 25) {
//     motor_control(-i, -i);
//     delay(3000);
//     blink_it(3, 200);
//   }
//   motor_control(0, 0);
// }




void loop() {
}

void motor_control(int left, int right) {
  analogWrite(motor_right_forward, 0);
  analogWrite(motor_right_backward, 0);
  analogWrite(motor_left_forward, 0);
  analogWrite(motor_left_backward, 0);
  // analogWrite(motor_right_forward, 225);
  // analogWrite(motor_left_forward, 225);
  // delay(20);
  //   // analogWrite(motor_right_forward, 0);
  //   // analogWrite(motor_left_forward, 0);
  // if (left == 0 && right == 0)
  //   return;
  // else if (left == 0) {
  //   if (right > 0) {
  //     analogWrite(motor_right_forward, 255);
  //     delay(10);
  //     analogWrite(motor_right_forward, right);
  //   } else if (right < 0) {
  //     analogWrite(motor_right_backward, 255);
  //     delay(10);
  //     analogWrite(motor_right_backward, (-1) * right);
  //   }
  // } else if (right == 0) {
  //   if (left > 0) {
  //     analogWrite(motor_left_forward, 255);
  //     delay(10);
  //     analogWrite(motor_left_forward, left);
  //   } else if (left < 0) {
  //     analogWrite(motor_left_backward, 255);
  //     delay(10);
  //     analogWrite(motor_left_backward, (-1) * left);
  //   }
  // } else if (left > 0 && right > 0) {
  //   analogWrite(motor_left_forward, 255);
  //   analogWrite(motor_right_forward, 255);
  //   delay(10);
  //   analogWrite(motor_left_forward, left);
  //   analogWrite(motor_right_forward, right);
  // } else if (left < 0 && right < 0) {
  //   analogWrite(motor_left_backward, 255);
  //   analogWrite(motor_right_backward, 255);
  //   delay(10);
  //   analogWrite(motor_left_backward, (-1) * left);
  //   analogWrite(motor_right_backward, (-1) * right);
  // } else if (left < 0 && right > 0) {
  //   analogWrite(motor_left_backward, 255);
  //   analogWrite(motor_right_forward, 255);
  //   delay(10);
  //   analogWrite(motor_left_backward, (-1) * left);
  //   analogWrite(motor_right_forward, right);
  // } else if (left > 0 && right < 0) {
  //   analogWrite(motor_left_forward, 255);
  //   analogWrite(motor_right_backward, 255);
  //   delay(10);
  //   analogWrite(motor_left_forward, left);
  //   analogWrite(motor_right_backward, (-1) * right);
  // }
    if (left < 0) {
      // analogWrite(motor_left_backward, 225);
      // delay(10);
      analogWrite(motor_left_backward, (-1) * left);
    } else {
      // analogWrite(motor_left_forward, 225);
      // delay(10);
      analogWrite(motor_left_forward, left);
    }
    if (right < 0) {
      // analogWrite(motor_right_backward, 225);
      // delay(10);
      analogWrite(motor_right_backward, (-1) * right);
    } else {
      // analogWrite(motor_right_forward, 10);
      // delay(10);
      analogWrite(motor_right_forward, right);
  }
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