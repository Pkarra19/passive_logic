#ifndef TEST_C
#define TEST_C

#include <stdio.h>
#include <assert.h>
#include "state_machine.h"

void test_initial_state(void)
{
    state_machine intersection;
    init(&intersection);
    assert(intersection.states == NS_GREEN_EW_RED);
    assert(intersection.timer == 10);
    printf("PASSED: Inital State Test\r\n");
}

void test_update_state(void)
{
    state_machine intersection;

    intersection.timer = 5;
    update(&intersection);
    assert(intersection.states == NS_GREEN_EW_RED);
    printf("PASSED: Remain in init state with timer greater than 0\r\n");

    intersection.timer = 0;
    update(&intersection);
    assert(intersection.states == NS_YELLOW_EW_RED);
    printf("PASSED: NS_GREEN_EW_RED to NS_YELLOW_EW_RED\r\n");

    intersection.timer = 0;
    update(&intersection);
    assert(intersection.states == NS_RED_EW_GREEN);
    printf("PASSED: NS_YELLOW_EW_RED to NS_RED_EW_GREEN\r\n");

    intersection.timer = 0;
    update(&intersection);
    assert(intersection.states == NS_RED_EW_YELLOW);
    printf("PASSED: NS_RED_EW_GREEN to NS_RED_EW_YELLOW\r\n");

    intersection.timer = 0;
    update(&intersection);
    assert(intersection.states == NS_GREEN_EW_RED);
    printf("PASSED: NS_RED_EW_YELLOW to NS_GREEN_EW_RED\r\n");

}

int main()
{
    test_initial_state();
    test_update_state();
}
#endif /* TEST_C */