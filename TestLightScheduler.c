#include "LightScheduler.h"
#include "unity.h"
#include "FakeTimeService.h"
#include "LightControlSpy.h"

void setUp(void)
{

}

void tearDown(void)
{

}

//The LightScheduler allows to schedule the switching of room lights (on or off) on a specific day at a specific time (hour and minute).
void testLightOnOff(void){
    //J'initialise mon scheduler
    create();
    LightControl_init();
    //Je crée mon événement
    scheduleOn(42,MONDAY,1200,LIGHT_ON);
    
    //Je mets mon horloge à l'heure de l'évènement
    Time X ;
    X.minuteOfDay = 1200;
    X.day = MONDAY;

    FakeTimeService_setTime(&X);

    //je réveille l'évènement
    wakeUp();

    //Je teste si  
    TEST_ASSERT_EQUAL( 42, LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL( LIGHT_ON, LightControlSpy_getLastState() );
}

//    Each light is identified by an integer number.
void testLedIDisInteger (void){
    //Soit N le nombre total de Led
    int N = 1 ;//à completer en fonction du nb de led.Ici cas simple n=1
    for (int i = 1;i<=N;i++){
        scheduleOn(i,MONDAY,1200,LIGHT_ON);
    }

    //Je mets mon horloge à l'heure de l'évènement
    Time X ;
    X.minuteOfDay = 1200;
    X.day = MONDAY;

    FakeTimeService_setTime(&X);

    //je réveille l'évènement
    wakeUp();

    for (int i = 1; i<=N; i++){
        TEST_ASSERT_EQUAL(i, LightControlSpy_getLastLightId() );
    }
 }

//    The actual switching is taken care of by a separate light control driver.
void testSeparateDriver(void){
    //j'initialise 
    LightControl_init();

    //Je lance le contrôle sur une led via le driver
    LightControl_on(18);

    //Je fais mes tests
    TEST_ASSERT_EQUAL( 18, LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL( LIGHT_ON, LightControlSpy_getLastState() );
}
//    If an event is scheduled, it will be triggered only on the specified day and within one minute around the specified time.

//    The user can schedule switching a light on or off on a specific day of the week at a specific time.
void testScheduleTime(void){
    create();
    scheduleOn(42,MONDAY,1200,LIGHT_ON);

    //Je mets mon horloge à l'heure de l'évènement
    Time X ;
    X.minuteOfDay = 1200;
    X.day = MONDAY;

    FakeTimeService_setTime(&X);


    //Je réveille mon évènement
    wakeUp();

    //Je teste si  
    TEST_ASSERT_EQUAL( 42, LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL( LIGHT_ON, LightControlSpy_getLastState() );

}
//    The user can schedule switching a light on or off everyday at a specific time.
void testScheduleHour(void){
    //j'intialise mon scheduler
    create();
    
    //Je crée mon événement
    scheduleOn(42,EVERYDAY,1200,LIGHT_ON);

    //Je mets mon horloge à l'heure de l'évènement
    Time X ;
    X.minuteOfDay = 1200;
    X.day = MONDAY;

    FakeTimeService_setTime(&X);


    //Je réveille mon évènement

    wakeUp();

        //Je teste si  
    TEST_ASSERT_EQUAL( 42, LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL( LIGHT_ON, LightControlSpy_getLastState() );

}
//    The user can schedule switching a light on or off during weekends (Saturday and Sunday).
void testScheduleWeekend(void){
    create();
    scheduleOn(42,WEEKEND,1200,LIGHT_ON);

    //Je mets mon horloge à l'heure de l'évènement
    Time X ;
    X.minuteOfDay = 1200;
    X.day = MONDAY;

    FakeTimeService_setTime(&X);


    //Je réveille mon évènement
    wakeUp();

        //Je teste si  
    TEST_ASSERT_EQUAL( 42, LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL( LIGHT_ON, LightControlSpy_getLastState() );

}
//    The user can schedule switching a light on or off during week days (Monday till Friday).
void testScheduleWeekday(void){
    create();
    scheduleOn(42,WEEKDAY,1200,LIGHT_ON);

    //Je mets mon horloge à l'heure de l'évènement
    Time X ;
    X.minuteOfDay = 1200;
    X.day = MONDAY;

    FakeTimeService_setTime(&X);


    //Je réveille mon évènement
    wakeUp();

            //Je teste si  
    TEST_ASSERT_EQUAL( 42, LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL( LIGHT_ON, LightControlSpy_getLastState() );
}
//    The user can schedule multiple events for the same light.
void testScheduleMultipleEventsSameLed(void){
    create();
    scheduleOn(12,MONDAY,1200,LIGHT_ON);
    scheduleOn(12,TUESDAY,1200,LIGHT_ON);

   //Je mets mon horloge à l'heure du 1er évènement
    Time X ;
    X.minuteOfDay = 1200;
    X.day = MONDAY;

    FakeTimeService_setTime(&X);

    //Je réveille mon évènement
    wakeUp();

    //A voir : normalement, gestlastState permet juste de voir si c'est allumé
    TEST_ASSERT_EQUAL( 12, LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL( LIGHT_ON, LightControlSpy_getLastState() );

    //Je mets à l'heure du 2ème évènement
    Time Y ;
    Y.minuteOfDay = 1200;
    Y.day = MONDAY;

    FakeTimeService_setTime(&Y);

    //Je réveille mon évènement
    wakeUp();

    //A voir : normalement, gestlastState permet juste de voir si c'est allumé
    TEST_ASSERT_EQUAL( 12, LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL( LIGHT_ON, LightControlSpy_getLastState() );

}
//    The user can remove a scheduled event.
void testRemoveScheduleEvent(void){
    create();
    scheduleOn(30,MONDAY,1200,LIGHT_OFF);
    RemoveSchedule(30,MONDAY,1200,LIGHT_ON);

    //Je mets à l'heure du 2ème évènement
    Time Y ;
    Y.minuteOfDay = 1200;
    Y.day = MONDAY;

    FakeTimeService_setTime(&Y);

    //Je réveille mon évènement
    wakeUp();

    //je teste si
    TEST_ASSERT_EQUAL(30,LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL(LIGHT_OFF,LightControlSpy_getLastState() );
}

//    The user can schedule a maximum number of 256 events.
void testSchedule256EventsMax(void){
    for (int i=0;i<256;i++){
        create();
        scheduleOn(42,MONDAY,1200,LIGHT_OFF);
    }
    //Le 257eme événement 
    scheduleOn(42,MONDAY,1200,LIGHT_ON);
    wakeUp();
    //Je vérifie que le 257eme événement n'a pas lieu
    TEST_ASSERT_EQUAL( 42, LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL( LIGHT_OFF, LightControlSpy_getLastState() );
}



void testThatFailsBecauseItDoesNotTestAnything(void)
{
    TEST_ASSERT_MESSAGE( 0, "Go write some real tests!" );
}
