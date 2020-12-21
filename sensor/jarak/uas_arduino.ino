int trig_pin = 6;
int echo_pin = 7;
long echotime; 
float distance;

//led
int ledKuning = 11, ledHijau = 10, ledMerah = 9, ledBiru = 8;
 
void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT); 
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);  
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledBiru, OUTPUT);
}
 
void loop() {
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  echotime= pulseIn(echo_pin, HIGH);
  distance= 0.0001*((float)echotime*340.0)/2.0;
//  Serial.print(distance);
//  Serial.println(" cm"); 
  digitalWrite(ledKuning, 0);
  digitalWrite(ledHijau, 0);
  digitalWrite(ledMerah, 0);
  digitalWrite(ledBiru, 0);
  if(distance < 50) {
    digitalWrite(ledHijau, 1);
    Serial.print(distance);
    Serial.println(" cm"); 
    Serial.print("LED Hijau Nyala");
  } else if(distance >= 50 && distance < 100) {
    digitalWrite(ledMerah, 1);
    Serial.print(distance);
    Serial.println(" cm"); 
    Serial.print("LED Merah Nyala");
  } else if(distance >= 100) {
    digitalWrite(ledBiru, 1);
    digitalWrite(ledKuning, 1);
    Serial.print(distance);
    Serial.println(" cm"); 
    Serial.print("LED Kuning dan Biru Nyala");
  } 
  delay(100);
}
