#define BLYNK_TEMPLATE_ID "TMPL3O0naNLnD"
#define BLYNK_TEMPLATE_NAME "switchboard"
#define BLYNK_AUTH_TOKEN "6p-sDtS5Byd6jj2qUm_WFzogErjL9gzs"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char auth[] = "6p-sDtS5Byd6jj2qUm_WFzogErjL9gzs"; // Your Blynk Auth Token
char ssid[] = "vivo1819";
char pass[] = "password";
const int relayPin = 25;  // Use GPIO 25 for the relay

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  Blynk.begin(auth, ssid, pass);

  // Set up the relay pin
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Initialize the relay to OFF

  // Attach a virtual pin handler
  Blynk.virtualWrite(V1, LOW); // Initialize the switch status to OFF
}

void loop() {
  Blynk.run();
}

// Blynk virtual pin handler
BLYNK_WRITE(V1) {
  int switchStatus = param.asInt(); // Get the value from the app
  digitalWrite(relayPin, switchStatus); // Control the relay based on the app value
}