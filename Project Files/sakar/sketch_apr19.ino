#include <dummy.h>
#include <Base64.h>
#include <WiFi.h>
#include <ArduinoHttpClient.h>

#define IO14 14
#define IO13 13
#define IO12 12
#define SPEAKER 25
#define CONNECTION_TIMEOUT 10

int pwmChannel1 = 0; // Selects channel 0 for GPIO14
char ssid[] = "yourNetwork";    // Your WiFi network SSID
char pass[] = "yourPassword";   // Your WiFi network password
char server[] = "api.watttime.org"; // The server you're making the request to
int port = 443; // HTTPS port

WiFiClient wifiClient;
//HttpClient client;
HttpClient client = HttpClient(wifiClient, server, port);

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
  
  // Assigns the PWM channels to respective GPIO pins
  ledcAttachPin(14, pwmChannel1); // GPIO14
  ledcAttachPin(13, pwmChannel1); // GPIO13
  ledcAttachPin(12, pwmChannel1); // GPIO12

  ledcWrite(pwmChannel1, dutyCycle);
  

  Serial.begin(9600);
  delay(1000);
  int timeout_counter = 0;

  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.println("Connecting to WiFi...");
    delay(1000);

    timeout_counter++;
    if (timeout_counter >= CONNECTION_TIMEOUT * 5) {
      ESP.restart();
    }
  }

  Serial.println("C onnected to WiFi");

}

void loop() {
  // put your main code here, to run repeatedly:
  //reg();
  //login();
  
  //client.beginRequest();
  //client.get("/v3/signal-index");
  
   // Set duty cycle to produce 3.3V
  //ledcWrite(pwmChannel1, dutyCycle);
  
  sound();
}

void sound() {
  tone(SPEAKER, 440, 1000); // Play a 440 Hz tone for 1 second
  delay(1000); // Wait for a second
}

void reg(){
  String url = "/register";
  String params = "{\"username\":\"ece445\",\"password\":\"carbonintensity\",\"email\":\"skarki2@illinois.edu\",\"org\":\"UIUC\"}";
  
  client.beginRequest();
  client.post(url, "application/json", params);
  client.sendHeader("Content-Length", params.length());
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

  // Wait for a while before sending another request
  delay(30000); // Delay for 1 minute
}

void login() {
   // Send login request
  String url = "/login";
  String credentials = "freddo:the_frog";
  String authHeader = "Basic " + base64::encode(credentials);

  client.beginRequest();
  client.get(url);
  client.sendHeader("Authorization", authHeader);
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

  // Parse the token from the response
  String token = parseToken(response);
  Serial.print("Token: ");
  Serial.println(token);

  // Wait for a while before sending another request
  delay(60000); // Delay for 1 minute
}

String parseToken(String response) {
  // Assuming the JSON response is in the format {"token": "your_token_here"}
  int startIndex = response.indexOf('"') + 1;
  int endIndex = response.lastIndexOf('"');
  return response.substring(startIndex, endIndex);
}
