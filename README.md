# The C Programming Language 2nd Edition

This repository is a follow along with the book by [Brain W. Kernighan](https://en.wikipedia.org/wiki/Brian_Kernighan) and [Dennis M. Ritchie](https://en.wikipedia.org/wiki/Dennis_Ritchie).

[The C Programming Language 2nd Edition](https://www.amazon.com/Programming-Language-Brian-W-Kernighan/dp/0131103628/ref=sr_1_1?ie=UTF8&qid=1483068596&sr=8-1&keywords=the+c+programming+language "C Book on Amazon.com")

## Introduction

1. C is a general purpose programming language. It is closely assosiated with UNIX.

2. C inherits many ideas from BCPL, developed by Martin Richards and B by Ken Thompson.
  * While B and BCPL are typeless languages, C is not. C has characters, integers, and floating points.

3. There are also derived data types created with pointers, arrays, structures, and unions. 
  * Pointers allow for address arithmetic.

4. Expressions are formed operators and operands.
  * Any expression including assignment or a function call can be a statement.

5. C provides fundamental control-flow:
  1. if-else
  2. switch
  3. while, for
  4. do
  5. break

6. Functions:
  * Can return basic types, structures, unions, or pointers.
  * Can be called recursively.
  * Cannot be nested.
  * Variables can be declared in block-structed fashion.
  * Can exist in seperate source files.

7. C is a "Low Level Language".

8. C provides no operations to deal directly with composite objects:
  * Strings, sets, lists, or arrays
  * However most implementations come with basic libraries for these.

9. C was redifined by the ANSI in 1983.

## Chapter 1. A Tutorial Introduction

This chapter will be a simple introduction. Most of the content will be repeated in later chapters.

### 1.1 Getting started

The best way to learn any langauge is by writing programs in it.

We begin with the basic hello world program that prints out text onto the screen.

[Working hello world program](./Chapter-1/helloworld.c)

The following would have also worked:

```c
printf("hellow ");
printf("world")
printf("\n");
```

However the following wouldn't:

```c
printf("hello world
");
```

The `#include <stdio.h>` grabs the standard input/ouput library.

1. <b>Exercise 1.1: </b> Experiment with leaving out parts of the program.

2. <b>Exercise 1.2: </b> Experiment to find out what happens if you replace `/n` with a special character that DNE.

### 1.2 Variables and Arithmetic Expressions

Our next program prints a table of Farenheit temperatures and their coresponding values in Celsius using `C = (5/9)(F - 32)`.

The output should look like:

| Farenheit | Celsius |
| --------- | ------- |
| 0         | -17     |
| 20        | -6      |
| ...       | ...     |
| 280       | 137     |
| 300       | 148     |

You can see the program here [farenheit-celsius-table.c](./Chapter-1/farenheit-celsius-table.c)

Some importatnt things to take away:

1. How to write comments in C:
  * `//` Start single line comments.
  * `/* */` Hold multi-line comments.

2. All varibales must be declared first and have a type:
  * <b>int</b> a 16-bit or 32-bit integer.
  * <b>float</b> a 16-bit or 32-bit decimal number.
  * <b>char</b> character - a single byte.
  * <b>short</b> a short integer.
  * <b>long</b> a long integer.
  * <b>double</b> a double-precision floating point.

3. There is a special reason for `5 * (fahr - 32) / 9;`:
 * Integer division tuncates so 5/9 would be 0.

4. We get a more in depth view of how printf works:
  * See chapter 7 for more details.

Also there are some issues that we should fix:

1. The output doesn't look nice:
  * We can format it by specifying how big our outputs are like: 
  
  ```c
  printf("%3d %6d", fahr, celsius);
  ```

  * This will right align the second column.

2. Another issue that are results aren't accurate:
  * To fix this we should use floating point numbers instead.

Some Notes about `printf()`:

* `%d` prints as decimal integer.
* `%6d` prints as decimal integer at least 6 wide.
* `%f` prints as floating point.
* `%6f` prints as flaoting point at least 6 wide.
* `%.2f` prints as floating point 2 characters after the decimal point.
* `%6.2f` prints as floating point at least 6 wide and 2 characters after the decimal point.
* `%o` prints octals numbers.
* `%x` prints hexadecimal numbers.
* `%c` prints chars.
* `%s` prints strings.
* `%%` prints the % sign.

See this better version: [farenheit-celsius-table-better.c](./Chapter-1/farenheit-celsius-table-better.c).

1. <b>Exercise 1.3: </b> Modify temperature conversion to print out a table header.

2. <b>Exercise 1.4: </b> Write a program to print celsius to fahr table.

### 1.3 The For Statement

Now we can rewrite the same temperature table program using a [for loop](./Chapter-1/for-loop.c).

Notice that the program is less lines of code.

For loops and while loops are interchange.

1. <b>Exercise 1.5: </b> Modify the temperature conversion program to print the table in reverse order.

### 1.4 Character Input and output

We are now going to look at programs related to processing character data.

Text input regardless of where it originates is dealt with as a stream of characters.
A <b>text stream</b> is a sequence of characters divided into lines: each line consists of 0 or more characters followed by a new line character `\n`.
It is the libraries responsibility to make each output and input stream conform to this model.

The standard library provides several functions for reading and writing one character at a time.
The following are the easiest:

* `c = getchar()` reads the next input character.
* `putchar(c)` prints a character each time it is called.

#### 1.5.1 File Copying

See [file-copying.c](./Chapter-1/file-copying.c) for a basic file copy program.

This program simple outputs the inputs. 

We use an int because it is big enough to store the EOF.

EOF is an integer defined in stdio.h.

A more experience programmer could have written the program in better way like [this](./Chapter-1/file-copying-better.c)

In this verison we test for EOF as we grab them.

1. <b>Exercise 1.6: </b> Verify that the expression getchar() != EOF is 0 or 1.
2. <b>Exercise 1.7: </b> Write a program to print the value of EOF.

#### 1.5.2 Character Counting

Using the same logic as our last program we can easily count character.

[character-counting.c](./Chapter-1/character-counting.c)

In this example we see how we can use `++nc` or `nc++` to increment a varibale.
We can also use `--nc` or `nc--` to decrement the variable.

We use a `long` in this example because a `long` is always at least a 32 bit integer.

In the next example we cope with even bigger integers by using a `double` and a for loop for fun.

[character-counting-for.c](./Chapter-1/character-counting-for.c)

#### 1.5.3 Line Counting

The next program counts the input lines. All we have to do is count `\n`.

[line-counting.c](./Chapter-1/line-counting.c)

1. <b>Exercise 1.8: </b> Write a program to count blanks, tabs, and new lines.
2. <b>Exercise 1.9: </b> Write a program to copy input and output multiple spaces with a single space.
3. <b>Exercise 1.10: </b> Write a program to replace all tabs with \t and do the same for backspaces and backslashes.

#### 1.5.4 Word Counting

We are now going to create a barebones version of the UNIX wc program.
We define a word as a sequence of letters that does not contain a blank, tab, or newline.

[word-counting.c](./Chapter-1/word-counting.c)

Everytime the program incounters the character of a new word it counts a new word.
Notice how we used `#define` to create a symbolic constant for 0 and 1 this is the prefered method!

1. <b>Exercise 1.11: </b> How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
2. <b>Exercise 1.12: </b> Write a program that prints its input one word per line.

### 1.6 Arrays

In this section we are going to write some code to print the number of times we see each digit.

Instead of storing each occurence in a seperate variable we are going to store them in an array.

[digit-counting.c](./Chapter-1/digit-counting.c)

Notice that we are relying on the computation `c - '0'` to store the count in the correct array index.
Luckily the value for each digit is sequential.

1. <b>Exercise 1.13: </b> Write a program to print a histogram of the lengths of words in its input.
  * A verticle diagram is more challenging than a horizontal one.
2. <b>Exercise 1.14: </b> Write a program that prints a histogram of difference characters.

### 1.7 Functions

C has the ability to write functions similar to Fortan and Pascal.

Let's write our own function that computers the a ^ b or a**b.

[power.c](./Chapter-1/power.c)

The template for a function is:

```
  return-type function-name(paramete declarations)
  {
    declarations;
    statements;
  }
```

1. <b>Exercise 1.15: </b> Rewrite the temperature conversion program to use a function to convert temperatures.

### 1.8 Arguements - Call by value

One thing that is unique about C is that the values we pass the function are local copies.

This leads to some interesting results that we could not perform in Fortan or Pascal, where the original values are passed as a reference.

However can also pass a reference to the original value using a pointer, which we will see in Chapter 5.

This is not true for arrays though. When we call a function on an array we are passing a reference to the array in memory and not copying the array.


### 1.9 Character Array - Strings

The most common type of arrays in C is the array of characters.

To illustrate this let's write a simple program to print the longest line from input.

Here is the pseudo code:

```
while(there's another line)
  if(it's longer than the previous longest line)
    save it
    save its lengths
print longest line
```

Here is the actual code:

[print-longest-line.c](./Chapter-1/print-longest-line.c)

Strings in C are stored in arrays with `\0` to mark their end.
Here is an example of the string `"hello\n"`:

|   |   |   |   |   |   |   |
|---|---|---|---|---|---|---| 
|h  | e | l | l | o | \n| \0|

1. <b>Exercise 1.16: </b> Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines.
2. <b>Exercise 1.17: </b> Write a program to print all input lines that are longer that 80 characters.
3. <b>Exercise 1.18: </b> Write a program to remove trailing blanks and tabs from each line of input, and delete entirely blank lines.
4. <b>Exercise 1.19: </b> Write a function `reverse(s)` that reverses the character string s.

### 1.10 External Variables and Scope

The variables in main are private to main because main is a function.

The values that are unique to a funciton are called <b>automatic variables</b> and they go away after the function is done with them.

If we need that data to be persistent what we can do is declare <b>external variables</b> which are variables outside of a function as the next example shows.

[print-longest-line-extern.c](./Chapter-1/print-longest-line-extern.c)

Notes to access an external variable from within a function we must use the `extern` keyword.
However this keyword can be omitted under the correct circumstances.

1. <b>Exercise 1.20: </b> Write a program detab that replaces tabs in the input with the proper number of blank spaces.
2. <b>Exercise 1.21: </b> Write a program entab that basically does the reverse of detab.
3. <b>Exercise 1.22: </b> Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column.
4. <b>Exercise 1.23: </b> Write a program to remove all comments from a C program. Single lines and Multi lines too.
5. <b>Exercise 1.24: </b> Write a program to check a C program for rudimentary syntax errors. 

## Chapter 2. Types, Operators, and Expressions

Variables and constants are the basic data and objects manipulated in a program.

Declarations list the variables to be used, and state what type they have and perhaps their initial values.

ANSI made some important changes in this section:
* `signed` and `unsigned` forms of integers, constants and hexadecimal character constants.
* Floating-point operations may be done in single percision: there is also a `long double` type for higher precision.
* String costants may be concatenated at compile time.
* Enumerations have become part of the langauge.
* Objects can be declared `const` preventing them from being changed.
* The rules for automatic coercions among arithmetic types have been augmented to handle the richer set of types.

### 2.1 Variable Names

There are actually some restrictions to variable names that we didn't mention in Chapter 1:

* Names must be letters and numbers.
  * The first character must be a letter.
* `_` Underscore counts as a character.
* Lowecase and uppercase characters are distinct: so `x` is different from `X`.
  * Typically all caps are constants and variables are lowercase.
* Also keywords, like `if`, `long`, and `switch`, are reserved.

### 2.2 Data Types and Sizes

There are a few basic types in C:
* `char` a single byte, can hold one character in the local character set.
* `int` an integer, could be 16-bit or 32-bit.
* `float` a single-precision floating point.
* `double` double-precision floating point.

In addition, there are a number of qualifiers that can be applied to these basic types:

```c
  short int sh;
  long int counter;
```

The word `int` can be omitted in such declarartions and typically is.

The intent is that `short` and `long` should provide different lengths of integers.
`int` is usually the natural size of an integer in the machine, which could be 16-bit or 32-bit.
`short` is often 16-bit and `long` should be 32-bit.

`signed` and `unsigned` may be used as well. `unsinged` forces the the variable to be positive which allows it to be larger.
Whether plain `char` is `signed` or `unsigned` is machine-dependent.

1. <b>Exercise 2.1: </b> Write a program to determine the range of `char`, `short`, `int`, and `long` variables, both `signed` and `unsigned`. Also determine the ranges for floating-point types aswell.

### 2.3 constants

An integer constant like `1234` is an `int`. A `long` constant is written with a terminal `l` or `L` as in `123456789L`.
`Unsigned` constants are written with a terminal `u` or `U`, and the suffix `ul` or `UL`, indicates `unsigned long`.

Floating-point constants contain a decimal point (`123.4`) or an exponent (`1e-2`) or both.
There type is `double` unless suffixed. The suffixes `f` and `F` indicates a float.
`l` or `L` denotes a `long double`.

The value of an integer can be specified in octal or hexadecimal instead of decimal.
A leading `0X` means hexadecimal. For example, decimal 31 can be written as 037 in octal and 0x1f or 0X1F in hex.
Octal and hexadecimal constants may also be followed by `L` to make them long or `U` to make them unsigned.
`0XFUL` is an `unsigned long` constant with the value 15 decimal.

A <b>character constant</b> is an integer, written as one character within a single quotes, such as 'x'. 
The value of a character constant is the numeric value of the character in the machine's character set.
Character constants participate in numeric operations just as any other integers.

Certain characters can be represented in character and strings constants by escape sequence like `\n`;
these sequences look like two characters, but represent only one.

In addition, an arbitrary byte-sized bit patten can be specified by:

`'\ooo`

where `ooo` is one to three octal digits (0...7) or by

`\xhh`

where `hh` is one or more hexadecimal digits (0...9, a...f, A...F). So we might write:

```c
  #define VTAB '\013'; /* ASCII Vertical tab*/
  #define BELL '\007'; /* ASCII bell character */
```

or in hexadecimal:

```c
  #define VTAB '\xb';
  #define BELL '\x7';
```

The complete list of escape sequences is:

|character|name| 
|---|---|
|\a| alert (bell)|
|\b|backspace|
|\f|formfeed|
|\n|newline|
|\r|carriage return|
|\t|horizontal tab|
|\v| vertical tab|
|\\|backslash|
|\?|question mark|
|\'|single quote|
|\"|double quote|
|\ooo|octal number|
|\xhh|hexadecimal|
|\0|zero character|

A <b>constant expression</b> is an expression that involes only constants.

A <b>string constant</b> or <b>string literal</b> is a sequence of zero or more characters.

Note: `'x'` and `"x"` are not the same thing.

There are also <b>enumeration constants</b>. An enumeration is a list of constant integer values.

```c
enum boolean {NO, YES};
```

NO is automatically 0 and YES is 1;
It is also possible to define the constants in the enum as you declare it:

```c
enum escapes {BELL = '\a', BASKSPACE = '\b'}
```

If you only declare one value the next constants continues to increase. 
In the next example FEB is 2, MAR = 3, etc.

```c
enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
```
### 2.4 Declarations

All variables must be declared before use:

```c
int lower, upper, step;
char c, line[1000];
```

Variables can be distributed among declarations in any fashion:

```c
int lower;
int upper;
int step;
char c;
char line[1000];
```

A variable may also be initialized in its declaration:

```c
char esc = '\\';
int i = 0;
int limit = MAXLINE + 1;
float eps = 1.0e-5;
```

External and static variables are initialized automatically to 0;

The qualifier `const` can be applied to the declaration of any variable to to specify that it cannot change.

```c
const double e = 2.17828182845905;
const char msg[] = "warning: ";
```

The `const` declaration can also be used with array arguments, to indicate that the function doesn't change the array.

```c
int strlen(const char[]);
```
### 2.5 Arithmetic Operations

The binary arithmetic operations are `+, -, *, /`, and the modulos operation `%`.

Integer division truncates so the modulos operator get the remainder.

For example, a year is a leap year if it is divisible by 4 but not divisible by 100, except if it is divisible by 400.

```c
if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  printf("%d is a leap year.", year);
else
  printf("%d is not a leap year.", year);
```

The `%` operator cannot be applied to `float` or `double`. The operations also follow the order of operations.

### 2.6 Relational and Conditional Operations

The relational operations are:

```
> >= < <=
```

They all have the same precendence. Just below in precendence are:

```
== !=
```

Relational operations are lower in precendence then arithmetic ones.

More interesting are `&& ||` they are evaluated left to right and stop once the truth is known.

`&&` has higher precendence than `||`.

By definition the value is 1 if true and 0 if false.

There is also the unary operator `!` which turns 0 into 1 and vice versa.

### 2.7 Type Conversions

With operations types automatically become wider. For example a `char` would become an `int`.

One example is the following function to convert a `string` to an `int`.

```c
/* atoi: convert s to integer */
int atoi(char s[])
{
  int i, n;
  n = 0;
  for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}
```

Another example of `char` to `int` is the following program:

```c
/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
  if(c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}
```

We can force a typecase like in the following example:

```c
int n = 25;
double root2 = sqrt( (double) n); // sqrt requires a double.
```

1. <b>Exercise 2.3: </b> Write a function `htoi(s)`, which converts a string of hexadecimal digits into its equivalent integer value.

### 2.8 Increment and Decrement Operations

C has two increment operation `--` and `++` that subtract one and add one to the variable.

These values can be applied as a prefix or postfix operator.

if n is 5, then:

```c
x = n++;
```

will set x to 5 then increment n. As compared to:

```c
x = ++n;
```

which will increment n to 6 and then set x to n.

Note (i + j)++ is illegal.

Consider the following:

```c
/* squeeze: delete all c from s */
void squeeze(char a[], int c)
{
  int i, j;
  for(i = j = 0; s[i] != '\0'; i++)
    if(s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}
``` 

As a third example consider the standard function `strcat(s,t)`, which concatenate string t and s.

```c
/* strcat: concatenate t to the end of s */
void strcat(char s[], char t[])
{
  int i, j;
  i = j = 0;
  while(s[i] != '\0') /* find the end of s */
    i++;
  while((s[i++] = t[j++]) != '\0') /* copy */
    ;
}
```
As you can see after each copy both indexes are increased by 1 for the next asignment.

1. <b>Exercise 2.4: </b> Write an alternate version of `squeeze(s1, s2)` that deletes each character in `s1` that matches any character in `s2`.
2. <b>Exercise 2.5: </b> Write the function `any(s1, s2)`, which returns the first location in s1 where any character in s2 appears.

### 2.9 Bitwise Operations

C provides six operations for bit manipulation;
* `&` bitwise AND.
* `|` bitwise inclusive OR.
* `^` bitwise exclusive OR.
* `<<` left shift.
* `>>` right shift.
* `-` one's complement (unary).

The bitwise AND is often used to mask off some set of bits;

```c
n = n & 0177; //sets to zero all but the low-order 7 bits of n
```

The bitwise OR is used to turn bits on:

```c
x = x | SET_ON; //set to one the bits that are one in SET_ON
```

The exclusive OR is used to set to 1 in each bit position where the operands have different bits.

The shift operations shift all bits over the number specified. 

```c
x << 2; //shifts the values of x two positions, this is the same as multiplying by 4.
```

The unary operator yields the one's complement of an integer (converts each 1 bit to a 0 and vice-versa).

As an example consider the function `getbits(x,p,n)` which return the (right adjusted) n-bit field of x tht begins at position p.
For example: `getbits(x,4,3)` returns the three bits in bit positions 4, 3, and 2 right adjusted.

```c
/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p + 1 - n) & -(-0 << n));
}
```

The expression `x >> (p + 1 - n)` moves the desired field to the end of the word. `-0` is a number containing all ones.
`-0<<n` places zeros in the rightmost `n` bits; complementing that with `-` makes a mask with ones in the rightmost `n` bits.

1. <b>Exercise 2.6: </b> Write a function `setbits(x,p,n,y)` that returns x with the n bits that begin at position p set to the rightmost n bits of y, leavin the other bits unchanged. 
2. <b>Exercise 2.7: </b> Write a function `invert(x,p,n)` that returns x with the n bits that begin at position p inverted.
3. <b>Exercise 2.8: </b> Write a function `rightrot(x,n)` that returns the value of the interger x rotated to the right by n bit positions.

### 2.10 Assignment Operators and Expressions

Just as a note we can compression some calculations:

```c
i = i + 2;
i += 2; // this is the same as above.
```

The `+=` is called an <b>assignment operator</b>.

This is not unique to `+` we could do this with any operation.

1. <b>Exercise 2.9: </b> In a two's complement number system. `x &= (x - 1)` deletes the rightmosst 1-bit in `x`. Explain why. Use this observation to write a faster version of bitcount.

### 2.11 Conditional Expressions

The statements:

```c
if(a > b)
  z = a;
else 
  z = b;
```

compute in `z` the maximum of `a` and `b`. 

The <b>conditional expression</b>, written with the ternary operator "?", provides an alternate way to write this and similar constructions.

```
expr1 ? expr2 : expr3
```

Thus we could set `z` to the maximum of `a` and `b` with:

```c
z = (a > b) > a : b; /* z = max(a, b) */
```

1. <b>Exercise 2.10: </b> Rewrite the function `lower`, which converts upper case letters to lower case, with a conditional expression instead of `if-else`.

### 2.12 Precendence and Order of Evaluation

Here is a table of precendence:

| Operations | Associativity |
| ---------- | ------------- |
| () [] -> . | left to right |
| ! ~ ++ -- + - * & (type) sizeof | right to left |
| * / % | left to right |
| + - | left to right |
| << >> | left to right |
| < <= > >= | left to right |
| == != | left to right |
| & | left to right |
| ^ | left to right |
| \| | left to right |
| && | left to right |
| \|\| | left to right |
| ?: | left to right |
| = += -= *= /= %= &= ^= != <<= >>= | right to left |
| , | left to right |

## Chapter 3. Control flow

Control flow statments control the order in which statements are executed.

### 3.1 Statements and Blocks

In C semicolons `;` are expressions followed by a semi-colon become statements.

Braces `{ }` are used to group declarations and statements together into a <b>compound statements</b> or <b>block</b>.

### 3.2 If-Else

The `if-else` statement is used to express decisions:

```c
if(expression)
  statment;
else
  other_statement;
```

The fact that an else will pair the closest if with there are no brackets, can lead to some tricky situations.

### 3.3 Else-If

For more complicated decision making we have the `else if`:

```c
if(expression)
  statement;
else if(expression)
  statement;
else if(expression)
  statment;
else
  statement;
```

To show off the power of `else-if` here is a copy of binary search:

```c
/* binarysearch: find x in v[0] <= v[1] .... <= v[n-1] */
int binarysearch(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  while(low <= high) {
    mid = (low + high) / 2;
    if(x < v[mid])
      hight = mid - 1;
    else if(x > v[mid])
      low = mid + 1;
    else 
      return mid;
  }
  return - 1; /* no match */
}
```
1. <b>Exercise 3.1: </b> Our binary search makes two tests inside the loop, when one would suffice. Write a version with only one test inside the loop for more tests outside the loop and compare the run time of them. 

### 3.4 Switch 

We can compress an `else if` statment into a `switch` tree.

Here is a template for `switch`:

```c
swtich(expression) {
  case: const-exp: statements;
  case: const-exp: statements;
  default: statement;
}
```

The default is optional and defines what should happen if non of the options are discovered.

Here is the digit count program from earlier using `switch`:

```c
#include <stdio.h>

int main()
{
  int c, i, nwhite, nother, ndigit[10];
  nwhite = nother = 0;
  while((c = getchar()) != EOF) {
    swtich(c) {
      case: '0': case '1': case '2': case '3':
      case '4': case '5': case '6': case '7': case '8':
      case '9':
        ndigit[c - '0']++;
        break;
      case ' ':
      case '\n':
      case '\t':
        nwhite++;
        break;
      defualt:
        nother++;
        break;
    }
  }
  /* same print statements */
  return 0;
}
```

The `break` statement causes an immediate exit from the switch, to prevent other cases from running.
* `break` can also be used to escape a while or for loop.

1. <b>Exercise 3.2: </b> Write a function `escape(s,t)` that converts characters like newline and tab into visible escpae sequences like `\n` and `\t` as it copies the string from s to t.

### 3.5 Loops - While and For

We have already encountered the `while` and `for` loop.

So I'm just going to add some additional notes:

```c
/* This creates an infinite for-loop */
for(;;) {}
```

1. <b>Exercise 3.3: </b> Write a function `expand(s1,s2)` that expands shorthand notation like a-z into the equivalent complete list abc...xyz.
* Allow for upper case, lower case, and digits.

### 3.6 Loops - Do While

As we have seen `for` and `while` terminate at the top. If we want to reverse this we can use a `do while`:

```c
do 
  statment
while(expression);
```

`do while` is used much less than `for` and `while` but can be very valuable when needed.

```c
/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
  int i, sign;
  if((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while((n /= 10) > 0);
  if(sign < 0)
    s[s++] = '-';
  s[i] = '\0';
  reverse(s);
}
```

1. <b>Exercise 3.4: </b> In a two's complement number representation, our version of `itoa` doesn't handle the largest negative number. Why not? Fix this.
2. <b>Exercise 3.5: </b> Write a function `itob(n,s,b)` that converts the integer `n` to a base `b` character representation in the string `s`.
3. <b>Exercise 3.6: </b> Write a version of `itoa` that accepts arguments instead of two. The 3rd is the minimum field width; the converted number must be padded with blanks on the left if necessary to make wide enough.

### 3.7 Break and Continue 

`break` exits a loop early while `continue` just advances one interation.


### 3.8 Goto and Labels

The `goto` statment allows code to break from many loops or advance to other parts of code as marked by a label.

I am not going to put anything here because the book hardly talks about them and other books say they should never be used!

## Chapter 4. Functions and Program structures

Functions break large computing tasks into smaller ones, and enable people to build on what other have done already.

C has been designed to make functions efficient and easy to use; C programs generally consist of many small functions rather than a few big ones.

A program may reside in one or more source files. Source files may be compiled separately or loaded togther.

### 4.1 Basic Functions

To begin with le us design and write a program to print each line of its input that contains a particular "pattern" or string of characters.
* This is a special case of the UNIX program grep.

[grep.c](./Chapter-4/grep.c)

Note: If you want to compile multiple files together then do something like:
* `cc main.c getline.c strindex.c`

1. <b>Exercise 4.1: </b> Write the function `strindex(s, t)`, which returns the position of the rightmost occurence of t in s, or -1 if there is none.

### 4.2 Functions Returning Non-Integers

So far we have only seen functions that return `int` or no value (`void`).

Many numerical functions return precision point values like `sqrt`, `sin`, and `cos` return `double`.

To illustrate this we write a function `atof(s)` which returns the double-precision floating-point equivalent.

[atof.c](./Chapter-4/atof.c)

1. <b>Exercise 4.2: </b> Extend `atof` to handle scientific notation of the form `123.45e-6`
 * Where the floating-point number may be followed by `e` or `E` and an optionally signed exponent.
