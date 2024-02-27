#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(10, 11); // RX, TX
const int vibrationPin = 2;

void setup() {
  Serial.begin(9600);
  gsmSerial.begin(9600);
  pinMode(vibrationPin, INPUT);
}

void loop() {
  int vibrationValue = digitalRead(vibrationPin);
  if (vibrationValue == HIGH) {
    sendSMS();
    delay(10000); // Wait 10 seconds before sending another SMS
  }
}

void sendSMS() {
  gsmSerial.println("AT+CMGF=1"); // Set SMS mode to text
  delay(1000);
  gsmSerial.println("AT+CMGS=\"+254719738140\""); // Replace +1234567890 with the phone number you want to send the SMS to
  delay(1000);
  gsmSerial.println("Vibration detected!"); // Replace "Vibration detected!" with the message you want to send
  delay(1000);
  gsmSerial.println((char)26); // Send Ctrl+Z to indicate the end of the message
  delay(1000);
}
