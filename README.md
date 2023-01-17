# C Cheatsheet

# Add Hello world

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

scanf("%s", &variable);
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
