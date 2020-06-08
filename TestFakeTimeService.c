#include "FakeTimeService.h"
#include "unity.h"

void testFakeTimeService_setTime(void)
{
    Time X;
    Time Y;
    X.day = MONDAY;
    X.minuteOfDay = 1200;
    
    Y.day = MONDAY;
    Y.minuteOfDay = 1200;


    TimeService_init();
    FakeTimeService_setTime(&X);

    TimeService_getTime(&Y);
   
    TEST_ASSERT_EQUAL( X.day, Y.day );
    TEST_ASSERT_EQUAL( X.minuteOfDay, Y.minuteOfDay);

    TimeService_destroy();
}