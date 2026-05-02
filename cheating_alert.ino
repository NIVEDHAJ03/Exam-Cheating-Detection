int led = 8;
int buzzer = 9;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.println("System Ready");
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();

    Serial.print("Received: ");
    Serial.println(data);

    if (data == '1') {
      digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("ALERT: Cheating Detected");
    }

    else if (data == '0') {
      digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);
      Serial.println("System Normal");
    }
  }
}
