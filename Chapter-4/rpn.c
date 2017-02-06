/* Reverse Polish Calculator */
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* Max size of operand or operator */
#define NUMBER '0' /* Signal that a number was found */ 

int getop(char []);
void push(double);
double pop(void);

/* Main */
int main() 
{
  int type;
  double op2;
  char s[MAXOP];

  while( (type = getop(s)) != EOF ) {
      switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop(); // We need this b/c `-` is not commutative
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s", s);
            break;
      }
  }

  return 0;
}

/* Push and POP */
#define MAXVAL 100 /* Maximum depth of val stack */

int sp = 0; /* Next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) 
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, cant push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty.\n");
        return 0.0;
    }
}

/* getop */
#include <ctype.h>

int getch(void); 
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while( (s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c; /* Not a number */
    i = 0;
    if(isdigit(c)) /* Collect Integer part */
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.') /* Collect fraction part */
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0'
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

/* getch and ungetch */
#define BUFSIZE 100

char buf[BUFSIZE]; /* Buffer for unget */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

int ungetch(int c) /* push character back onto input */
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
