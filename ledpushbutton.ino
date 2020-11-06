int ledPin = 13; // choose the pin for the LED
int ledMerah = 10;
int ledKuning = 12;
int ledHijau = 11;
int switchPin =7; // choose the input pin (for a pushbutton)
int val = 0; // variable for reading the pin status
int counter = 0;
int currentState = 0;
int previousState = 0;

void setup() {
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(switchPin, INPUT); // declare pushbutton as input
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  Serial.begin(9600);
}

void loop(){
val = digitalRead(switchPin); // read input value
if (val == HIGH) { // check if the input is HIGH (button released)
  digitalWrite(ledPin, HIGH); // turn LED on
  if(counter == 3){
    counter = 0;
    digitalWrite(ledMerah, 1);
    digitalWrite(ledKuning, 0);
    digitalWrite(ledHijau, 0);
  }
  currentState = 1;
} else {
  digitalWrite(ledPin, LOW); // turn LED off
  currentState = 0;
}
if(currentState != previousState){
  if(currentState == 1){
    counter += 1;
    Serial.println(counter);
  }
}
setLED(counter);
previousState = currentState;
delay(200);
}
void setLED(int counter){
  switch (counter) {
    case 1:
    	digitalWrite(ledMerah, 1);
    break;
    case 2:
    	digitalWrite(ledKuning, 1);
    break;
    case 3:
    	digitalWrite(ledHijau, 1);
    break;
    default:
    break;
  }
}
