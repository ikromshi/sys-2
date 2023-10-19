#include <stdio.h>
#include <stdlib.h>

/* Code Listing 1.1:
   Header file for a generic FSM handler
 */

/* States and events should just be integers */
typedef int state_t;
typedef int event_t;

/* Dummy struct for circular typedefs 
 * We need to use the fsm definition in the function pointer
 * but we will eventually use the function pointer inside the 
 * fsm definition.  This is the circular typedef
 */
struct fsm;

/* Function pointer type declaration for effects */
typedef void (*action_t) (struct fsm *);

/* Generic FSM struct that could have other fields, as well */
typedef struct fsm {
  state_t state;  /* current state */
  size_t nevents; /* number of events for this FSM */
  /* pointer to the FSM's transition function */
  state_t (*transition) (struct fsm *, event_t, action_t *);
} fsm_t;

/* Invoke an event handler for a given FSM */
void handle_event (fsm_t *fsm, event_t event);

