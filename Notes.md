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
When overloading non-symmetric binary operations, it's usually best practice to write an additional overloaded member function. This is because order matters in asymmetric binary operations. 
i.e.

```
clock operator*(unsigned long m, clock c)
{
      return (m * c.tot_secs);
}

clock operator*(clock c, unsigned long m)
{
      return (m * c);
}
```

As a rule of thumb, any time a class needs an explicit copy constructor defined, it also needs an assignment operator defined. This is usually the case when the object allocates its own memory.
Overloading both the assignment and plus operators doesn't imply that operator+= is overloaded.
Operators for which there is no normal expectation should not be overloaded.

new() ad delete() member funcntions are always implicitly static. The new() is invoked before the object exists and therefore cannot have a *this* yet.
The delete() is called by the destructor, so the objec is already destroyed.

```
// Normal form for heap-managed classes

class dbl_vect {
public:
      dbl_vect();       //default constructor
      dbl_vect(const dbl_vect&);    // copy constructor
      ....
      // This allows assignment to work efficiently. Requires lvalue semantics.
      dbl_vect& operator=(const dbl_vect&); //returns lvalue
      ....
};
```

## Keywords

![keywords](/res/keywords.png){:class="img-responsive" width="400px"}

* Explicit: This keyword doesn't allow the compiler to use a class constructor for implicit conversions in parameters. This way we can avoid accidental hidden bugs with constructors.

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

## Signature Matching

For a given argument, a best match is alwazs an exact match. An exact match also includes trivial conversions.

| **From** | **To** |
| --- | --- |
| T* | const T* |
| T* | volatile T* |

These modifiers can be used in overloading resolution.

## Storage Classes

The four storage classes are:
* auto: Handles storage according to blocks.
* extern: The compiler searches for the definition in another file.
* register: The associated variables should be stored in high-speed memory registers, if possible.
* static: Preserves values inside functions. Restricts visibility to file.
In C++ the system sets to 0 external and static variables that are not initialized. However, automatic variables are not set to 0 and could contain "garbage" values.
* volatile: Means that a variable can be modified external to the program code. Also suppresses compiler optimizations on it.

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
Overlaying bitfields and unions can be useful.
Favor direct list initialization whenever possible. List initialization will make the compiler complain when you try to initialize a data member with a value that cannot be held.
*Deep Copy* means copying the memory content from one address to another. *Shallow Copy* means copying addresses.
Check with *assert* after *new*.
A reference returned from a function can be used as left operand for assignment.

## Classes, Unions and Structs

*Struct* ad *Class* can be used interchangeably. By default structs have public privacy specifications, while classes have private.
It is recommended to use struct over class when it only has public data members.
The *static* identifier makes class data member part of the class, but separate from any class object.
A static member of a global class must be explicitly declared and defined in file scope. The preferred stle for accessing static members is to use scope resolution, otherwise it could be misleading.
When calling a member function, the function gets and implicit argument list (class data members). When the function is static, it doesn't get this implicit argument list.
When the member function has *const* it is not able to modify the implicit arguments and the compiler checks that the object doesn't have its objects modified. Also ROM optimizations can also be done when using const.
The compiler provides a copy constructor whose signature is: 
``` class_name::class_name(const class_name&); ```
It is appropiate that the class provides its own copy constructor, otherwise data members who are pointers could cause issues.
Default constructors are used to initialized arrays of a derived type.
Unions can't have static members, nor members with constructors or destructors. Global anonymous unions must be declared static.

```typedef struct { ... } Foo;```
Declares an anonymous structure and creates a typedef for it. 

## Class Scope

* ::i - This unary operator refers to external scope
* foo_bar::i - This binary operator refers to class scope

## ADT Conversions

The de facto type conversion constructor is as follows:

```point::point(double u);```

A conversion to an already defined type can be implemented by defining a special conversion function inside the user defined class.

```operator type() { .... }```

### Overloaded Function Selection Algorithm

1. Use an exact match if found.
2. Try standard type promotions.
3. Try standard type conversions.
4. Try user-defined conversions.
5. Use a match to ellipsis if found.

