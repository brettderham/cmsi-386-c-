##### Question 1

A[0][0] --> addressed at 0x1000020D0
A[3][7] --> addressed at 0x100002118

##### Question 2

1. a as an array of pointers
2. b as a pointer to an array (of doubles)
3. c as an array of pointers to functions that gets arguments (returns doubles)
4. d as a function that gets arguments and returns an array


##### Question 3

f as a function pointer that accepts 2 arguments:

f(

 --> gets a function pointer that gets a double and an array of doubles

 --> a double

 )

##### Question 4

the b fields in the subclass can be accessed right away but to get the super class you will need some pointers

##### Question 5

C++ uses static scoping so we end up with

2

5

2

which we get because it reads x globally,

if C++ instead had dynamic scoping we would get

5

5

2

because it would instead look at more recent assigning

##### Question 6

a. shuffle(in array[], int array_length)

b. shuffle(std::array<int, array_length>&, array)
