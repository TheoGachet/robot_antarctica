// Copyright (MIT License) 2022 Théo Gachet
// Projet réalisé en 2019 par Théo Gachet et Matéi Voillemier

//coté emetteur

#include <SPI.h> // gestion du bus SPI
#include <Mirf.h> // gestion de la communication
#include <nRF24L01.h> // définition des registres du nRF24L01
#include <MirfHardwareSpiDriver.h> // communication SPI nRF24L01

void setup()
{
  //
  Mirf.cePin = 8;
  Mirf.csnPin = 7;
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.channel = 0;
  Mirf.payload = sizeof(unsigned int);
  Mirf.configRegister(RF_SETUP, 0x06);
  Mirf.config();
  Mirf.setTADDR((byte *)"ardu2");
  Mirf.setRADDR((byte *)"ardu1");
}

void loop()
{
  envoyerNombre(66);
}

void envoyerNombre(byte nombre)
{
  Mirf.send(nombre);
  while(Mirf.isSending())
    delay(5);
}
