// Copyright (MIT License) 2022 Théo Gachet
// Projet réalisé en 2019 par Théo Gachet et Matéi Voillemier

namespace moteur
{
  void avancer() //les distances 248 et 250 doivent être changées constamment en fonction de la masse du robot (asservissement empirique)
  {
    digitalWrite(moteur1, HIGH);
    analogWrite(enA, 248);
    digitalWrite(moteur2, HIGH);
    analogWrite(enB, 250);
  }

  void arreter()
  {
    digitalWrite(moteur1, LOW);
    analogWrite(enA, 0);
    digitalWrite(moteur2, LOW);
    analogWrite(enB, 0);
  }
  
  void tourner(bool direction, int temps) // 0 = droite; 1 = gauche; le temps est en ms
  {
    if (direction)
    {
      digitalWrite(moteur1, HIGH);
      analogWrite(enA, 248);
      digitalWrite(moteur2, LOW);
      analogWrite(enB, 0);
      delay(temps);
    }
    else
    {
      digitalWrite(moteur1, LOW);
      analogWrite(enA, 0);
      digitalWrite(moteur2, HIGH);
      analogWrite(enB, 250);
      delay(temps);
    }
  }
  
  void demiTour(bool direction) // 0 = droite; 1 = gauche
  {
    direction ? moteur::tourner(0, 1100) : moteur::tourner(1, 900);
  }
}
