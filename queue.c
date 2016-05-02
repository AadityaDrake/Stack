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
	q_node front = q;
	while(front!=NULL) {
		printf("%c ",front->value);
		front=front->next;
	}
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
	q_node new1 =malloc(sizeof (q_node));
	new1->value = val;
	if(q.front == NULL) {
		q.front = new1;
		q.rear = new1;
	}
	else {
		q.rear->next = new1;
		q.rear = new1;
	}
	q.rear->next = NULL;
	return q;
}

/* Story 10
 * As a programmer, I want to dequeue an item from a queue so I can
 * learn to use queues.
 */

char dequeue(queue *q)
{
	q_node temp;
	char x;
	if(q->front == NULL) {
		printf("Error: dequeue of empty queue \n");
	}
	else {
		temp=q->front;
		q->front = q->front->next;
		temp->next = NULL;
		x = temp->value;
		free(temp);
	}
	return x;
}
