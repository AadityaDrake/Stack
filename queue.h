#ifndef queue_h
#define queue_h

#define TRUE 1
#define FALSE 0


/* struct node is defined in stack.h
struct node {
  char value;
  struct node *next;
};
*/
typedef struct node *q_node;

typedef struct queue_struct {
  q_node front;
  q_node rear;
} queue;

/*
  Queues
*/

/* Story 8 */
void print_queue(char *msg, queue q);
void print_queue_plus(char *before, queue q, char *after);

/* Story 9 */
queue enqueue(queue q, char val);

/* Story 4 */
char dequeue(queue *q);

#endif
