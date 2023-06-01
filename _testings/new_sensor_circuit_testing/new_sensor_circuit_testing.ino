#define right_1 A0
#define center A1
#define left_1 A2

int l1, l2, l3, l4, r1, r2, r3, r4, c1;

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
  int r1 = analogRead(right_1);
  // int r2 = analogRead(right_2);
  // int r3 = analogRead(right_3);
  // int r4 = analogRead(right_4);
  int l1 = analogRead(left_1);
  // int l2 = analogRead(left_2);
  // int l3 = analogRead(left_3);
  // int l4 = analogRead(left_4);
  int c1 = analogRead(center);
  Serial.print(l1);
  Serial.print(",");
  Serial.print(c1);
  Serial.print(",");
  // Serial.print(r2);
  // Serial.print(",");
  // Serial.print(r3);
  // Serial.print(",");
  // Serial.print(r4);
  // Serial.print(",");
  Serial.println(r1);
  // Serial.print(",");
  // Serial.print(l2);
  // Serial.print(",");
  // Serial.print(l3);
  // Serial.print(",");
  // Serial.println(l4);
}
