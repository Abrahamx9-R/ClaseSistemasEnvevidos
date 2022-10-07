const int PIN = 33;
const int LED = 32;


struct Button{
    const int PIN;
    int numeTimeButtonPress;
    bool pressed;
    bool bStatus;
};

Button button1 = {PIN,0,false};

void IRAM_ATTR isr_button(){
  button1.numeTimeButtonPress += 1;
  button1.pressed = true;
  button1.bStatus ^=  true;
  }

void setup() {
  Serial.begin(9600);
  pinMode(PIN,INPUT);
  pinMode(LED,OUTPUT);
  attachInterrupt(button1.PIN, isr_button, FALLING);
  digitalWrite(LED, LOW);
}

void loop() {
  if (button1.bStatus){
    Serial.printf("El boton se ha presionado %u veces \n",button1.numeTimeButtonPress);
    digitalWrite(LED, HIGH);
    button1.pressed = false;
    delay(500);
    digitalWrite(LED, LOW);
  }
  else{
    Serial.print("bStatus: ");
    Serial.println(button1.bStatus);
  }

}
