/**********************************
 *  20120902 
 *  jphome98@gmail.com
 **********************************/

#define PROTOCOL     "HSP/1.0"       /* 协议版本号 */
#define DEVICE_ID    "201201"        /* 设备ID */
#define SENSOR_ID    "201201"        /* 传感器ID */
#define SENSOR_TYPE  "CMD"         /* 传感器类型 */
#define HSMART_OK    "HSMART_OK"

/* 命令类型 */
#define CMD_LIGHT_ON     "01"
#define CMD_LIGHT_OFF    "02"

char buffer8[8];
char buffer7[7];
char buffer3[3];

int led = 13;
char start_flag = 0;

void setup()
{
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()) {
    Serial.readBytes(buffer8, 8);
    if (!strcmp(buffer8, PROTOCOL)) {   /* 校验协议 "HSP/1.0" */
      Serial.readBytes(buffer7, 7);
      if (!strcmp(buffer7, DEVICE_ID)) {  /* 校验设备ID */
        Serial.readBytes(buffer7, 7);
        /**********************************************************************************/
        if (!strcmp(buffer7, SENSOR_ID)) {  /* 校验传感器ID 201201 */
          Serial.readBytes(buffer3, 3);
          if (!strcmp(buffer3, CMD_LIGHT_ON)) {
            digitalWrite(led, HIGH);
          } 
          else if (!strcmp(buffer3, CMD_LIGHT_OFF)) {
            digitalWrite(led, LOW);
          }
        }
        /**********************************************************************************/
        Serial.println(PROTOCOL);
        Serial.print(DEVICE_ID);
        Serial.println(SENSOR_ID);
        Serial.println(HSMART_OK);

      }
    }    
  }
}










