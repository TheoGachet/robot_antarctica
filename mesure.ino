// Copyright (MIT License) 2022 Théo Gachet
// Projet réalisé en 2019 par Théo Gachet et Matéi Voillemier

namespace mesure
{
  int getDistanceAvant() //la distance est retournée en cm
  {
    digitalWrite(capteurAvantTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(capteurAvantTrig, LOW);
    return (pulseIn(capteurAvantEcho, HIGH));
  }
  
  int getDistanceDroite() //la distance est retournée en cm
  {
    digitalWrite(capteurCoteTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(capteurCoteTrig, LOW);
    return (pulseIn(capteurCoteEcho, HIGH));
  }

  double convertirFrequenceVitesse(double frequence)
  {
    if (frequence < 5.5)
      return (2.1113*frequence);
    return (0.94*exp(0.4605*frequence));
  }
  double getVitesseVent() //la distance est retournée en km/h
  {
    unsigned long tpsActuel = millis(); //Le temps est en ms !
    unsigned long deltaT = tpsActuel - bufferTemps; //deltaT est le temps entre le dernier signal et l'execution de la fonction
    bool anemoActuel = digitalRead(pinAnemo);
    
    if (anemoActuel == 1 && anemoBuffer == 0)
      {
        double frequence = 1000.0/static_cast<double>(deltaT); // 1000/deltaT = 1/(deltaT * 10^(-3))
        bufferTemps = tpsActuel;
      }
    
    else if (deltaT>= 2000) //nombre a changer en fonction des mesures de l'anémometre
    {
      return 0;
    }
    
    anemoBuffer = anemoActuel;
    
    return (mesure::convertirFrequenceVitesse(frequence)); //cette fonction sera faite à l'aide d'expériences
  }
  
  int getHumidite()
  {
    return 0;
  }

  int getTemperature()
  {
   return 0;
  }
  
  int getPression()
  {
    return 0;
  }
};
