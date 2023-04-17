# <a href="#">C</a> Cheatsheet <img width="50em" src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/C_Programming_Language.svg/1200px-C_Programming_Language.svg.png">

<table>


<td>

* [File](#file)
* [Hello world](#hello-world)

</td>



</table>


## File

### Run file
```sh
gcc <file-name>.c -o <exe-filename>.exe

./<exe-filename>.exe
```


## Hello world
```c
#include <stdio.h>

int main() {
    printf("Hello, world\n");

    return 0;
}
```

## Importing packages
```c
#include <package.h>
```


## Variables
```c
// declare variable
<type> <name> = <value>;

// declare array
<type> <name>[] = {<value>, <value>};

// string
char <name>[] = "<content>";
char <name>[<str-length>] = "<content>";

/*
Types:
    unsigned int, short, long = %u = positive number
    signed int, short, long   = %d = negative numbers

    bool  = %d  = true/false
    char  = %c  = one character (in single quiote)
    int   = %d  = numbers
    short = %hd = numbers (-32_768 to 32_767)
    long  = %ld = numbers (-9223372036854775808 to 9223372036854775807)

    float       = %f  = floating numbers (6 decimals)
    double      = %lf = floating numbers (15 decimals)
    long double = %Lf = floating numbers (19 decimals)

    void = N/A = only for function return as empty
*/
```

### Struct




<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br>
<br><br><br>

# OLD ONE




# C Cheatsheet

<table>
<td>

* [Imports](#import)
* [Variables](#variables)
* [Input/Output](#inputoutput)
* [Loops](#loops)


</td>
<td>

* [Function & Return](#functionreturn)
* [Extern file](#externfile)
* [Logic](#logic)
* [Projects](#projects)
* [Time](#time)
	* [Delay](#delay)

</td>
</table>

## Import
### Input/Output lib
```C
#include <stdio.h>
```
### String lib
```C
#include <string.h>
```
### Time lib
```C
#include <time.h>
```

## Variables
### Types
```C
int x = 5; // %d
float x = 3.14; // %f
double x = 5.5555f; // %lf
char x = 'A'; // %c
char x[] = "Hello"; // %s

int x[5] = {1, 2, 3, 4, 5}; 
```
## Input/Output
### Output
```C
#include <stdio.h>

// Basic
printf("Hello, world");

// Variable
printf("Hello, %s", variable);
```
### Input
```C
#include <stdio.h>

int variable;
scanf("%d", &variable);
```

## Loops
### For loop
```C
for (int i=0; i<5; i++) {}
```
### While loop
```C
// First way
while (1) {}

// Second way
for (;;) {}
```

## Function/Return
### Function
```C
// Basic
void name() {}

// Main
int main() { return 0; }
```
### Return
```C
int name() { return 5+5; }
```

## Extern file
### Import file
```C
// main.C
#include "second.h"

// second.h
extern int name() { return 5+5; }
```

## Logic
### If/Else If/ Else
```C
if (x) {} else if (y) {} else {}
```
### Switch/Case
```C
switch (x) { case "y": break; }
```

## Time
### Delay
```C
#include <time.h>

void delay(int msDelay) {
	clock_t startTime = clock();
	while (clock() < startTime + msDelay);
}
```

## Others
### Size of array
```C
int array = {1, 2, 3, 4, 5};

int size = sizeof array / sizeof array[0];
```
### Random number
```C
#include <stdlib.h>
#include <time.h>

// 0-5
int randomInt = (rand() % 5) + 1;
srand(time(0));
```



## Projects
 - Calculator
 - Sorting algorithm
 - Snake
