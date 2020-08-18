// sudo apt install python-is-python3
// sudo apt-mark hold python2 python2-minimal python2.7 python2.7-minimal libpython2-stdlib libpython2.7-minimal libpython2.7-stdlib
// sudo apt install python3-serial

// ADC2 is used with WiFi. Therefor analogRead() on ADC2 pins fails. ADC1 channels are save to use ⇒ GPIO32, 33, 34, 35, 36, 39.

#include "libs.h"
#include "api.h"

#define LED_BUILTIN 2
#define SENSOR_1 33
#define SENSOR_2 32

//============================CONFIG WIFI============================================================

const char *ssid = NOME_REDE;
const char *password = SENHA_REDE;

//============================DECLARAÇÃO DE OBJETOS==================================================

API objApi;
HTTPClient http;

//============================DECLARAÇÃO DE FUNÇÕES==================================================

void connectWifi();
void setObjetos();

//============================CONFIGURAÇÕES INICIAIS=================================================

void setup()
{
  Serial.begin(115200);

  connectWifi();

  pinMode(LED_BUILTIN, OUTPUT);
}

//============================LOOP===================================================================

void loop()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(5000);

  int sensor1 = analogRead(SENSOR_1);
  int sensor2 = analogRead(SENSOR_2);

  objApi.create("sensor_1", sensor1);
  objApi.create("sensor_2", sensor2);
}

//============================FUNÇOES================================================================

void connectWifi()
{
  WiFi.begin(ssid, password);
  Serial.println("Conectando");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Conectado!");
}

void setObjetos(){
   objApi.setHttp(http);
}