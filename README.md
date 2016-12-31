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
