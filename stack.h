#ifndef arrays_h
#define arrays_h

#define TRUE 1
#define FALSE 0

struct node {
  char value;
  struct node *next;
};

typedef struct node *stack;

/*
  Stacks
*/

/* Test code */
void print_stack(char *msg, stack l);
void print_stack_plus(char *before, stack l, char *after);

/* Story 3 */
void push(stack *s, char i);

/* Story 4 */
char pop(stack *s);

/* Story 5 */
void test_match_brackets(char *brackets);
int match_brackets(char *expression);

#endif
