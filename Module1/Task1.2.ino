const int pirPin = 2;   
const int ledPin = 13;  
volatile bool motionDetected = false;  

void motionISR() {
    motionDetected = true;  
}

void setup() {
    Serial.begin(9600);
    pinMode(pirPin, INPUT);
    pinMode(ledPin, OUTPUT);
    
    attachInterrupt(digitalPinToInterrupt(pirPin), motionISR, RISING);
}

void loop() {
    if (motionDetected) {
        Serial.println("Motion detected!");
        digitalWrite(ledPin, HIGH);
        delay(2000);  
        digitalWrite(ledPin, LOW);
        motionDetected = false;  
    }
}
