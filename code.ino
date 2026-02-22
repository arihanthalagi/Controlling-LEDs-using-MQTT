#include <WiFi.h>
#include <PubSubClient.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// MQTT Broker
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

// LED Pins
const int led1 = 2;
const int led2 = 4;

void setup() {
  Serial.begin(115200);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  while (!client.connected()) {
    client.connect("ESP32Client");
  }

  client.subscribe("home/led");
}

void loop() {
  client.loop();
}

// Callback Function
void callback(char* topic, byte* payload, unsigned int length) {

  String message;

  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  if (message == "LED 1 ON") {
    digitalWrite(led1, HIGH);
  }
  else if (message == "LED 1 OFF") {
    digitalWrite(led1, LOW);
  }
  else if (message == "LED 2 ON") {
    digitalWrite(led2, HIGH);
  }
  else if (message == "LED 2 OFF") {
    digitalWrite(led2, LOW);
  }
}
