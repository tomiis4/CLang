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

### Structs
```c
// create struct
struct <struct-name> {
    <type> <key-name>;
    <type> <key-name>;
}

// initialize empty struct variable
struct <struct-name> <variable-name>;

// initialize filled struct variable
struct <struct-name> <variable-name> = {<value>, <value>};
```


## Functions
```c
<type> name() {
	//...
}

// return
<type> name() { return x }

// parameters 
<type> name(<type> param1) {  }
```


## Logic Statements

### If/else
```c
if (condition) {
    //...
} else if (condition2) {
    //...
} else {
    //...
}
```

### Switch/case
```c
switch (statement) {
    case x:
        //...
        break;
    case y:
        //...
        break;
    default:
        //...
}
```


## Loop

### For-I
```c
for (int i=0; i < 10; i++) {
    //...
}
```

### While
```c
while (condition) {
    //...
}
```


## Converting
```c
// str -> int
#include <stdlib.h>

int number = atoi(<string>);

// int -> str
#include <stdlib.h>

char str[20];
sprintf(str, "%d", <number>);

// int -> float
float decimal = (float) <number>;

// flaot -> int
int number = (int) <float>;
```


## Build-In Functions

### printf
```c
// print formatted output

// without variable
printf("Hello, world");

// with variable
printf("Hello, <format-type>", <variable>);
```

### scanf
```c
// get user input

scanf(<format-type>, &<variable>);
```

### memory
```c
// todo
```

#TODO
## Pointers
```c
// create new pointer variable with name pointer
<type> *pointer;

// change pointer address
pointer = <address>;

// change data from address/pointer
*pointer = <value>

// read data from address/pointer
*pointer

// get address from variable
&variable
```

## Libraries 

### time.h
```c
// get start time
clock_t startTime = clock();


// create delay
void delay(int ms) {
    clock_t startTime = clock();

    while (clock() < startTime + msDelay);;
}
```


## Projects
- Calculator
- Sorting algorithm
- Snake
