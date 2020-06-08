#include "LightControlSpy.h"
#include "unity.h"

void testLightControlSpyReturnsLastStateChange(void)
{
    LightControl_init();
    LightControl_on(18);
   
    TEST_ASSERT_EQUAL( 18, LightControlSpy_getLastLightId() );
    TEST_ASSERT_EQUAL( LIGHT_ON, LightControlSpy_getLastState() );

    LightControl_destroy();
}