#define LED 32
#define BOTON 33
int valor;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BOTON,OUTPUT);
  digitalWrite(LED,LOW);
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
}

void loop() {
  valor = digitalRead(BOTON);
  if (valor == HIGH){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
    }

}
