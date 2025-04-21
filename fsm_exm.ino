typedef enum state_e {ONE_E,TWO_E,THREE_E,FOUR_E} state_t;

state_t state;
state_t next_state;

#define CONDITION 0

void fsm_execute();
void fsm_switch();

void setup()
{
  Serial.begin(9600);
  state = ONE_E;
  next_state = ONE_E;
}
void loop ()
{
    fsm_execute();
    fsm_switch();
}

void fsm_execute()
{
    switch (state)
    {
        case (ONE_E):
            next_state = TWO_E;
            Serial.print("1\n");
        break;
        
        case (TWO_E):
            if (CONDITION)
                next_state = FOUR_E;
            else
                next_state = THREE_E;
            Serial.print("2\n");
        break;
        
        case (THREE_E):
            if (CONDITION)
                next_state = THREE_E;
            else
                next_state = FOUR_E;
            Serial.print("3\n");
        break;
        
        case (FOUR_E):
            if (CONDITION)
                next_state = THREE_E;
            else
                next_state = FOUR_E;
            Serial.print("4\n");
        break;
        
        default:
            next_state = 1;
        break;
    }
}

void fsm_switch()
{
    state = next_state;
}
