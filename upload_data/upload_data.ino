#include <DallasTemperature.h>
#include <OneWire.h>

#include <Arduino.h>
#define PROTOCOL     "HSP/1.0"
#define DEVICE_ID    "201201"
#define SENSOR_ID    "201204"
#define SENSOR_TYPE  "DATA"

int led = 13;
// Data wire is plugged into port 0 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS); 
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup()
{
  // Start up the library
  sensors.begin();

  pinMode(led, OUTPUT);
  pinMode(ONE_WIRE_BUS, INPUT);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}

void loop()
{
  sensors.requestTemperatures(); 

  Serial.println(PROTOCOL);
  Serial.print(DEVICE_ID);
  Serial.println(SENSOR_ID);
  Serial.println(SENSOR_TYPE);
  Serial.println(sensors.getTempCByIndex(5));

  delay(4000);
}








