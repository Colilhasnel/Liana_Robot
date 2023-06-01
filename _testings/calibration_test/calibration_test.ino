#define right_1 A0
#define right_2 A1
#define right_3 A6
#define right_4 A2
#define left_1 A3
#define left_2 A4
#define left_3 A7
#define left_4 A5
#define built_in 13

double l1, l2, l3, l4, r1, r2, r3, r4;
double error_l1 = 0, error_r1 = 0, k = 0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  delay(3000);
  for (int i = 0; i < 4; i++) {
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
  }
  delay(1000);
}

void loop() {
  r1 = analogRead(right_1);
  r2 = analogRead(right_2);
  r3 = analogRead(right_3);
  r4 = analogRead(right_4);
  l1 = analogRead(left_1);
  l2 = analogRead(left_2);
  l3 = analogRead(left_3);
  l4 = analogRead(left_4);

  Serial.print(r1);
  Serial.print(",");
  Serial.print(r2);
  Serial.print(",");
  Serial.print(r3);
  Serial.print(",");
  Serial.print(r4);
  Serial.print(",");
  Serial.print(l1);
  Serial.print(",");
  Serial.print(l2);
  Serial.print(",");
  Serial.print(l3);
  Serial.print(",");
  Serial.println(l4);
  // k += 1;
}

// void calibrate(int time) {
//   int begin, curr;
//   begin = curr = millis();
//   while (begin + time >= curr) {
//     l1 = analogRead(sensor_left_1);
//     // l2 = analogRead(sensor_left_2);
//     // l3 = analogRead(sensor_left_3);
//     r1 = analogRead(sensor_right_1);
//     // r2 = analogRead(sensor_right_2);
//     // r3 = analogRead(sensor_right_3);
//     sensor_min_l1 = min(sensor_min_l1, l1);
//     sensor_max_l1 = max(sensor_max_l1, l1);
//     // sensor_min = min(sensor_min, l2);
//     // sensor_min = min(sensor_min, l3);
//     sensor_min_r1 = min(sensor_min_r1, r1);
//     sensor_max_r1 = max(sensor_max_r1, r1);
//     // sensor_min = min(sensor_min, r2);
//     // sensor_min = min(sensor_min, r3);
//     curr = millis();
//   }
// }

void blink_it(int num, int time) {
  digitalWrite(built_in, LOW);
  for (int i = 0; i < num; i++) {
    digitalWrite(built_in, HIGH);
    delay(time);
    digitalWrite(built_in, LOW);
    delay(time);
  }
}
