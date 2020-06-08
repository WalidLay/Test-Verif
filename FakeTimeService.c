#include "FakeTimeService.h"
#include "unity.h"
Time FakeTime;

void FakeTimeService_setTime(Time *a){
    FakeTime= *a;
}

void TimeService_init(){
    FakeTime.day = NONE;
    FakeTime.minuteOfDay = 0000;
}

void TimeService_destroy(){

}

void TimeService_getTime(Time *time){
    *time=FakeTime;
}

void TimeService_startPeriodicAlarm(int seconds, void (*callback)(void)){

}

void TimeService_stopPeriodicAlarm(int seconds){

}