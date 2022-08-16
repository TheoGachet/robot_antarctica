// Copyright (MIT License) 2022 Théo Gachet
// Projet réalisé en 2019 par Théo Gachet et Matéi Voillemier

#include <Wire.h>
#include <SFE_BMP180.h>
#define ALTITUDE 164 //Altitude de la ville de Chaumont, Haute-Marne (52)

SFE_BMP180 pressure;

void setup() {
  Serial.begin(9600);
  Serial.println("Programme lancé");

  if (pressure.begin())
    Serial.println("BMP180 initialisation réussie");
  else //Else, stop code forever
  {
    Serial.println("BMP180 échec d'initialisation");
    while (1);
  }
}

void loop() {
  
  char status;
  double T, P;
  
  status = pressure.startTemperature();
  if (status != 0) {
    delay(status);

    status = pressure.getTemperature(T);
    if (status != 0) {
      Serial.print("Température : ");
      Serial.print(T, 1);
      Serial.println(" °C");

      status = pressure.startPressure(3);

      if (status != 0) {
        delay(status);

        status = pressure.getPressure(P, T);
        if (status != 0) {
          Serial.print("Pression : ");
          Serial.print(P);
          Serial.println(" hPa");

        }
      }
    }
  }  
  delay(1000);
}
