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

2. <b>Exercise 2.2: </b> Experiment to find out what happens if you replace `/n` with a special character that DNE.

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

3. There is special reason for `5 * (fahr - 32) / 9;`
 * integer division tuncates so 5/9 would be 0.

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

See this better version: [farenheit-celsius-table-better.c](./Chapter-1/farenheit-celsius-table-better.c).