#include "mbed.h"
#include "Motor.h"

Motor motor1(D12, D11, D10, D9);

InterruptIn botao(USER_BUTTON);

AnalogIn EixoYJoyStick(A0);

int tempo = 2;
int y;
bool referenciamento = 0;
int contador = 0;
int valor_inicial_x = 0;
int valor_final_x = 500;
int flag_referenciamento_x = 1;
int etapa = 2;

int lista_pos_x[8];
int pos_atual_x;
int flag_jogManual = 1;
int contador_x = 0;
int estado = 1;

    
void jogManual(){
    
    while(estado == 3){
        motor1.stop();
        contador_x = pos_atual_x;
        y = EixoYJoyStick.read() * 1000;
        while(y > 800 && flag_jogManual == 1){
            y = EixoYJoyStick.read() * 1000;
            if(contador_x >= valor_final_x){
                contador_x = valor_final_x;
                motor1.stop();
                continue;
            } else {
                motor1.gira_motor_sentido_antihorario(tempo);
                contador_x += 1;
            }
            
        }

        while(y < 200 && flag_jogManual == 1){
            y = EixoYJoyStick.read() * 1000;
            if(contador_x <= valor_inicial_x){
                contador_x = valor_inicial_x;
                motor1.stop();
                continue;
            } else {
                motor1.gira_motor_sentido_horario(tempo);
                contador_x -= 1;
            }
        }

        pos_atual_x = contador_x;
    }
}

void toggle_button(){
    estado++;
    if(estado > 3){
        estado = 1;
    }
}

int main() {
    botao.fall(&toggle_button);
    while(1) {

        switch (estado) {
        case 1:
            motor1.gira_motor_sentido_antihorario(tempo);
            break;
        case 2:
            motor1.gira_motor_sentido_horario(tempo);
            break;
        case 3:
            jogManual();
            break;
        }


    }
}
