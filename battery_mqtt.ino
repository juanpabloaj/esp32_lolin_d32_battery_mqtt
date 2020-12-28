#include <WiFi.h>
#include <PubSubClient.h>

#include "configuration.h"

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}


void setup() {
  Serial.begin(115200);

  // initialize digital pin LED_BUILTIN as an output
  pinMode(LED_BUILTIN, OUTPUT);

  setup_wifi();
  client.setServer(mqtt_server, 1883);

  if (!client.connected()) {
    mqttReconnect();
  }

  float voltage = analogRead(35) / 4096.0 * 7.23;
  char voltString[8];
  dtostrf(voltage, 8, 2, voltString);

  client.publish("esp32/voltage", voltString);

  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  beginSleep(getSleepTimer());
}

void loop() {}

void mqttReconnect() {
  while(!client.connected()) {
    Serial.print("attempting MQTT connection ...");

    if(client.connect("esp32Client")) {
      Serial.println("connected");
    } else {
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}


long getSleepTimer() {
  long sleepDurationMinutes = 2;
  int currentHour = 0, currentMin = 0, currentSec = 0;
  return (sleepDurationMinutes * 60 - ((currentMin % sleepDurationMinutes) * 60 + currentSec)) +5;
}

void beginSleep(long sleepTimer) {
  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);
  esp_sleep_enable_timer_wakeup(sleepTimer * 1000000LL);
  esp_deep_sleep_start();
}
