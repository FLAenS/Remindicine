const int analogPin = A5;  // Replace with your ADC pin
const int led = 9;
const int buzzer = 8;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // Read the analog value from the light sensor
  int Lux = analogRead(analogPin);
  if (Lux < 1000){
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else{
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  // Delay before the next reading
  delay(500);
}