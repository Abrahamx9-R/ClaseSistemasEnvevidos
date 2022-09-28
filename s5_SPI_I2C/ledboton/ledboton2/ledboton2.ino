#define LED 32
#define BOTON 33
int valor = 1;

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(BOTON,OUTPUT);
  digitalWrite(LED,LOW);
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
}

void loop() {
  
  if (digitalRead(BOTON) == HIGH){
    Serial.println(valor);
    valor += 1;
    valor = valor%2;
    delay(100);
    
  }
  if (valor == 1){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }


}
