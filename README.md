# FloatToIEEE754
Hexadecimal and binary ieee754 single-precision formating.
## Usage
    $ make
    $ ./ieee754 3.14159
    3.14159.................................(base 10 argument)
    3.14159.................................(base 10 internal float)
    40490fd0................................(ieee754 hexadecimal)
    0:10000000:10010010000111111010000......(ieee754 sign:exponent:mantissa)
