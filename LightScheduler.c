#include "LightScheduler.h"


Time CurTime;
TabEvents Events[256];

//void setUp(void){
//
//}


void create(){
    for (int i = 0; i<256;i++){
        Events[i].LedID = -1;
        Events[i].Time.day = NONE;
        Events[i].Time.minuteOfDay = 0000;
        Events[i].State = LIGHT_STATE_UNKNOWN;
    }

}

//Fonction permettant d'envoyer un évènement à une LED (LED-JOUR-HEURE)
void scheduleOn(int id, Day day,int minuteofday,int State){
     //j'enregistre l'évènement dans le tableau TabEvents
    for (int i = 0; i < 256 ; i++){
        if (Events[i].LedID ==-1 ){
            Events[i].LedID = id;
            Events[i].Time.day = day;
            Events[i].Time.minuteOfDay = minuteofday;
            Events[i].State = State;
            break;
        }
    }
}

void light_on(void){

}

void light_off(void){

}

void RemoveSchedule(int id, Day day,int minuteofday,int State){

}
void wakeUp(void){
    //Je récupère l'heure
    TimeService_getTime(&CurTime);
    //il balaye parmi les événements qui existent s'il y'en a une pour allumer une led
    

for (int i=0;i<256;i++){
    switch (Events[i].Time.day)
    {
    case WEEKDAY:
        if (CurTime.day == MONDAY || CurTime.day == TUESDAY || CurTime.day == WEDNESDAY || CurTime.day == THURDSDAY || CurTime.day == FRIDAY){
            if(Events[i].Time.minuteOfDay == CurTime.minuteOfDay){
                if(Events[i].State){
                    LightControl_on(Events[i].LedID);
                }
                else{
                    LightControl_off(Events[i].LedID);
                }
            }
        }
        break;
    
    case WEEKEND:
        if (CurTime.day == SATURDAY || CurTime.day == FRIDAY){
            if(Events[i].Time.minuteOfDay == CurTime.minuteOfDay){
                if(Events[i].State){
                    LightControl_on(Events[i].LedID);
                }
                else{
                    LightControl_off(Events[i].LedID);
                }
            }
        }
        break;

    case EVERYDAY:
        if(Events[i].Time.minuteOfDay == CurTime.minuteOfDay){
            if(Events[i].State){
                LightControl_on(Events[i].LedID);
            }
            else{
                LightControl_off(Events[i].LedID);
            }
        }
        break;
    
    default:
    if(CurTime.day == Events[i].Time.day && CurTime.minuteOfDay == Events[i].Time.minuteOfDay){
        if(Events[i].State){
                LightControl_on(Events[i].LedID);
            }
            else{
                LightControl_off(Events[i].LedID);
            }
        break;
    }
    }
}
}


