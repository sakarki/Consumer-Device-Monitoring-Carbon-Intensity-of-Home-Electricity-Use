#include <dummy.h>
#include <Base64.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoHttpClient.h>
#include <ArduinoJson.h>


#define IO14 14
#define IO13 13
#define IO12 12
#define SPEAKER 25
#define CONNECTION_TIMEOUT 1

int pwmChannel3 = 3; // Selects channel 0 for GPIO14 blue
int pwmChannel2 = 2; // GPIO13 green
int pwmChannel1 = 1; // GPIO12 red

// WiFi Credentials
const char* ssid = "ece445";
const char* password = "ece445team";

// API Information
const char* host = "api.watttime.org";
const int httpsport = 443;

// API Paths
const char* loginPath = "/login";
const char* dataPath = "/v3/signal-index";

// API Credentials
const char* username = "bghimire2001";
const char* passwordAPI = "Ece445!carbonproject";

// WiFiClientSecure for HTTPS
WiFiClientSecure client;

//HttpClient client = HttpClient(wifiClient, serverAddress, httpsPort);

#define frequency 60 // PWM frequency of 60 Hz
#define resolution 8 // 8-bit resolution, 256 possible values
#define dutyCycle 30 // Duty cycle to produce 50% duty cycle (3.3V)

void setup() {
  // put your setup code here, to run once:
  pinMode(SPEAKER, OUTPUT);
  pinMode(IO14, OUTPUT);
  pinMode(IO13, OUTPUT);
  pinMode(IO12, OUTPUT);

  //
  ledcSetup(pwmChannel1, frequency, resolution);
  ledcSetup(pwmChannel2, frequency, resolution);
  ledcSetup(pwmChannel3, frequency, resolution);

  // Assigns the PWM channels to respective GPIO pins
  ledcAttachPin(IO14, pwmChannel3); // GPIO14
  ledcAttachPin(IO13, pwmChannel2); // GPIO13
  ledcAttachPin(IO12, pwmChannel1); // GPIO12

  ledcWrite(pwmChannel1, 0); //no lights
  ledcWrite(pwmChannel2, 0);
  ledcWrite(pwmChannel3, 0);



  Serial.begin(9600);
  delay(1000);
  int timeout_counter = 0;
  WiFi.begin(ssid, password);

  Serial.println("Hello World"); //
  WiFi.mode(WIFI_STA);
  while (WiFi.begin() != WL_CONNECTED) {
    Serial.println("Hello World wifi connecting");
    delay(1000);
    timeout_counter++;
    if (timeout_counter >= CONNECTION_TIMEOUT * 5) {
      Serial.println("Hello World timeout");
      ESP.restart();
    }
  }

}
String getCarbonData() {
  Serial.println("Hello World GetCarbonData");
  client.setInsecure(); // Only use this in a trusted network environment

  if (!client.connect("api.watttime.org", 443)) {
    Serial.println("Connection failed");
    return (" ");
  }

  // Prepare Basic Auth header using Base64 encoding
  String auth = String(username) + ':' + String(passwordAPI);
  String encodedAuth = base64::encode(auth);

  // Make the login request
  client.println("GET /login HTTP/1.1");
  client.println("Host: " + String("api.watttime.org"));
  client.println("Authorization: Basic " + encodedAuth);
  client.println("Connection: close");
  client.println();

  // Wait for the response and capture the token
  String token;
  while (client.connected() || client.available()) {
    String line = client.readStringUntil('\n');
    if (line.startsWith("{\"token\":")) {
      int tokenStart = line.indexOf("token\":\"") + 8;
      int tokenEnd = line.indexOf("\"", tokenStart);
      token = line.substring(tokenStart, tokenEnd);
      break;
    }
    //Serial.println("loop");
  }
  Serial.println(token);

  if (token.length() == 0) {
    Serial.println("Failed to get token");
    return (" ");
  }

  // Make the API request using the token
  if (!client.connect(host, httpsport)) {
    Serial.println("Reconnection failed");
    return (" ");
  }

  client.println("GET /v3/signal-index?region=CAISO_NORTH&signal_type=co2_moer HTTP/1.1");
  client.println("Host: " + String(host));
  client.println("Authorization: Bearer " + token);
  client.println("Connection: close");
  client.println();

  // Print the response

  String jsonResponse;
  while (client.connected() || client.available()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {  // Start capturing the next line as it's the response body
      jsonResponse = client.readStringUntil('\n');
      break;
    }
  }

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, jsonResponse);
  float value = doc["data"][0]["value"];  // Access the value field
  Serial.print("Extracted value: ");
  return (String(value));
  Serial.println(value);


  /*
    int statusCode = client.responseStatusCode();

    if (statusCode != 200) {
    return "Error: Login Failed with status code " + String(statusCode);
    }
    Serial.println("parse JSON");
    // Parse JSON and extract token
    String response = client.responseBody();
    StaticJsonDocument<400> doc;
    deserializeJson(doc, response);
    String token = doc["token"];

    // Use token to request data
    client.beginRequest();
    client.get(dataPath + String("?region=CAISO_NORTH&signal_type=co2_moer"));
    client.sendHeader("Authorization", "Bearer " + token);
    client.endRequest();
    Serial.println("Hello World request data");
    statusCode = client.responseStatusCode();
    if (statusCode == 200) {
    response = client.responseBody();
    deserializeJson(doc, response);
    if (doc["data"].size() > 0 && !doc["data"][0]["value"].isNull()) {
      String value = doc["data"][0]["value"].as<String>();
      return value;
    } else {
      return "Error: Data field missing or null";
      Serial.println("Error: Data field missing or null");
    }
    } else {
    return "Error: Data retrieval failed with status code " + String(statusCode);
    Serial.println( "Error: Data retrieval failed with status code ");
    }
  */
}
/*
  void low_sound() {
  int freq = 20000 - valueInt*20
  tone(SPEAKER, freq, 1000); // Play a 440 Hz tone for 1 second
  delay(1000); // Wait for a second
  Serial.println("high_sound");
  }

  void high_sound() {
  int freq = 200 + valueInt*16
  tone(SPEAKER, freq, 1000); // Play a 440 Hz tone for 1 second
  delay(1000); // Wait for a second
  Serial.println("high_sound");
  }
*/

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World loop");
  String carbonStringValue = getCarbonData();
  Serial.println(carbonStringValue);
  if (carbonStringValue.startsWith("Error")) {
    while (1) {
      //sound();
      ledcWrite(pwmChannel1, 0); //no lights
      ledcWrite(pwmChannel2, 0);
      ledcWrite(pwmChannel3, 0);
    }
  } else {
    int valueInt = carbonStringValue.toInt();
    Serial.println(valueInt); // Print the converted integer value
    if (valueInt > 0 && valueInt <= 50) {
      ledcWrite(pwmChannel3, 0);
      ledcWrite(pwmChannel2, 255); //
      ledcWrite(pwmChannel1, 255); //green
      Serial.println("Low");
      delay(1000);

      //play lower intensity sound ranges
      int freq = 2000 - valueInt * 20;
      tone(SPEAKER, freq, 30000); // Play a tone for 30 second
      delay(1000); // Wait for a second
      Serial.println("low_sound");
      freq = 0;
      noTone(SPEAKER);
    }
    else if (valueInt > 50) {
      ledcWrite(pwmChannel3, 255);
      ledcWrite(pwmChannel2, 0);
      ledcWrite(pwmChannel1, 0);
      Serial.println("High");
      delay(1000);

      //play higher intensity sounds
      int freq = 200 + valueInt * 16;
      tone(SPEAKER, freq, 30000); // Play a tone for 30 second
      delay(1000); // Wait for a second
      Serial.println("high_sound");
      freq = 0; 
      noTone(SPEAKER);
    }
    else {
      ledcWrite(pwmChannel1, 0); //no lights
      ledcWrite(pwmChannel2, 0);
      ledcWrite(pwmChannel3, 0);
      delay(1000);
    }
  }
  delay(30000); // Wait for 30 seconds
}
