#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "stack.h"
#include "queue.h"
#include "expressions.h"

/***************************************************
 *
 * Stacks
 *
 ***************************************************/

/* Story 1 and 2 are tested at the command line */

/* Story 3
 * As a programmer, I want to be able to push an item on a stack, so I
 * can use the stack to parse expressions.
 */
void test3(void)
{
  stack test = NULL;

  printf("Test 3: push\n");
  fflush(stdout);

  push(&test, 'a');
  print_stack("pushed a", test);
  push(&test, 'b');
  print_stack("pushed b", test);
  push(&test, 'c');
  print_stack("pushed c", test);
}

/* Story 4
 * As a programmer, I want to pop an item from a stack so I can use
 * the stack to parse expression.
 */
void test4(void)
{
  stack test = NULL;

  printf("Test 4: pop\n");
  fflush(stdout);

  push(&test, 'a');
  print_stack("pushed a", test);
  push(&test, 'b');
  print_stack("pushed b", test);
  push(&test, 'c');
  print_stack("pushed c", test);

  char val = '0';
  val = pop(&test);
  printf("popped %c ", val);
  fflush(stdout);
  print_stack("after pop", test);
  val = pop(&test);
  printf("popped %c ", val);
  fflush(stdout);
  print_stack("after pop", test);
  val = pop(&test);
  printf("popped %c ", val);
  fflush(stdout);
  print_stack("after pop", test);
  val = pop(&test);
  printf("popped %c ", val);
  fflush(stdout);
  print_stack("after pop", test);
}

/* Story 5
 * As a user, I want to be able to enter a set of brackets to see if
 * they are matched at the command line, so I can use the program to
 * match brackets.
 */

void test5(void)
{
  printf("Test 5: match_brackets\n");
  fflush(stdout);

  test_match_brackets("()");
  test_match_brackets("(]");
  test_match_brackets("[]");
  test_match_brackets("{}");
  test_match_brackets("(a + b)");
  test_match_brackets("{[ x * (a + b)] }");
  test_match_brackets("{[ x * (a + b}] }");
}

/* Story 6
 * As a programmer, I want to reimplement a stack that contains
 * integers, so I can write the function to evaluate postfix
 * notation.
 */

void test6(void)
{
  istack test = NULL;

  printf("Test 6: integer stack\n");
  fflush(stdout);

  ipush(&test, 1);
  print_istack("pushed 1", test);
  ipush(&test, 2);
  print_istack("pushed 2", test);
  ipush(&test, 3);
  print_istack("pushed 3", test);

  int val = 0;
  val = ipop(&test);
  printf("popped %d ", val);
  fflush(stdout);
  print_istack("after pop", test);
  val = ipop(&test);
  printf("popped %d ", val);
  fflush(stdout);
  print_istack("after pop", test);
  val = ipop(&test);
  printf("popped %d ", val);
  fflush(stdout);
  print_istack("after pop", test);
  val = ipop(&test);
  printf("popped %d ", val);
  fflush(stdout);
  print_istack("after pop", test);
}

/* Story 7
 * As a programmer, I want to implement a program that will evaluate
 * expressions based on postfix notation, so I can see how it is
 * done.
 */

void test_postfix(char * expr)
{
  printf("eval_postfix(\"%s\"): %d\n", expr, eval_postfix(expr));
  fflush(stdout);
}

void test7(void)
{
  printf("Test 7: evaluate_postfix\n");
  fflush(stdout);

  test_postfix("1 2 +");
  test_postfix("1 2 -");
  test_postfix("3 2 *");
  test_postfix("4 2 /");
  test_postfix("20 4 +");
  test_postfix("2 40 +");
  test_postfix("20 40 +");
  test_postfix("10 20 40 + -");
  test_postfix("10 20 40 + /");
  test_postfix("10 20 + 40 -");
  test_postfix("10 20 * 40 -");
}

/***************************************************
 *
 * Stacks
 *
 ***************************************************/

queue new_queue(void)
{
  queue *q = malloc(sizeof(queue));
  q->front = NULL;
  q->rear = NULL;
  return *q;
}

queue make_test_queue(void)
{
  queue *q = NULL;
  q_node qn = NULL;

  q = malloc(sizeof(queue));
  q->front = q->rear = malloc(sizeof(q_node));
  q->rear->value = 'a';
  q->rear->next = NULL;

  qn = malloc(sizeof(q_node));
  qn->value = 'b';
  qn->next = NULL;
  q->rear->next = qn;
  q->rear = qn;

  qn = malloc(sizeof(q_node));
  qn->value = 'c';
  qn->next = NULL;
  q->rear->next = qn;
  q->rear = qn;

  return *q;
}

/* Story 8
 * As a programmer, I want to be able to print a queue, so I can see
 * what is in it.
 */

void test8(void)
{
  queue q = make_test_queue();

  printf("Test 8: print_queue\n");
  fflush(stdout);
  print_queue("Test queue (a b c) ", q);
}

/* Story 9
 * As a programmer, I want to be able to enqueue a character in a
 * queue, so I can learn how queues work.
 */

void test9(void)
{
  queue q = new_queue();

  printf("Test 9: enqueue\n");
  fflush(stdout);
  q = enqueue(q, 'a');
  printf("Returning  front: a :rear");
  print_queue("\nadded 'a'", q);
  q = enqueue(q, 'b');
  printf("Returning  front: a b :rear");
  print_queue("\nadded 'b'", q);
  q = enqueue(q, 'c');
  printf("Returning  front: a b c :rear");
  print_queue("\nadded 'c'", q);
}

/* Story 10
 * As a programmer, I want to dequeue an item from a queue so I can
 * learn to use queues.
 */

void test10(void)
{
  queue q = make_test_queue();

  printf("Test 10: dequeue\n");
  fflush(stdout);
  print_queue("Test queue (a b c) ", q);
  printf("Retrieved %c ", dequeue(&q));
  print_queue("queue is now ", q);
  q = enqueue(q, 'd');
  printf("Returning  front: b c d :rear\n");
  print_queue("added 'd'", q);
  printf("Retrieved %c ", dequeue(&q));
  print_queue("queue is now ", q);
  printf("Retrieved %c ", dequeue(&q));
  print_queue("queue is now ", q);
  printf("Retrieved %c ", dequeue(&q));
  print_queue("queue is now ", q);
  printf("Retrieved %c ", dequeue(&q));
  print_queue("queue is now ", q);
}

int main(void)
{
  initialize(0, NULL);
  char * stars = "*****************************************************\n";

  printf("%s*\n* Stacks\n*\n%s", stars, stars);
  test3();
  test4();

  printf("%s*\n* Expressions\n*\n%s", stars, stars);
  test5();
  test6();
  test7();

  printf("%s*\n* Queues\n*\n%s", stars, stars);
  test8();
  test9();
  test10();

}
