// Pin mappings
const int PIN_LIGHT = 2;
const int PIN_TRIG = 3;
const int PIN_ECHO = 4;
const int PIN_BUZZ = 5;
const int PIN_LIGHT_TWO = 6;
// Declaring duration and distance
long duration;
float distance;
// Minimum distance
const int safetyDistance = 20;
// Input/output mappings
 void setup() {
  pinMode(PIN_LIGHT, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_BUZZ, OUTPUT);
  pinMode(PIN_LIGHT_TWO, OUTPUT);
  Serial.begin(9600);
}
void loop() {
 // Writing input from trig pin 
 digitalWrite(PIN_TRIG, LOW);
 delayMicroseconds(2);
 digitalWrite(PIN_TRIG, HIGH);
 delayMicroseconds(10);
 digitalWrite(PIN_TRIG, LOW);
 // Current distance calculation 
 duration = pulseIn(PIN_ECHO, HIGH);
 distance = duration * 0.034 / 2;
 // Prints distance on serial monitor (in cm)
 Serial.print("Distance: ");
 Serial.print(distance);
 Serial.print(" cm");
 // If distance is a positive floating point number AND it is more than the safety distance, alarm goes off
 if (distance > 0 && distance < safetyDistance) {
    digitalWrite(PIN_LIGHT, HIGH);   
    digitalWrite(PIN_LIGHT_TWO, LOW); 
    tone(PIN_BUZZ, 1000); 
 // If previous conditions are not true, alarm is not on
  } else {
    digitalWrite(PIN_LIGHT, LOW); 
    digitalWrite(PIN_LIGHT_TWO, HIGH);    
    noTone(PIN_BUZZ);  
  }
 // Millisecond delay for reduced lag 
  delay(100);
}
