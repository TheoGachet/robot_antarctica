// Copyright (MIT License) 2022 Théo Gachet
// Projet réalisé en 2019 par Théo Gachet et Matéi Voillemier

//pins moteurs
int moteur1 = 0; //moteur gauche digital
int moteur2 = 1; //moteur droit digital
int enA = 0;     //moteur gauche analogique
int enB = 0;     //moteur droit analogique

//pins capteurs simples
int pinAnemometre;
int pinBarometre;
int pinThermometre;
int pinHygrometre;

//pins capteurs ultrasons
int capteurAvantTrig;
int capteurAvantEcho;
int capteurDroiteTrig;
int capteurDroiteEcho;

void setup()
{
  //pins moteurs
  pinMode(moteur1, OUTPUT);
  pinMode(moteur2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  //pins capteurs simples
  pinMode(pinAnemometre, INPUT);
  pinMode(pinBarometre, INPUT);
  pinMode(pinThermometre, INPUT);
  pinMode(pinHygrometre, INPUT);

  //pins capteurs ultrasons
  pinMode(capteurAvantTrig, OUTPUT);
  pinMode(capteurAvantEcho, INPUT);
  pinMode(capteurDroiteTrig, OUTPUT);
  pinMode(capteurDroiteEcho, INPUT);

  //initialisation capteurs ultrasons
  digitalWrite(capteurAvantTrig, LOW);
  digitalWrite(capteurDroiteTrig, LOW);
}

void loop()
{
  
}
