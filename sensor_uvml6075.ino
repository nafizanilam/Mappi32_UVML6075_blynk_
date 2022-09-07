#define BLYNK_TEMPLATE_ID "XXXXXXXXXXX"
#define BLYNK_DEVICE_NAME "XXXXXXXXXXXXXXX"
#define BLYNK_AUTH_TOKEN "XXXXXXXXXXXXXXXXXXXX"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <SparkFun_VEML6075_Arduino_Library.h>
VEML6075 uv;

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "XXXXXXX";
char pass[] = "XXXXXXX";

BlynkTimer timer;


void myTimerEvent()
{
  Blynk.virtualWrite(V5, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  Wire.begin();

  if (!uv.begin())
  {
    Serial.println("Unable to communicate with VEML6075.");
    while (1)
    ;
  }
}

void loop()
{
  Blynk.run();
  timer.run();

  float Uva = (uv.a());
  float Uvb = (uv.b());

  Serial.println(String(uv.a()));
  Serial.println(String(uv.b()));

  Serial.println(String(uv.a()) + ", " + String(uv.b()));
  delay(250);

  Blynk.virtualWrite(V1, Uva);
  Blynk.virtualWrite(V2, Uvb);
  delay(1000);
}
