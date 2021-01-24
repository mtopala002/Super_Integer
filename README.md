# Super_Integer

This library provides a solution for the limited space for storing integers in C++.
The library uses string to represent integers. Here is the a list of the functions included:

1) string absol(string a): this one returns the absolute value of a 
2) bool isbigger(string a, string b): returns true if a is bigger than b, and false otherwise.
3) bool isequal(string a, string b): returns true if a = b, and false otherwise
4) string add(string a, string b): returns the sum of a and b
5) string product(string a, string b): returns the product of a and b
6) string subtract(string a, string b): returns a - b 
7) string divide(string b, string a): return the integral part of b/a.
8) string mod(string a, string b): return b modulo a
9) string power(string a, string e): return a to the power of e

Note that the library does not support negative integers except with "absol" function. I will try to add this feature as soon as possible.
