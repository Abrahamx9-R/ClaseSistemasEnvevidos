#define LED_R 14
#define LED_G 27
#define LED_B 12
#define PIN_BUTTON 33

int led_status = 0;

int menu = 8;

typedef enum{
  RED = 1,
  GREEN,
  BLUE,
  CYAN,
  YELLOW,
  MAGENTA,
  WHITE,
  MAX
} RGB_States;

//debouncing (evitar el rebote del boton)
unsigned long lastDebounceTime = 0;
unsigned debounceDelay = 200;



void IRAM_ATTR isr_button(){
  if (millis()- lastDebounceTime > debounceDelay){
    led_status++;
    if (led_status >= menu){
      led_status = 0;
    
    }
    if(led_status >= menu) led_status = 0;
//    led_status = (led_status >= 7) ?0 : led_status+1;
   lastDebounceTime = millis();
   
   
   }

}




void setup() {
  pinMode(PIN_BUTTON,INPUT);
  attachInterrupt(PIN_BUTTON,isr_button,RISING);
  pinMode(LED_R,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_B,OUTPUT);

  Serial.begin(115200);

}

void loop() {
  switch(led_status){
    case 1:
      digitalWrite(LED_R,LOW);
      digitalWrite(LED_G,HIGH);
      digitalWrite(LED_B,HIGH);
    break;
    
    case 2:
      digitalWrite(LED_R,HIGH);
      digitalWrite(LED_G,LOW);
      digitalWrite(LED_B,HIGH);
    break;

    case 3:
      digitalWrite(LED_R,HIGH);
      digitalWrite(LED_G,HIGH);
      digitalWrite(LED_B,LOW);
    break;
    
    case 4:
      digitalWrite(LED_R,LOW);
      digitalWrite(LED_G,LOW);
      digitalWrite(LED_B,HIGH);
    break;
    case 5:
      digitalWrite(LED_R,LOW);
      digitalWrite(LED_G,HIGH);
      digitalWrite(LED_B,LOW);
    break;
    case 6:
      digitalWrite(LED_R,HIGH);
      digitalWrite(LED_G,LOW);
      digitalWrite(LED_B,LOW);
    break;

    case 7:
      digitalWrite(LED_R,LOW);
      digitalWrite(LED_G,LOW);
      digitalWrite(LED_B,LOW);
    break;
    
    default:
      digitalWrite(LED_R,HIGH);
      digitalWrite(LED_G,HIGH);
      digitalWrite(LED_B,HIGH);
    break;

  
  }

  
}
