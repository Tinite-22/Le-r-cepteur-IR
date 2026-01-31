#include <IRremote.h>

// Pin du récepteur IR
int PIN_IR = 10;

// Pin de la LED
int LED_Pin = 9;

// Variable pour stocker les valeurs IR
int iValue;

void setup() {
  
  // Initialisation communication série
  Serial.begin(9600);

  // Initialisation récepteur IR
  IrReceiver.begin(PIN_IR);

  // Configuration de la LED
  pinMode(LED_Pin, OUTPUT);
  
  // Tout éteindre au démarrage
  digitalWrite(LED_Pin, LOW);
}

/*
-----------------------------------------------------------
UTILISATION DES CODES IR RECUPERES
-----------------------------------------------------------
Les valeurs utilisées dans le switch case (ex: 69, 68)
proviennent du programme de lecture IR.

Avant d’utiliser ce programme :

1) Exécuter d’abord le programme de lecture IR pour
   récupérer les codes de votre télécommande.

2) Noter les valeurs affichées dans le Moniteur Série.

3) Remplacer les valeurs des "case" par celles obtenues.

Exemple :
Si le bouton ON affiche 45 → utiliser : case 45:
Si le bouton OFF affiche 46 → utiliser : case 46:

Cela permet d’adapter le programme à n’importe quelle
télécommande IR.
-----------------------------------------------------------
*/


void loop() {

  // Vérifie réception IR
  if (IrReceiver.decode()) {

    iValue = IrReceiver.decodedIRData.command;
    Serial.println(iValue);

    // -------- SWITCH CASE --------
    switch (iValue) {

      case 69:         // LED ON
        digitalWrite(LED_Pin, HIGH);
        break;

      case 68:         // LED OFF
        digitalWrite(LED_Pin, LOW);
        break;
      
      default:
        // Aucun bouton reconnu
        break;
    }

    // Reprendre réception IR
    IrReceiver.resume();
  }
}
