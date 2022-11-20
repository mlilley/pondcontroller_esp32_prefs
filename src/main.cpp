#include <Arduino.h>
#include <Preferences.h>

/**
 * Pondcontroller configuration writer.
 * 
 * Writes configuration settings to pondcontroller device ROM.
*/

#define PREFS_NAMESPACE "pondcontroller"

#define DEVICE_ID        "pondcontroller1"
#define WIFI_SSID        "wifissid"
#define WIFI_PASS        "wifipassword"
#define MQTT_HOST        "bro.ker.ipa.ddr"
#define MQTT_PORT        1883
#define CONTROL_SETPOINT 20.0f
#define CONTROL_DEVIANCE 1.0f
#define PUBLISH_MS       30000L
#define CONTROL_MS       5000L

void setup() {
  Serial.begin(115200);
  Serial.println("Clearing flash and writing preferences...");

  Preferences prefs;
  prefs.begin(PREFS_NAMESPACE, false);

  prefs.clear();

  prefs.putString("DEVICE_ID",     DEVICE_ID);
  prefs.putString("WIFI_SSID",     WIFI_SSID);
  prefs.putString("WIFI_PASS",     WIFI_PASS);
  prefs.putString("MQTT_HOST",     MQTT_HOST);
  prefs.putUInt  ("MQTT_PORT",     MQTT_PORT);
  prefs.putFloat ("TEMP_SETPOINT", CONTROL_SETPOINT);
  prefs.putFloat ("TEMP_DEVIANCE", CONTROL_DEVIANCE);
  prefs.putULong ("PUBLISH_MS",    PUBLISH_MS);
  prefs.putULong ("CONTROL_MS",    CONTROL_MS);

  prefs.end();

  Serial.println("Done.");
}

void loop() {
}