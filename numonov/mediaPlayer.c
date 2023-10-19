/** Author: Ikrom Numonov
 * Modification: Posted Practicum
 * Last Modified: Oct 4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NIL 6

#ifndef LIST1
  #define LIST1
  #include "listing1.1.h"
#endif
#include "listing1.3.h"

/* Code Listing 1.4:
   Connecting the specific FSM with the generic interface
 */

/* Given FSM instance and event, perform the table lookups */
static state_t
media_transition (fsm_t *fsm, event_t event, action_t *effect)
{
  /* If the state/event combination is bad, return -1 */
  if (fsm->state >= NST || event >= NUM_EVENTS || _transition[fsm->state][event] == NST)
    return -1;
//
  /* Look up the effect and transitions in the tables */
  *effect = _effect[fsm->state][event];
  return _transition[fsm->state][event];
}

/* Return an FSM that links to these internals */
fsm_t *
media_init (void)
{
  fsm_t *fsm = calloc (1, sizeof (fsm_t));
  fsm->nevents = NUM_EVENTS;
  fsm->state = CONN;
  fsm->transition = media_transition;
  return fsm;
}

/* Effect start_load 
 *   start loading the bytes for playback
 */
void start_load(fsm_t *fsm){
  printf("Loading the CD\n");
}

/* Effect resume 
 *   resume playback
 */
void resume(fsm_t *fsm){
  printf("resuming play\n");
}

/* Effect pause_play 
 *   pause playback
 */
void pause_play(fsm_t *fsm){
  printf("pausing play\n");
}

/** Effect stop_playback
 * stop playback
 */
void stop_playback(fsm_t *fsm) {
  printf("Stopping playback\n");
}

/* Effect closing
 *   handle actions when closing
 */
void closing(fsm_t *fsm){
  printf("Closing\n");
}

/* Effect play2x
 *   play at double speed (fast forward)
 */
void play2x(fsm_t *fsm){
  printf("Playing at double speed (FastForward)\n");
}


/* Code Listing 1.5:
   Creating an instance of the FSM and sending it events
 */
int main(){
  fsm_t *fsm = media_init ();
//  handle_event (fsm, Connect);
//  handle_event (fsm, Connect); /* no transition here ! */
//  handle_event (fsm, Ready);

  char input[50];
  char continueInput[10];
  event_t event;

  printf("Available events:\n");
  printf("0 - Connect\n1 - Ready\n2 - Suspend\n3 - Cancel\n4 - Finish\n5 - FastFwd\n");


  while (1) {
      printf("Enter event number: ");
      fgets(input, sizeof(input), stdin);

      // Removing newline character from input
      size_t len = strlen(input);
      if (len > 0 && input[len-1] == '\n') {
          input[len-1] = '\0';
      }

      event = atoi(input);
      handle_event(fsm, event);

      // Display the current state (based on the `ms_t` enumeration)
      char *states[] = { "CONN", "BUFF", "PLAY", "CLOS", "NST" };
      if (fsm->state < NST) {
          printf("Current state: %s\n\n", states[fsm->state]);
      } else {
          printf("Invalid state reached.\n\n");
      }

      printf("Do you want to enter another event? (yes/No): ");
      fgets(continueInput, sizeof(continueInput), stdin);
      // Remove newline from continueInput
      len = strlen(continueInput);
      if (len > 0 && continueInput[len-1] == '\n') {
          continueInput[len-1] = '\0';
      }

      if (strcmp(continueInput, "no") == 0 || strcmp(continueInput, "No") == 0) {
          break;
      }
  }

  free(fsm);
  return 0;
}

