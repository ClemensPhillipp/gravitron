const int GSM1 = 3;
#define In1 5
#define In2 6

const int spinning_time = 10000;
const int pause_time = 5000;
const int max_spinning_speed = 255;

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(GSM1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(pause_time);
  spin();
  delay(max_spinning_speed);
  stopSpin();
}

void stopSpin() {
  for (int i = max_spinning_speed; i >= 0; i--) {
    analogWrite(GSM1, i);
    delay(50);
  }

  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
}

void spin() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  for (int i = 0; i <= max_spinning_speed; i++) {
    analogWrite(GSM1, i);
    delay(50);
  }
}
