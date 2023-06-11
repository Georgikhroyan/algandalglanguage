# algandalglanguage
TASK 1 AND TASK 2 для алгоримтов и алгоритмических языков
1.1
1. Выяснить, сколько байт отведено для хранения данных типа short, int, long,
float, double и long double.

1.9
Выяснить способ представления типа char: signed- или unsigned- вариант. 

• Task 2.1
The input from stdin will provide a positive value ε. Then, you need to enter a specific value for x. For the given x, you should compute and output the square root √x to stdout. To calculate the square root, use the iterative formula (Heron's method):
x0 = 1, xi+1 = 1/2 * (xi + x/xi), i = 0, 1, 2, ...
The calculation should continue until the absolute difference |xi − xi+1| ≥ ε. The resulting value of xi+1 should be output. Use the printf() function with the format specifier %.10g for printing the double precision floating-point value. Avoid using unnecessary library functions or features.

• Task 2.2.1
The input from stdin will provide the values of x, an, an−1, ..., a0, as space-separated floating-point numbers. You should output the interpolated value of the polynomial a0 + a1x + a2x^2 + ... + an*x^n at the given value of x. The coefficients a0, ..., an are given in ascending order (a0 is the constant term, an is the coefficient for x^n). Do not use arrays or loops for this task.

• Task 2.2.2
Write a program based on task 2.2.1. Given the interpolated value, output the derivative at the specified value of x.

• Task 2.2.3
Write a program based on task 2.2.2. Given the interpolated value and its derivative, output the integral from 0 to x. For this, provide the following inputs:
n, x, an, an−1, ..., a0
(In the input line, the integer value n will be followed by n+1 floating-point numbers.)



• task2.3

Write a recursive and iterative function for calculating the i-th number of the Fibonacci sequence, defined as follows:
F0 = 0, F1 = 1, Fi = Fi−2 + Fi−1, i = 0, 1, 2, 3,...

Implement a program that reads an input from stdin and calculates the corresponding Fibonacci number. If the input is a negative number, output the Fibonacci number as a negative value. If the input is zero, output the Fibonacci number as zero. Print the result to stdout.

• task2.4

Implement the function "str2double" that converts a string to a double value. The string should be converted according to the syntax of the C language (e.g., scientific notation, hexadecimal notation). The result should be returned as a double value, using the "double" data type. Do not use any built-in conversion functions.

Write a program that reads a string from stdin containing a valid double value, calls the function "str2double()" on the string, and prints the resulting double value to stdout using the format "%.10g". The input string can contain leading and trailing whitespace characters.

• task2.5

Implement the function "count_words" for the C language. The function should count the number of words, separated by whitespace characters and punctuation marks. The function should return a dynamically allocated array of strings. Each string should contain one word. The last element of the array should be a NULL pointer. The function should handle memory allocation errors.

Write a program that reads a text from stdin, consisting of non-empty words, separated by whitespace characters, punctuation marks, and newline characters. Process the text using the "count_words()" function, and output the count of words, followed by each word on a separate line.

• task2.6

Implement the function "search_element" for the C language. The function should perform a binary search on an ordered array of integers. The function should return the index of the element if found, or -1 if the element is not present. The array should be searched recursively.

Write a program that reads integer elements from stdin (ordered in ascending order), followed by the element to search for. If the element is found, output its index. Otherwise, output -1.

• task2.7

Here is the corrected and translated version of the task:

Write a program that calculates expressions consisting of digits '0'-'9', arithmetic operations, parentheses, and spaces. The calculations should follow the usual order of operations. The program should handle integer arithmetic and output the result.

The grammar for the expressions is defined as follows:
<expression> ::= <term> {+ <term>}
<term> ::= <factor> {* <factor>}
<factor> ::= 0|1|2|3|4|5|6|7|8|9| (<expression>)

Implement a recursive descent parser that reads expressions from standard input and outputs the evaluated result to standard output. The input expression will be a valid arithmetic expression without any syntax errors. If the expression evaluates to an integer, output the result as an integer. If the expression results in a floating-point number, output it as a floating-point number with 10 decimal places.

Хроян Георгий .
