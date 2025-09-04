#define PH_sensor 34

float calibration = 21;

void setup() {
  Serial.begin(115200);
  Serial.println("==================================================== The ESP32 PH sensor :) ========================================================================");
  Serial.println("-_-");
}
void loop() {
  int analogValue = analogRead(PH_sensor);
  float voltage = analogValue * (3.3 / 4095.0);
  float phValue = 7 + ((2.5 - voltage) * calibration);
 
  Serial.print("Raw Value: ");
  Serial.println(analogValue);
  
if (phValue <= 6) {
  Serial.print("pH Value: ");
  Serial.print(round(phValue));
  Serial.println(" , Acidic");
}
else if (phValue >= 8) {
  Serial.print("pH Value: ");
  Serial.print(round(phValue));
  Serial.println(" , Basic");
}
else {
  Serial.print("pH Value: ");
  Serial.print(round(phValue));
  Serial.println(" , Neutral");
}
  delay(1000);
}