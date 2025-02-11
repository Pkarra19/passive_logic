#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef enum
{
    NS_RED_EW_GREEN,
    NS_RED_EW_YELLOW,
    NS_GREEN_EW_RED,
    NS_YELLOW_EW_RED,
} traffic_states;

typedef struct 
{
    traffic_states states;
    int timer;
} state_machine;

void init(state_machine* current_state);
void update(state_machine* current_state);

#endif /* STATE_MACHINE_H */
