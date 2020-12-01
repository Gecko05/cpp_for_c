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