#define SENSOR_PIN A0  // Broche du capteur TCRT5000
#define BUZZER_PIN 8   // Broche du buzzer
#define THRESHOLD 500  // Ajuster selon les tests (valeur basse = objet détecté)

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);

  // Debug: afficher la valeur du capteur
  Serial.print("Valeur TCRT5000: ");
  Serial.println(sensorValue);

  if (sensorValue < THRESHOLD) { // Objet détecté (valeur basse pour TCRT5000)
    digitalWrite(BUZZER_PIN, HIGH); // Activer le buzzer
    delay(1000);                    // Buzzer 1 seconde
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("ALERTE_INTRUSION");
    delay(2000); // Pause pour éviter les répétitions rapides
  }
}
