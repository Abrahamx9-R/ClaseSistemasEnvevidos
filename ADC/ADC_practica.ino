//const int pinLDR = 34;

# define PIN_LDR 34
# define PIN_LM35 35

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Serial.println(analogRead(PIN_LDR));
  //Serial.print("   ,   ");
  Serial.println(analogRead(PIN_LM35)*0.1221); // 5000/(10*4095)=0.1221  -> conversion a grados centigrados
  delay(100);
  
}
