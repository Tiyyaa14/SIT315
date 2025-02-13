const int pirPin = 2;    
const int tiltPin = 3;   
const int motionLed = 8; 
const int tiltLed = 9;   

volatile bool motionDetected = false;
volatile bool tiltDetected = false;


void motionISR() {
    motionDetected = true;
}

void tiltISR() {
    tiltDetected = true;
}

void setup() {
    Serial.begin(9600);
    Serial.println("Setup complete");

    pinMode(pirPin, INPUT);
    pinMode(tiltPin, INPUT_PULLUP);  
   pinMode(motionLed, OUTPUT);
    pinMode(tiltLed, OUTPUT);

    
    attachInterrupt(digitalPinToInterrupt(pirPin), motionISR, RISING);
    attachInterrupt(digitalPinToInterrupt(tiltPin), tiltISR, FALLING);
}

void loop() {
    if (motionDetected) {
        Serial.println("Motion detected!");
        digitalWrite(motionLed, HIGH);  
        delay(2000);                    
        digitalWrite(motionLed, LOW);   
        motionDetected = false;
    }

    if (tiltDetected) {
        Serial.println("Tilt detected!");
        digitalWrite(tiltLed, HIGH);    
        delay(2000);                    
        digitalWrite(tiltLed, LOW);     
        tiltDetected = false;
    }

    delay(500);
}
