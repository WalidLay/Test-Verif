#include "LightControlSpy.h"

int LIGHT_ID;
int LIGHT_STATE;

void LightControl_init(void){
    //initialise le lightcontrol : toutes les leds sont à 0
    LIGHT_STATE = 0;
}

void LightControl_on(int id){
    //mettre la variable à 1
    LIGHT_STATE = LIGHT_ON;
    //sauvegarde l'identifiant
    LIGHT_ID=id;
}

void LightControl_destroy(void){


}


void LightControl_off(int id){
    //mettre la variable à 1

    //sauvegarde l'identifiant
}

int LightControlSpy_getLastLightId(void){
    //renvoit l'id
    return LIGHT_ID;

}

int LightControlSpy_getLastState(void){
    return LIGHT_STATE;
}