# <a href="https://clang.llvm.org/">CLang</a> Cheatsheet <img width="50em" src="https://www.incredibuild.com/wp-content/uploads/2021/03/Clang01.png">

<table>
<td>

- [File](#file)
- [Hello world](#hello-world)
- [Include headers](#include-headers)
- [Variables](#variables)

</td>
<td>

- [y](#y)
- [y](#y)

</td>
</table>


## File

### compile file using (gcc)
```bash
gcc ./file.c
./a.exe

# custom name of exe file
gcc ./file.c -o custom_name.exe
```


## Hello world
```c
#include <stdio.h>

int main() {
    printf("Hello, world!");

    return 0;
}
```


## Include headers
```c
// method 1
#include <header.h>

// method 2
#include "header.h"
```


## Variables
```c
// declare
<type> <name> = <value>;
int example = 5;

// declare array
<type> <name>[<size>] = {};
int example[2] = {5, 10};

// string
char <name>[] = <value>;
char example[] = "Hello!";

/*
Types:
    unsigned int, short, long = %u = positive number
    signed int, short, long   = %d = negative numbers

    bool  = %d  = true/false (need stdbool header)
    char  = %c  = one character (in single quote)
    int   = %d  = numbers
    short = %hd = numbers (-32_768 to 32_767)
    long  = %ld = numbers (-9223372036854775808 to 9223372036854775807)

    float       = %f  = floating numbers (6 decimals)
    double      = %lf = floating numbers (15 decimals)
    long double = %Lf = floating numbers (19 decimals)

    void = N/A = only for function return as empty
*/
```

### structs
```c
// create struct
struct <struct-name> {
    <type> <key-name>;
};


// initialize empty struct variable
struct <struct-name> <variable-name>;


struct <struct-name> {
    <type> <key-name>;
} <variable-name>;


// initialize filled struct variable
struct <struct-name> <variable-name> = {<value>, <value>};




// create struct
struct example {
    int foo;
};


// initialize empty struct variable
struct example example_var;
example_var.x = 5;


struct example {
    int foo;
} example_var;


// initialize filled struct variable
struct example example_var = {5};
```



# <a href="https://clang.llvm.org/">CLang Headers</a> Cheatsheet <img width="50em" src="https://www.incredibuild.com/wp-content/uploads/2021/03/Clang01.png">
