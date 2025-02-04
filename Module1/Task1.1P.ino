const int pirPin = 2;   
const int ledPin = 13;  

void setup() {
    pinMode(pirPin, INPUT);   
    pinMode(ledPin, OUTPUT); 
    Serial.begin(9600);       
}

void loop() {
    int motionDetected = digitalRead(pirPin); 

    if (motionDetected == HIGH) {
        digitalWrite(ledPin, HIGH); 
        Serial.println("Motion detected: LED ON");
    } else {
        digitalWrite(ledPin, LOW); 
        Serial.println("No motion: LED OFF");
    }

    delay(500); 
}
