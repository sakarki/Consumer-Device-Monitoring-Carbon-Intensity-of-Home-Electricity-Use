#include <dummy.h>

#include <WiFi.h>
#include "HTTPClient.h"
#define IO14 14
#define IO13 13
#define IO12 12
#define SPEAKER 25
#define CONNECTION_TIMEOUT 10

const char* ssid = "ece445";
const char* password = "ece445team";

void setup() {
  // put your setup code here, to run once:
  pinMode(SPEAKER, OUTPUT);
  pinMode(IO14, OUTPUT); // Set the LED pin as an output
  pinMode(IO13, OUTPUT); // Set the LED pin as an output
  pinMode(IO12, OUTPUT); // Set the LED pin as an output

  Serial.begin(115200);
  delay(1000);
  int timeout_counter = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi...");
    delay(500);
    
    timeout_counter++;
        if(timeout_counter >= CONNECTION_TIMEOUT*5){
        ESP.restart();
    }
  }

  Serial.println("Connected to WiFi");

}

void loop() {
  // put your main code here, to run repeatedly:
  fetchData();
  sound();
  analogWrite(IO14, 255);
  analogWrite(IO13, 255);
  analogWrite(IO12, 255);
}

void sound() {
  tone(SPEAKER, 440, 1000); // Play a 440 Hz tone for 1 second
  delay(1000); // Wait for a second
}

void fetchData() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;   // Object to manage HTTP requests

    http.begin("https://api.carbonintensity.org.uk/intensity"); // API
    http.addHeader("Accept", "application/json"); // Set the content type of the request

    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.println("Error on HTTP request");
    }

    http.end();
  } else {
    Serial.println("Error in WiFi connection");
  }
}
