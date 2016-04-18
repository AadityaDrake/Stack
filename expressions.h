#ifndef expressions_h
#define expressions_h

#define TRUE 1
#define FALSE 0

struct inode {
  int value;
  struct inode *next;
};

typedef struct inode *istack;

/*
  Expressions
*/

void print_istack(char *msg, istack s);

/* Story 6 */
void ipush(istack *s, int i);
int ipop(istack *s);

/* Story 7 */
int eval_postfix(char *expression);

#endif
