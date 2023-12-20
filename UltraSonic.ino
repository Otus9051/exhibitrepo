// Pin Definitions
const int trigPin = 5;
const int echoPin = 6;
const int redLedPin = 13;
const int greenLedPin = 4;
const int blueLedPin = 7;
const int whiteLedPin = 11;
const int gndOnDig1 = 2;
const int gndOnDig2 = 8;
const int gndOnDig3 = 12;

// Variables
long duration;
int distance;

void setup() {
    // Initialize Serial Monitor
    Serial.begin(9600);

    // Set pin modes
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(redLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(blueLedPin, OUTPUT);
    pinMode(whiteLedPin, OUTPUT);
    pinMode(gndOnDig1, OUTPUT);
    pinMode(gndOnDig2, OUTPUT);
    pinMode(gndOnDig3, OUTPUT);
}

void loop() {
    // Trigger the ultrasonic sensor
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 
    
    // Ground on Digital Pins
    digitalWrite(gndOnDig1, LOW);
    digitalWrite(gndOnDig2, LOW);
    digitalWrite(gndOnDig3, LOW);

    // Measure the duration of the echo pulse
    duration = pulseIn(echoPin, HIGH);

    // Calculate the distance in centimeters
    distance = duration * 0.034 / 2;

    // Print the distance to Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Control the LEDs based on the distance
    if (distance >= 20) {
        digitalWrite(redLedPin, HIGH);
        digitalWrite(blueLedPin, LOW);
        digitalWrite(greenLedPin, LOW);
        analogWrite(whiteLedPin, 10);
    } else if (distance <= 19 && distance >= 10) {
        digitalWrite(redLedPin, LOW);
        digitalWrite(blueLedPin, HIGH);
        digitalWrite(greenLedPin, LOW);
        analogWrite(whiteLedPin, 50);
    } else if (distance <= 9) {
        digitalWrite(redLedPin, LOW);
        digitalWrite(blueLedPin, LOW);
        digitalWrite(greenLedPin, HIGH);
        analogWrite(whiteLedPin, 255);
    }

    // Delay before next measurement
    delay(500);
}
