//FONTE1: http://blog.filipeflop.com/sensores/monitorando-temperatura-e-umidade-com-o-sensor-dht11.html
//FONTE2: https://learn.adafruit.com/downloads/pdf/dht-humidity-sensing-on-raspberry-pi-with-gdocs-logging.pdf
//FONTE3: https://learn.adafruit.com/setting-up-io-python-library-on-beaglebone-black/using-the-bbio-library

#include "DHT.h"

#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT22 // DHT 22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
}

void loop()
{
  // A leitura da temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
  }
}
