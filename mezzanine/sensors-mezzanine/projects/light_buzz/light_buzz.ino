//pins used for components
const int buzzer = 4;   // Arduino port pin PD4
const int sensor = A0;  // Arduino analog ping ADC0


//this is the threshold value for the light sensor
//to make the light sensor more sensitive, lower this value
int thresholdVal = 400;

void setup(){
        pinMode(sensor, INPUT);  // set pin for button input
        pinMode(buzzer, OUTPUT); // set pin for buzzer output
}

void loop() {
        int sensorVal = analogRead(sensor);
        if (sensorVal < thresholdVal)
                digitalWrite(buzzer, HIGH);
        else
                digitalWrite(buzzer, LOW);
}

