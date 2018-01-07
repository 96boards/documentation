const int buttonPin = 4;
const int ledPin = 3;
const int buzzerPin = 5;

void setup() {
	pinMode(buttonPin, INPUT);
	pinMode(ledPin, OUTPUT);
	pinMode(buzzerPin, OUTPUT);
	Serial.begin(115200);
	Serial.println("waiting");
}

void loop() {
 	int pressed = digitalRead(buttonPin);
	if (pressed == 1) {
 		digitalWrite(ledPin, HIGH);
		Serial.println("tweet");
		delay(1000);
		digitalWrite(ledPin, LOW);
	}
}
