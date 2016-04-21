#include <stdio.h>
#include <stdlib.h>
#include "expressions.h"

/*****************************************
 *
 * Postfix Expressions
 *
 *****************************************/

/* Story 6
 * As a programmer, I want to reimplement a stack that contains
 * integers, so I can write the function to evaluate postfix
 * notation.
 */

void print_istack(char *msg, istack s)
{
	istack temp=s;
	printf("%s top: ",msg);
	while(temp!=NULL) {
		printf("%d ",temp->value);
		temp=temp->next;
	}
  	printf(" : bottom\n");
}

void ipush(istack *s, int val)
{
	istack n=malloc(sizeof(struct inode));
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

int ipop(istack *s)
{
	int x;
	istack t;
	if(*s == NULL){
		printf("Error: pop(s, *val) empty stack s\n)");
		x=-1;
	}
	else {
		t=*s;
		*s = (*s)->next;
		x=t->value;
		t->next = NULL;
		free(t);
	}
	return (x);
}

/* Story 7
 * As a programmer, I want to implement a program that will evaluate
 * expressions based on postfix notation, so I can see how it is
 * done.
 */

int eval_postfix(char *expr)
{
	istack top = NULL;
	int op2=0,op1=0,val=0,r,p;
	for(int i = 0 ; expr[i] != '\0' ; i++) {
		if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i]== '^') {
			op1 = ipop(&top);
			op2 = ipop(&top);
			switch(expr[i]) {
				case '+' :
					val = op2+op1;
					break;
				case '-' :
					val = op2-op1;
					break;
				case '*' :
					val = op2*op1;
					break;
				case '/' :
					val = op2/op1;
					break;
				default:
					val = 0;
			}
			ipush(&top,val);
		}
		if(expr[i] >= '0' && expr[i] <= '9'){
			p = expr[i]-'0';
			ipush(&top,p);
		}
	}
	r = ipop(&top);
	return r;
}
