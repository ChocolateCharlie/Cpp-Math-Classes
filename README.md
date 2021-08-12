# Math Classes (C++)

A few classes useful in maths:

  - [x] Basic functions
  - [ ] Complex numbers
  - [x] Rational numbers
  - [x] Time


## Basic functions
Basic is a template class that comprises ```abs```, ```gcd```, ```max``` and ```min``` methods.

_Code example:_
```cpp
#include "Basic.h"
...
Basic<int>::abs(-4);          // Evaluates to (+)4
Basic<float>::max(3.4, 7.8);  // Evaluates to 7.8
```

## Rational numbers
Rational is a class that handles rational numbers. It comprises the output operator ```<<``` ; all of the four mathematical operators (```+```, ```-```, ```\*```, ```/```) between a Rational number and both an integer or another Rational number ; all of the equality and comparison operators (```==```, ```!=```, ```<```, ```<=```, ```>```, ```>=```) between a Rational number and both an integer or another Rational number ; additive inverse (```opposite```) and multiplicative inverse (```reciprocal```) ; conversion to a float (```to_decimal```).

A Rational number has by defaut it's denominator set to 1 ; thus, it is not necessary to specify the denominator in this case.

_Code example:_
```cpp
#include "Rational.h"
...
Rational a(3);      // Creates a Rational number with a numerator set to 3 and a denominator set to 1
Rational b(-4, 3);  // Creates a Rational number with a numerator set to -4 and a denominator set to 3
```

### Exceptions handling
Some methods from the Rational class may throw the standard exception _domain_error_ if the denominator is set to zero (at initialization or as the result of an operation) or when asked to divide by zero.

_Code examples:_
```cpp
#include "Rational.h"
...
// First example: dividing by zero
Rational a(3);
try {
  cout << a / 0 << endl;
}
catch(exception const &e) {
  cout << e.what() << endl; // Prints "Cannot divide by zero" on standard output
}
// Second example: creating a rational number with a denominator set to zero
try {
  Rational b(8, 0);
}
catch(exception const &e) {
  cout << e.what() << endl; // Prints "Denominator cannot be zero" on standard output
}
```
