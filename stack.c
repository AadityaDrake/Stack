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
	stack temp = s;
	printf("%s top: ",msg);
	while(temp != NULL){
		printf("%c ",temp->value);
		temp = temp->next;
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

void push(stack *s, char val)
{
	stack new1;
	new1 = malloc(sizeof(struct node));
	new1->value = val;
	if(*s == NULL){
		new1->next = NULL;
		*s = new1;
	}
	else{
		new1->next = *s;
		*s = new1;
	}
}

/* Story 4
 * As a programmer, I want to pop an item from a stack so I can use
 * the stack to parse expression.
 */

char pop(stack *s)
{
	char info;
	if(*s == NULL){
		printf("Error: pop(s, *val) empty stack s\n");
		info = '?';
	}
	else{
		stack temp = *s;
		info = temp->value;
		*s = (*s)->next;
		temp->next = NULL;
		free(temp);
	}
	return info;
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
  } else {
    printf("%s\n", brackets);
    fflush(stdout);
    for (int i = 0; i < mismatch; i++) {
      printf(" ");
    }
    printf("^ mismatch\n");
    fflush(stdout);
  }
}

int match_brackets(char *expression)
{
	stack s = NULL;
	char pop_char;
	int i,returner = 0;
	for(i=0 ; expression[i] != '\0' ; i++){
		if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
			push(&s,expression[i]);
		}
		else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
			if(s == NULL){
				returner = 1;
			}
			else{
				pop_char = pop(&s);
				if(pop_char == '(' && expression[i] == ')'){
					returner = -1;
				}
				else if(pop_char == '{' && expression[i] == '}'){
                                        returner = -1;
                                }
				else if(pop_char == '[' && expression[i] == ']'){
                                        returner = -1;
                                }
				else{
					returner = i;
					break;
				}
			}
		}
	}
	if(s != NULL) returner = i;
	return returner;	//return negative value if brackets match or balance, else return positive
}
