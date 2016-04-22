#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

/*****************************************
 *
 * Queue
 *
 *****************************************/

/* Story 8
 * As a programmer, I want to be able to print a queue, so I can see
 * what is in it.
 */

void pq(q_node q)
{
}

void print_queue(char *msg, queue q)
{
  printf("%s front: ", msg);
  fflush(stdout);
  pq(q.front);
  printf(":rear\n");
  fflush(stdout);
}

void print_queue_plus(char *before, queue q, char *after)
{
  printf("%s front: ", before);
  fflush(stdout);
  pq(q.front);
  printf(":rear %s", after);
  fflush(stdout);
}

/* Story 9
 * As a programmer, I want to be able to enqueue a character in a
 * queue, so I can learn how queues work.
 */

queue enqueue(queue q, char val)
{
}

/* Story 10
 * As a programmer, I want to dequeue an item from a queue so I can
 * learn to use queues.
 */

char dequeue(queue *q)
{
}
