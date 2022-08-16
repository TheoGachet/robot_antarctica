// Copyright (MIT License) 2022 Théo Gachet
// Projet réalisé en 2019 par Théo Gachet et Matéi Voillemier

const int input1 = 9; // M1 (gauche)
const int enA = 3;

const int input3 = 2; // M2 (droite)
const int enB = 5;

int trig1 = 8;        // capteur avant
int echo1 = 10;
long lecture_echo1;
long cm1;

int trig2 = 6;        // capteur latéral (gauche)
int echo2 = 7;
long lecture_echo2;
long cm2;

void setup()
{
  pinMode(input1,OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(trig1, OUTPUT);
  digitalWrite(trig1, LOW);
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT);
  digitalWrite(trig2, LOW);
  pinMode(echo2, INPUT);
  
  Serial.begin(9600);
}

void mesure1()
{
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  lecture_echo1 = pulseIn(echo1,HIGH);
  cm1 = lecture_echo1/58;
  Serial.println (cm1);
}

void mesure2()
{
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  lecture_echo2 = pulseIn(echo2,HIGH);
  cm2 = lecture_echo2/58;
  Serial.println (cm2);
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
  marche();
  mesure1();
  delay(100);
  if(cm1<15)
  {
    droite();
    mesure2();
    while(cm2<30)
    {
      marche();
      delay(500);
      mesure2();
    }
    delay(800);
    gauche();
  }
}
