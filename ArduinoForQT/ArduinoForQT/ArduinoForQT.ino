void setup() {
  Serial.begin(9600); // Initialiser la communication série à 9600 bauds
}

void loop() {
  // Simuler l'état des cabines et de la zone d'attente
  static bool toggle = false;
  toggle = !toggle; // Alterner entre deux états

  // Créer un JSON avec des données simulées
  Serial.print("{\"cabine1\": \"");
  Serial.print(toggle ? "occupe" : "libre");
  Serial.print("\", \"cabine2\": \"");
  Serial.print(toggle ? "libre" : "occupe");
  Serial.print("\", \"attente\": \"");
  Serial.print(toggle ? "occupe" : "libre");
  Serial.println("\"}");

  delay(5000); // Envoyer toutes les 5 secondes
}
