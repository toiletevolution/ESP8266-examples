#include <Arduino.h>
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

#include "config.h"

const int PIR_MOTION_SENSOR = 4;
const int REED_SWITCH_1 = 5;
const int REED_SWITCH_2 = 12;

unsigned long prevSendTime = 0UL;
boolean detected = false;

ESP8266WiFiMulti WiFiMulti;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_MOTION_SENSOR, INPUT_PULLUP);
  digitalWrite(PIR_MOTION_SENSOR, LOW);
  pinMode(REED_SWITCH_1, INPUT_PULLUP);
  pinMode(REED_SWITCH_2, INPUT_PULLUP);

  WiFiMulti.addAP(WIFI_SID, WIFI_PASSWORD);
}

void loop() {
  if (isPeopleDetected()) {
    detected = true;
  }

  unsigned long current = millis();
  if ((current - prevSendTime) > 10000UL) {
    int reed1 = digitalRead(REED_SWITCH_1);
    int reed2 = digitalRead(REED_SWITCH_2);
    
    if (detected) {
      send(1, reed1, reed2);
    } else {
      send(0, reed1, reed2);
    }
    detected = false;
    prevSendTime = current;
  }
  delay(1000);
}

boolean isPeopleDetected()
{
  int sensorValue = digitalRead(PIR_MOTION_SENSOR);
  if(sensorValue == HIGH)//if the sensor value is HIGH?
  {
    return true;//yes,return ture
  }
  else
  {
    return false;//no,return false
  }
}

void send(int pir, int reed1, int reed2)
{
  if((WiFiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    Serial.print(F("[HTTP] begin...\n"));
    http.begin(END_POINT);
    http.setAuthorization(DEVICE_ID, DEVICE_PASSWORD);
    http.addHeader("Content-Type", "application/json");

    StaticJsonBuffer<200> jsonBuffer;
    JsonArray& array = jsonBuffer.createArray();
    array.add(pir);
    array.add(reed1);
    array.add(reed2);
    String body;
    array.printTo(body);

//    int httpCode = http.POST(body);
//    Serial.printf("[HTTP] POST... code: %d\n", httpCode);
    Serial.println(body);

    http.end();
  }
}


