# Notes

## Classes

### Access modifiers

**Public**: Accessible outside the class.
**Protected**: Accessible inside the class and sub-classes.
**Private**: Not accessible outside the class.
**Friend**: Lets a class or function access the private and protected methods.

### Constructors

Class constructors can specify the call to the parent class constructor. If not specified, the default constructor of the parent class is called just before the class constructor.
**endl** creates a new line after an output.

### Overload

*operator+* specifies that we're referring to the addition operator.
Multiple definitions with different types act as overload.

## Keywords

![keywords](/res/keywords.png){:class="img-responsive" width="400px"}

## Input/Output

**cout**: standard output
**cin**: standard input
**cerr**: standard error

## Data Types

Files *limit* and *float* contain headers that define the limits on representable values for native data types.

Expression convertions:
* Any bool char, short or enum is promoted to int.
* int < unsigned < long < unsigned long
      < float < double < long double

Promotion convertions can generally behave well, while demotions usually involve data loss.
*static_cast<type>(variable)* is available for a conversion that is well defined, portable and invertible.
*reinterpret_cast* Are generally unsafe and should be avoided. They are system dependent.
*dynamic_cast* Requires understanding inheritance.
*const_cast* Serves to "cast away constness".

The comma expression as a whole has the value and type from its right operand. Its associates from left to right.

## Function Prototypes

The ellipsis symbol can be used for an unspecified argument list. i.e. printf(const *char cntrl_str, ...).
C++ is able to provide default arguments to functions. i.e. sum(a, b = 3).
Only trailing parameters can have default values.

## Storage Classes

The four storage classes are:
* auto: Handles storage according to blocks.
* extern: The compiler searches for the definition in another file.
* register: The associated variables should be stored in high-speed memory registers, if possible.
* static: Preserves values inside functions. Restricts visibility to file.
In C++ the system sets to 0 external and static variables that are not initialized. However, automatic variables are not set to 0 and could contain "garbage" values.

## Linkage Mysteries

It is possible to link to other languages, however, this linkage is system dependent. For example, C linkage is possible using:

``` extern "C" { code or include file } ```

To avoid linkage problems:
* Use header files for function prototypes, class definitions, constans, typedefs, templates, inline functions, and named namespaces.
* Use headers with an # ifdef __filename as a guard against multiple inclusion.
* Think in terms of the one-definition rule which states that clases, enums, templates, etc. must be defined exactly once in the program.
* As a heuristic, envision "writing" the code into one monolithic file and "seeing" whether this causes conflicts.

## Namespaces

Anonymous namespaces can replace static global variables. For example:
``` namespace { int count = 0; } // Count is available to the rest of the file ```
Library headers conforming to ANSI C++ will no longer be using the .h suffix.

## Pointers

``` 
p = &i;     // the address of object i
p = 0;      // a special sentinel value
p = static_cast<int*>(1507);  // absolute address

```

## Reference Declarations and Call by Reference

```
int         n;
int&        nn = n;       // nn is alternative name for n
double      a[10];
double&     last = a[9];  // last is an alias for a[9];
```

## Tips

Input can be redirected from a file to another like this *gcd < gcd.dat*.
Output can be redirected like this *gcd > gcd.ans*.
A cast to void can informt the compiler that the expression's computed value is to be discarded.