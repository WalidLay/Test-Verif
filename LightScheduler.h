#ifndef LIGHT_SCHEDULER_H
#define LIGHT_SCHEDULER_H

#include "LightControl.h"
#include "TimeService.h"
#include "FakeTimeService.h"
#include "LightControlSpy.h"

typedef struct{
    int LedID;
    Time Time;
    int State;
} TabEvents;


// TODO: Define the light scheduler interface here
// Fonction pour initialiser le light scheduler. en retour, le scheduler renvoit l'heure
void create(void);

//Fonction permettant d'envoyer un évènement à une LED (LED-JOUR-HEURE)
void scheduleOn(int,Day,int ,int);

void wakeUp(void);

void RemoveSchedule(int,Day,int,int);
//void setPeriodicAlarm(int TimeAlarm, wakeUp());



#endif
