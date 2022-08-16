// Copyright (MIT License) 2022 Théo Gachet
// Projet réalisé en 2019 par Théo Gachet et Matéi Voillemier

// Émission d’une valeur integer via module nRF24L01

#include <SPI.h> // gestion du bus SPI
#include <Mirf.h> // gestion de la communication
#include <nRF24L01.h> // définition des registres du nRF24L01
#include <MirfHardwareSpiDriver.h> // communication SPI nRF24L01

int valeur = 770;  // contient la valeur à envoyer
byte valeur_octet[2]; // contient la valeur découpée en octet pour l’envoi

void setup()
{
  Mirf.cePin = 8; // CE sur broche 8
  Mirf.csnPin = 7; // CSN sur broche 7
  Mirf.spi = &MirfHardwareSpi; // utilisation du port SPI hardware
  Mirf.init(); // initialise le module SPI
  Mirf.channel = 0; // utilisation canal 0 pour communiquer (128 canaux disponible, de 0 à 127)
  Mirf.payload = sizeof(unsigned int); // = 2, déclaration taille du message à transmettre, max 32 octets
  // RF_SETUP=0000abcd : a=1–>2Mb/s, a=0–>1Mb/s; puissance émission bc=00–>-18 dBm, bc=01–>-12dBm, bc=10–>-6dBm, bc=11–>0dBm;
  // d=0 pas de gain sur le bruit en réception
  Mirf.configRegister(RF_SETUP, 0x06); // 1 Mb/s et 0 dBm (puissance maximum)
  Mirf.config(); // configure le canal et la taille du message
  Mirf.setTADDR((byte *)"ardu2"); // définition adresse sur 5 octets de la 2ème carte Arduino
  Mirf.setRADDR((byte *)"ardu1"); // définition adresse sur 5 octets de la 1ere carte Arduino
}

void loop()
{
  while(Mirf.isSending())
  {
    // en cours d’émission
    delay(5);
  }
  valeur_octet[0] = valeur & 0xFF; // 1er octet
  valeur_octet[1] = (valeur & 0xFF00) >> 8; // 2ème octet
  Mirf.send(valeur_octet);
  delay(1000);
}
