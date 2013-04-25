/**********************************
 *  20130421 
 *  jphome98@gmail.com
 **********************************/
#include <OneWire.h>
#include <DallasTemperature.h>

#define PROTOCOL     "HSP/1.0"       ///< 协议版本号
#define DEVICE_ID    "201301"        ///< 设备ID
#define LED_1_ID     "201301"
#define SWITCH_1_ID  "201302"
#define SWITCH_2_ID  "201303"
#define TEMP_ID      "201304"

#define SENSOR_TYPE_CMD    "CMD"
#define SENSOR_TYPE_DATA   "DATA"
#define HSMART_OK          "HSMART_OK"

/// 命令类型
#define ON     "01"
#define OFF    "02"
#define QUERY  "03"

char proto_head[15];
char proto_opt[9];

/// pin
int led_1 = 13;
int switch_1 = 10;
int switch_2 = 11;
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup()
{
  pinMode(led_1, OUTPUT);
  digitalWrite(led_1, HIGH);
  pinMode(switch_1, OUTPUT);
  digitalWrite(switch_1, HIGH);
  pinMode(switch_2, OUTPUT);
  digitalWrite(switch_2, HIGH);

  delay(500);
  digitalWrite(led_1, LOW);

  Serial.begin(9600);
  sensors.begin();
}

void loop()
{
  if (Serial.available()) {
    Serial.readBytes(proto_head, 15);
    if (!strcmp(proto_head, PROTOCOL","DEVICE_ID)) {
        Serial.readBytes(proto_opt, 9);
        if (!strcmp(proto_opt, LED_1_ID ON)) {
            digitalWrite(led_1, HIGH);
            goto ok;
          } else if (!strcmp(proto_opt, LED_1_ID OFF)) {
            digitalWrite(led_1, LOW);
            goto ok;
          } else if (!strcmp(proto_opt, SWITCH_1_ID ON)) {
            digitalWrite(switch_1, LOW);
            goto ok;
          } else if (!strcmp(proto_opt, SWITCH_1_ID OFF)) {
            digitalWrite(switch_1, HIGH);
            goto ok;
          } else if (!strcmp(proto_opt, SWITCH_2_ID ON)) {
            digitalWrite(switch_2, LOW);
            goto ok;
          } else if (!strcmp(proto_opt, SWITCH_2_ID OFF)) {
            digitalWrite(switch_2, HIGH);
            goto ok;
          } else if (!strcmp(proto_opt, TEMP_ID QUERY)) {
            sensors.requestTemperatures();
            Serial.print(PROTOCOL","DEVICE_ID","TEMP_ID","SENSOR_TYPE_DATA",");
            Serial.println(sensors.getTempCByIndex(0));
            goto ok;
          }
    }
ok:
    Serial.println(PROTOCOL","HSMART_OK);
  }
}

