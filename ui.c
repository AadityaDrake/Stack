#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "expressions.h"
#include "ui.h"

/*****************************************
 * Initialize
 * This section contains the definitions of the parameters and
 * initilaize(), the function that will initialize the parameters to
 * control the operation of execute().
 *****************************************/

FILE *infile = NULL;     // input file
FILE *outfile = NULL;    // output file
FILE *errfile = NULL;    // error file

void print_help(void)
{
  printf("stack: parameters are\n");
  printf("\t-h: print this message\n");
}

/*
 * initialize(argc, argv)
 * parses the parameters to the program
 * return TRUE if successful; FALSE if there is an error
 */
int initialize(int argc, char *argv[])
{
  /* argv[0] is the name of the program */
  int arg = 1,q;
  char *parameter = "";
char expr[20];

  infile = stdin;         // input file defaults to stdin
  outfile = stdout;       // output file defaults to stdout
  errfile = stderr;       // error file; defaults to stderr
  while(arg < argc) {
    parameter = argv[arg];
        printf("argv[%d]=%s\n",arg,parameter);
        arg++;

    switch(parameter[1]) {
        case 'x':
                printf("error: unknown parameter -x\n");
                print_help();
                        break;
        case 'h':
                print_help();
                        break;
        case 'b':
                printf("Enter Expression :: ");
                scanf("%s", expr);
                test_match_brackets(expr);
			break;
        case 'p':
                printf("Enter Expression :: ");
                scanf("%s", expr);
                q=eval_postfix(expr);
                printf("Evaluated No. is %d\n",q);
                        break;
    /* Story 5
     * As a user, I want to be able to enter a set of brackets to see
     * if they are matched at the command line, so I can use the
     * program to match brackets.
     */

    /* Story 2
     * As a user, I want my program to notify me when I enter an
     * incorrect parameter and tell me what the correct parameters
     * are, so I do not need to remember all of the parameters.
     */
    }
  }
  return TRUE;
}

/*****************************************
 * Execute
 * This section contains the definitions of execute(), the function
 * calls the functions that do the work.
 *****************************************/

int execute()
{
  printf("execute() called\n");
  return 0;                        // execution terminated normally
}

/*****************************************
 * Get
 * This section contains the functions that
 * Get an integer: get_int
 * get a float: get float
 *****************************************/

int is_whitespace(char c) {
  return (' ' == c || '\t' == c || '\n' == c);
}

char get_first_non_white(char *s) {
  for (int i = 0; '\0' != s[i] && i < 80; i++) {
    if (!is_whitespace(s[i])) {
      return(s[i]);
    }
  }
  return('\0');
}

/*
  read numbers: float and int
*/
int consume_digits(char *s)
{
  int i = 0;
  while (i < 80 && ('0' == s[i] ||
                    '1' == s[i] ||
                    '2' == s[i] ||
                    '3' == s[i] ||
                    '4' == s[i] ||
                    '5' == s[i] ||
                    '6' == s[i] ||
                    '7' == s[i] ||
                    '8' == s[i] ||
                    '9' == s[i] )
         ) {
    i++;
  }
  return i;
}

int can_be_float(char *s)
{
  int i = 0;
  if (s[i] == '-') {
    i++;
  }
  i += consume_digits(&s[i]);
  if ('\0' == s[i]) {
    return TRUE;
  }
  if ('.' == s[i]) {
    i += consume_digits(&s[i+1]) + 1;
  }
  if ('\0' == s[i]) {
    return TRUE;
  }
  return FALSE;
}

float get_float(char *msg)
{
  char buf[80] = "x";
  float f = 0.0;

  printf("%s> ", msg);
  scanf("%80s", buf);
  while(!can_be_float(buf)) {
    printf("%s is not a float> ", buf);
    scanf("%80s", buf);
  }
  sscanf(buf, "%f", &f);
  return f;
}

int can_be_int(char *s)
{
  int i = 0;
  if (s[i] == '-') {
    i++;
  }
  i += consume_digits(&s[i]);
  if ('\0' == s[i]) {
    return TRUE;
  }
  return FALSE;
}

int get_int(char *msg)
{
  char buf[80] = "x";
  int i = 0;

  printf("%s> ", msg);
  scanf("%80s", buf);
  while(!can_be_int(buf)) {
    printf("%s is not an integer> ", buf);
    scanf("%80s", buf);
  }
  sscanf(buf, "%d", &i);
  return i;
}
