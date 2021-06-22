#include <Arduino.h>
#include <main.h>
#include <Servo.h>

#define DEBUG true
#define ANGULO_INICIAL 90
#define ANGULO_INCREMENTO 10
#define BASE_DIR 'e'
#define BASE_ESQ 'q'
#define LIMITES_ESQ 160
#define LIMITES_DIR 20
//Mapeamento Servos
#define ServoBase 5

Servo servo_base;
int angulo_atual;
int calcula_posicao = ANGULO_INICIAL;

void setup() {
  #if DEBUG
  Serial.begin(9600);
  #endif

  mapearPinosServo();
  InicializaAnguloServo();
  
}

void loop() {
  MoveBase();
  delay(100);
}

void mapearPinosServo(){
  servo_base.attach(ServoBase);

}

void InicializaAnguloServo(){
  servo_base.write(ANGULO_INICIAL);
}

void MoveBase(){
    LeTeclado();
    angulo_atual = calcula_posicao;
}

void LeTeclado(){
    if(Serial.available()){  
    char tecla = Serial.read();
    if(tecla == BASE_ESQ){
      if(angulo_atual < LIMITES_ESQ){
        calcula_posicao = angulo_atual + ANGULO_INCREMENTO;
        servo_base.write(calcula_posicao);
      }     
    }else if(tecla == BASE_DIR){      
      if(angulo_atual > LIMITES_DIR){
        calcula_posicao = angulo_atual - ANGULO_INCREMENTO;
        servo_base.write(calcula_posicao);
      }
   }
 }
}
