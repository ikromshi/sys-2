#include <stdio.h>
#include <stdlib.h>

/* Code Listing 1.3:
   Internal state and lookup table definitions for Figure 1.5.1
 */

/* these are defined elsewhere but used in this file */
extern void start_load(struct fsm *);
extern void resume(struct fsm *);
extern void pause_play(struct fsm *);
extern void closing(struct fsm *);
extern void play2x(struct fsm *);

/* Internal type definition of states */
typedef enum { CONN, BUFF, PLAY, CLOS, FFWD, NST } ms_t;
/* Internal type definition of events */
typedef enum { Connect, Ready, Suspend, Cancel, Finish, FastFwd, Done} event;
#define NUM_STATES (NST+1)
//#define NUM_EVENTS (4+1)

 #define NUM_EVENTS (NIL+1)

/* Lookup table for transitions; row=state, column=event */
static ms_t const _transition[NUM_STATES][NUM_EVENTS] = {
  // Connect Suspend Ready   Finish Cancel FastFwd Done
  {  BUFF,   NST,    NST,    NST,   NST,   NST,    NST }, // Connecting
  {  NST,    NST,    PLAY,   NST,   CLOS,  NST,    NST }, // Buffering
  {  NST,    BUFF,   NST,    CLOS,  NST,   FFWD,   NST }, // Playing
  {  NST,    NST,    NST,    NST,   NST,   NST,    NST },  // Closing
  {  NST,    NST,    NST,    NST,   NST,   NST,    PLAY } // FastForward
};

/* Lookup table for effects; row=state, column=event */
static action_t const _effect[NUM_STATES][NUM_EVENTS] = {
  // Connect     Suspend     Ready   Finish Cancel   FastFwd Done
  {  start_load, NULL,       NULL,   NULL,  NULL,    NULL,   NULL }, // Connecting
  {  NULL,       NULL,       resume, NULL,  closing, NULL,   NULL }, // Buffering
  {  NULL,       pause_play, NULL,   closing,  NULL, play2x, NULL }, // Playing
  {  NULL,       NULL,       NULL,   NULL,  NULL,    NULL,   NULL },  // Closing
  {  NULL,       NULL,       NULL,   NULL,  NULL,    NULL,   resume }, // FastForward

};
