#include <dummy.h>
#include <Base64.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoHttpClient.h>
#include <ArduinoJson.h>


#define IO14 14
#define IO13 13
#define IO12 12
#define SPEAKER 25
#define CONNECTION_TIMEOUT 10

int pwmChannel1 = 0; // Selects channel 0 for GPIO14
int pwmChannel2 = 0;
int pwmChannel3 = 0;

// WiFi Credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// API Information
const char* serverAddress = "api.watttime.org";
const int httpsPort = 443;

// API Paths
const char* loginPath = "/login";
const char* dataPath = "/v3/signal-index";

// API Credentials
const char* username = "bghimire2001";
const char* passwordAPI = "Ece445!carbonproject";

// WiFiClientSecure for HTTPS
WiFiClientSecure wifiClient;

HttpClient client = HttpClient(wifiClient, serverAddress, httpsPort);

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
  ledcAttachPin(14, pwmChannel3); // GPIO14
  ledcAttachPin(13, pwmChannel2); // GPIO13
  ledcAttachPin(12, pwmChannel1); // GPIO12
  

  Serial.begin(9600);
  delay(1000);
  int timeout_counter = 0;

  while (WiFi.begin(ssid, password) != WL_CONNECTED) {
    delay(1000);
    timeout_counter++;
    if (timeout_counter >= CONNECTION_TIMEOUT * 5) {
      ESP.restart();
    }
  }

}
String getCarbonData() {
  // Base64 encode username and password for basic auth
  String auth = username + String(":") + passwordAPI;
  auth = base64::encode(auth);

  // Setup HttpClient
  HttpClient client = HttpClient(wifiClient, serverAddress, httpsPort);
  client.beginRequest();
  client.get(loginPath);
  client.sendHeader("Authorization", "Basic " + auth);
  client.endRequest();

  int statusCode = client.responseStatusCode();
  if (statusCode != 200) {
    return "Error: Login Failed with status code " + String(statusCode);
  }

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

  statusCode = client.responseStatusCode();
  if (statusCode == 200) {
    response = client.responseBody();
    deserializeJson(doc, response);
    if (doc["data"].size() > 0 && !doc["data"][0]["value"].isNull()) {
      String value = doc["data"][0]["value"].as<String>();
      return value;
    } else {
      return "Error: Data field missing or null";
    }
  } else {
    return "Error: Data retrieval failed with status code " + String(statusCode);
  }
}
void sound() {
  tone(SPEAKER, 440, 1000); // Play a 440 Hz tone for 1 second
  delay(1000); // Wait for a second
}

void loop() {
  // put your main code here, to run repeatedly:
  String carbonStringValue = getCarbonData();
  if (carbonStringValue.startsWith("Error")) {
    while(1){
      sound();
    }
  } else {
    int valueInt = carbonStringValue.toInt();
    if(valueInt <= 10){
      ledcWrite(pwmChannel1, 255);
      ledcWrite(pwmChannel2, 0);
      ledcWrite(pwmChannel3, 0);
    } else if(valueInt > 10 && valueInt < 20){
      ledcWrite(pwmChannel1, 0);
      ledcWrite(pwmChannel2, 255);
      ledcWrite(pwmChannel3, 0);
    } else if(valueInt > 20){
      ledcWrite(pwmChannel1, 0);
      ledcWrite(pwmChannel2, 0);
      ledcWrite(pwmChannel3, 255);
    }

  }
}


