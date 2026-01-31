#include <IRremote.h>

// Pin de l'IR
int PIN_IR = 9;

// Variable pour stocker les valeurs de la télécommande
int iValue;

void setup() {
  // Initialisation de la communication série
  Serial.begin(9600);

  // Initialisation du récepteur IR
  IrReceiver.begin(PIN_IR);
}

/*
-----------------------------------------------------------
ROLE DE CE PROGRAMME
-----------------------------------------------------------
Ce programme permet de LIRE et RECUPERER les codes envoyés
par les boutons de la télécommande IR.

ETAPES A SUIVRE :

1) Téléverser ce programme dans l’Arduino.

2) Ouvrir le Moniteur Série et régler la vitesse à 9600 bauds.

3) Pointer la télécommande vers le récepteur IR et appuyer
   sur un bouton.

4) Noter la valeur affichée à l’écran.
   Cette valeur correspond au code du bouton appuyé.

5) Répéter l’opération pour tous les boutons nécessaires.

6) Ces valeurs seront ensuite utilisées dans le SECOND
   programme (celui avec le switch case) pour contrôler
   les LEDs, moteurs, relais, etc.
-----------------------------------------------------------
*/

void loop() {

  // Vérifie si un signal IR est reçu
  if (IrReceiver.decode()) {

    iValue = IrReceiver.decodedIRData.command; // Valeur en décimal
    Serial.println(iValue);

    // Reprendre la réception IR
    IrReceiver.resume();
  }
}
