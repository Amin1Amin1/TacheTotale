// —— CONFIGURATION ——
const int TCRT_PIN = A0;        // Broche analogique du TCRT5000
const int LED_VERTE = 12;       // LED verte = cabine libre
const int LED_ROUGE = 13;       // LED rouge = cabine occupée
const int BUZZER_PIN = 8;       // Alarme après 15s
const unsigned long DELAI_ALARME = 15000; // 15 secondes
const int SEUIL_DETECTION = 300; // Seuil à ajuster selon votre capteur

// —— VARIABLES ——
unsigned long chronoOccupation = 0;
bool alarmeActive = false;
bool cabineOccupee = false;

void setup() {
  pinMode(LED_VERTE, OUTPUT);
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // État initial : cabine libre (LED verte)
  digitalWrite(LED_VERTE, HIGH);
  digitalWrite(LED_ROUGE, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  
  Serial.begin(9600);
  Serial.println("Système cabine prêt (LED verte = libre)");
}

void loop() {
  int valeurCapteur = analogRead(TCRT_PIN);
  
  // —— DÉTECTION CABINE OCCUPÉE (LED ROUGE) ——
  if (valeurCapteur < SEUIL_DETECTION) {  // Condition corrigée : détection quand valeur < seuil
    if (!cabineOccupee) {
      cabineOccupee = true;
      chronoOccupation = millis();
      digitalWrite(LED_VERTE, LOW);  // Éteint vert
      digitalWrite(LED_ROUGE, HIGH); // Allume rouge
      Serial.println("Client entré - LED rouge (occupée)");
    }
    
    // —— ALARME APRÈS 15s ——
    if (!alarmeActive && (millis() - chronoOccupation > DELAI_ALARME)) {
      alarmeActive = true;
      digitalWrite(BUZZER_PIN, HIGH);
      Serial.println("ALARME ! Client présent depuis 15s !");
    }
  } 
  // —— CABINE LIBRE (LED VERTE) ——
  else {
    if (cabineOccupee) {
      cabineOccupee = false;
      alarmeActive = false;
      digitalWrite(LED_ROUGE, LOW);  // Éteint rouge
      digitalWrite(LED_VERTE, HIGH); // Allume vert
      digitalWrite(BUZZER_PIN, LOW); // Coupe alarme
      Serial.println("Client sorti - LED verte (libre)");
    }
  }

  delay(200); // Pause entre les lectures
}
