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
	istack temp = s;
	printf("%s top: ",msg);
	while(temp != NULL){
		printf("%d ",temp->value);
		temp = temp->next;
	}
	printf(": bottom");
	printf("\n");
}

void ipush(istack *s, int val)
{
	istack new1;
	new1 = malloc(sizeof(struct inode));
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

int ipop(istack *s)
{
	int pop_int = 0;
	if(*s == NULL){
		printf("Error: pop(s, *val) empty stack s\n");
		pop_int = -1;
	}
	else{
		istack temp = *s;
		*s = (*s)->next;
		pop_int = temp->value;
		temp->next = NULL;
		free(temp);
	}
	return pop_int;
}

/* Story 7
 * As a programmer, I want to implement a program that will evaluate
 * expressions based on postfix notation, so I can see how it is
 * done.
 */

int eval_postfix(char *expr)
{
	istack s = NULL;
	int opr2=0,opr1=0,valu=0,result=0;
	for(int i = 0 ; expr[i] != '\0' ; i++){
		if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/'){
			opr2 = ipop(&s);
			opr1 = ipop(&s);
			switch(expr[i]){
				case '+' :
					valu = opr1+opr2;
					break;
				case '-' :
					valu = opr1-opr2;
					break;
				case '*' :
					valu = opr1*opr2;
					break;
				case '/' :
					valu = opr1/opr2;
					break;
				default:
					valu = 0;
			}
			ipush(&s,valu);
		}
		else if(expr[i] >= '0' && expr[i] <= '9'){
			int k = expr[i] - '0';
			ipush(&s,k);
		}
	}
	result = ipop(&s);
	return result;
}
