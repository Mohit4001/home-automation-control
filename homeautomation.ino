#define TEMP_PIN A0
#define FAN_PIN 9

int adcValue;
int pwmValue;

void setup() {
  pinMode(FAN_PIN, OUTPUT);
}

void loop() {
  adcValue = analogRead(TEMP_PIN);

  // Convert ADC value to temperature (LM35)
  float temperature = (adcValue * 5.0 * 100.0) / 1024;

  if (temperature < 25) {
    pwmValue = 0;
  } else if (temperature < 30) {
    pwmValue = 80;
  } else if (temperature < 35) {
    pwmValue = 160;
  } else {
    pwmValue = 255;
  }

  analogWrite(FAN_PIN, pwmValue);
  delay(500);
}