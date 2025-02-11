#ifndef STATE_MACHINE_C
#define STATE_MACHINE_C

#include <stdio.h>
#include <unistd.h>
#include "state_machine.h"

/* Set an init state light and timer */
void init(state_machine* current_state)
{
    current_state->states = NS_GREEN_EW_RED;
    current_state->timer = 10;
}

void update(state_machine* current_state)
{
    switch (current_state->states)
    {
        case (NS_GREEN_EW_RED):
        printf("NS: Green | EW: Red\r\n");
        printf("Timer: %d\r\n", current_state->timer);
        if (current_state->timer <=0)
        {
            current_state->states = NS_YELLOW_EW_RED;
            current_state->timer = 5;
        }
        break;

        case (NS_YELLOW_EW_RED):
        printf("NS: Yellow | EW: Red\r\n");
        printf("Timer: %d\r\n", current_state->timer);
        if (current_state->timer <=0)
        {
            current_state->states = NS_RED_EW_GREEN;
            current_state->timer = 10;
        }
        break;

        case (NS_RED_EW_GREEN):
        printf("NS: Red | EW: Green\r\n");
        printf("Timer: %d\r\n", current_state->timer);
        if (current_state->timer <= 0)
        {
            current_state->states = NS_RED_EW_YELLOW;
            current_state->timer = 5;
        }
        break;

        case (NS_RED_EW_YELLOW):
        printf("NS: Red | EW: Yellow\r\n");
        printf("Timer: %d\r\n", current_state->timer);
        if (current_state->timer <= 0)
        {
            current_state->states = NS_GREEN_EW_RED;
            current_state->timer = 10;
        }
        break;
    }
    (--current_state->timer);
}

/* Using a directive since I have multiple mains */
#ifdef SIMULATE
int main()
{
    state_machine traffic_light;
    init(&traffic_light);

    for (int i = 0; i<100; i++)
    {
        update(&traffic_light);
        sleep(1);
    }
}
#endif /* SIMULATE */

#endif /* STATE_MACHINE_C */