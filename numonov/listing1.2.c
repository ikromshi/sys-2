#include <stdio.h>
#include <stdlib.h>

#ifndef LIST1
  #define LIST1
  #include "listing1.1.h"
#endif

/* Code Listing 1.2:
   Body of handle_event() for a generic FSM handler
Paramters:
   fsm_t *fsm a pointer to a fsm struct
   event_t event the event that has occurred
 */

void handle_event (fsm_t *fsm, event_t event)
{
  /* Confirm the event is valid for the given FSM */
  if (event >= fsm->nevents)
    return;

  /* Use the FSM's lookup tables; if next is -1, the event is not
     defined for the current state */
  action_t effect = NULL;
  state_t next = fsm->transition (fsm, event, &effect);
  if (next == -1)
    return;

  /* Perform the effect (if defined) and change the state */
  if (effect != NULL)
    effect (fsm);
  fsm->state = next;
}
