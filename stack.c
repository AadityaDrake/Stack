#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* Define in ui.c */
extern FILE *infile;     // input file
extern FILE *outfile;    // output file
extern FILE *errfile;    // error file

/*****************************************
 *
 * Stacks
 *
 *****************************************/

/*
 * Test code: lets you print the contents of a stack with a message.
 */
void print_stack(char *msg, stack s)
{
        stack temp=s;
        printf("%s top: ",msg);
        while(temp!=NULL) {
                printf("%c ",temp->value);
                temp=temp->next;
        }
  printf(" : bottom\n");
}

void print_stack_plus(char *before, stack s, char *after)
{
  printf("\n");
}

/* Story 3
 * As a programmer, I want to be able to push an item on a stack, so I
 * can use the stack to parse expressions.
 */

void push(stack *s, char val) {
        stack n=malloc(sizeof(struct node));
        n->value=val;
        if(*s == NULL) {
                n->next=NULL;
                *s=n;
        }
        else {
                n->next=*s;
                *s=n;
        }
}


/* Story 4
 * As a programmer, I want to pop an item from a stack so I can use
 * the stack to parse expression.
 */

char pop(stack *s)
{
        char x = '\0';
        stack t;

        if(*s == NULL)
                printf("Error: pop(s, *val) empty stack s\n)");
        else {
                t=*s;
                x=t->value;
                *s = (*s)->next;
                t->next = NULL;
                free(t);
        }
        return x;
}

/* Story 5
 * As a programmer, I want to implement bracket matching to see how it
 * works.
 */
void test_match_brackets(char *brackets)
{
        int mismatch = 0;
        if ((mismatch = match_brackets(brackets)) < 0) {
                printf("%s\n", brackets);
                printf("Brackets match\n");
                fflush(stdout);
        }
        else {
                printf("%s\n", brackets);
                fflush(stdout);
                for (int i = 0; i < mismatch; i++)                              printf(" ");
                printf("^ mismatch\n");
                fflush(stdout);
        }
}

int match_brackets(char *expression)
{
        stack s = NULL;
        char top = '\0';

        for(int i=0; expression[i] != '\0'; i++) {
                if (expression[i] == '(' || expression[i] == '{' ||
			expression[i] == '[' || expression[i] == '<') {
                        push(&s, expression[i]);
                }
		else if (expression[i] == ')' || expression[i] == '}' ||
			 expression[i] == ']' || expression[i] == '>') {
                        if (s==NULL) {
                                return i;
                        }
                        else {
                                top = pop(&s);
                                if (top == '(' && expression[i] == ')')
                                        return -1;
                                if (top == '{' && expression[i] == '}')
                                        return -1;
                                if (top == '[' && expression[i] == ']')
                                        return -1;
                                if (top == '<' && expression[i] == '>')
                                        return -1;
                                return i;
                        }
                }
        }
	return 0;
}
