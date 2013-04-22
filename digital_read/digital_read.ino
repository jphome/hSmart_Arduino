#include <Arduino.h>
#define PROTOCOL     "HSP/1.0"
#define DEVICE_ID    "201201"
#define SENSOR_ID    "201204"
#define SENSOR_TYPE  "DATA"

int led = 13;
#define TEMP  0

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(TEMP, INPUT);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(PROTOCOL);
  Serial.print(DEVICE_ID);
  Serial.println(SENSOR_ID);
  Serial.println(SENSOR_TYPE);
  int tempData = digitalRead(TEMP);
  Serial.println(tempData);

  delay(4000);  ///< 4s刷新一次
}








