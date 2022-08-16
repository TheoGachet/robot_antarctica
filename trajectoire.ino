// Copyright (MIT License) 2022 Théo Gachet
// Projet réalisé en 2019 par Théo Gachet et Matéi Voillemier

// Code pour modifier le PWM (MLI) afin d'obtenir des trajectoires rectilignes uniformes
// NB : il faut adapter les valeurs à chaque modification de la masse du ROVER, i.e. à chaque ajout d'élément (asservissement)

const int input1 = 9; // GAUCHE
const int enA = 3;

const int input3 = 2; // DROITE
const int enB = 5;

void setup()
{
  pinMode(input1,OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(enB, OUTPUT);
}

void arret()
{
  //arrêt
  digitalWrite(input1, LOW);
  analogWrite(enA, 0);
  digitalWrite(input3, LOW);
  analogWrite(enB, 0);
  delay(5000);
}

void marche()
{
  digitalWrite(input1, HIGH);
  analogWrite(enA, 252);
  digitalWrite(input3, HIGH);
  analogWrite(enB, 255);
}

void arret()
{
  digitalWrite(input1, LOW);
  analogWrite(enA, 0);
  digitalWrite(input3, LOW);
  analogWrite(enB, 0);
}

void droite()
{
  digitalWrite(input1, HIGH);
  analogWrite(enA, 255);
  digitalWrite(input3, LOW);
  analogWrite(enB, 0);
  delay(1100);
}

void gauche()
{
  digitalWrite(input1, LOW);
  analogWrite(enA, 0);
  digitalWrite(input3, HIGH);
  analogWrite(enB, 255);
  delay(900);
}

void loop()
{
  // test de la trajectoire
}