1. Exact match with trivial conversions on nontemplate functions
2. Exact match using funcion templates
3. Ordinary argument resolution on nontemplate functions

## Templates

The identifier for a template argument is as follows:

```template <class identifier>```

When a template class is used, the code must always use the angle brackets as part of the declaration.

Member functions, when declared and defined inside the class, are, as usual, inline. When defining them externally, the full angle bracket declaration must be used.

```TYPE top_of() const 
{
      return s[top];
}```

would be written as:

```template<class TYPE> TYPE stack<TYPE>::top_of() const
{
      return s[top];
}```

Destructor definition:

```template<class TYPE> stack<TYPE>::~stack()
{ delete []s; }```

Template classes can contain friends. A friend function that does not use a template specification is universally a friend of all instantiations of the template class. A friend function that does, is specifically a friend of its instantiated class.

```friend vect<T> product(vect<T> v); // instantiated ```

Static members are nont universal, but are specific to each instantiation.

```
template <class T>
class foo {
      public:
      static int count;
};

foo<int> a;
foo<double> b;
```
Classes and functions can have several class template arguments. It's also possible to provide a default class instantiation.
```template<class T = doble>```

Members may themselves be templates inside th etemplate class.
```
template <class T1>
class foo{
      public:
      template <class T2>
      class fooprime {
      .....
      // can use T1 and T2 in fooprime
      };
      // can only use T1 in foo
      .......
};

foo<int>::fooprime<char> a;
```
There can also be function member templates if supported by compiler.

## STL

The standard template library is the C++ library providing generic programming for manny standard data structures and algorithms. The STL provides three components: containers, iterators and algorithms.

### STL Typical Container Interfaces

* Constructors, including default and copy constructors
* Element access
* Element insertion
* Element deletion
* Destructor
* Iterators

Containers are traversed using iterators, pointer-like objects that are available as templates and optimized for use with STL containers.

Containers come in two major families: sequence and associative. Associative containenrs have keys for looking up elements. Sequence containers are ordered by having a sequence of elements.

The associative containers have key-based accessible elements and an ordering relation **Compare**, which is the comparison object for the associative container.

### Container Adapters

Containenr adapter classes modify existing containers to produce various public behaviors based on an existing implementation. Three provided container adapters are **stack**, **queue**, and **priority_queue**.

### Iterators

Navigation over containers is by iterator. There are five iterator types: input, output, forward, bidirectional, and random access. Not all iterator types may be available for a given container class.
Input iterators support equality operations, dereferencing, and autoincrement.
Output iterators support dereferencing restricted to the left-hand side of assignment and autoincrement.
Forward iterators support all input/output iterator operations, as well as unrestricted use of assignment.
Bidirectional iterators support all forward iterator operations, as well as both autoincrement and autodecrement.
Random-access iterators support all bidirectional iterator operations, as well as address arithmetic operations, such as indexing. They also support comparison operations.

### Algorithms

The STL algorithms library contains the following four categories:
* Sorting algorithms
* Nonmutating sequence algorithms
* Mutating sequence algorithms
* Numerical algorithms

### Inheritance

A class can be derived from an existing class by using the form

```
class class-name: (public|protected|private) base-name{
      member declarations
};
```

A reference to the derived-class maybe be implicitly converted to a reference to the public base-class.

```
grad_student gs("Morris Pohl", 200);
student& rs = gs;
```

Only nonstatic member functions can be virtual. Constructos cannot be virtual, but destructors can be. As a rule of thumb, any class having virtual functions should have a virtual destructor.

### Abstract Base Classes

A pure virtual function is one whose body is normally undefined:

``` virtual function_prototype = 0; ```

The pure virtual function is used to defer the implementation decision of the function. In OOP terminology, it is called a deferred method.
A class that has at least one pure virtual function is an abstract class. This class cannot be used to declare objects. Instead, it is used to declare pointers that can access subtype objects derived from the abstract class.
A union may have constructors and destructors but not virtual functions. It can neither serve as abase class nor have a base class. Members of a union cannot require constructors or destructors.