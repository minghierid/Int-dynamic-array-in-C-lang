# About
With this C library you will able to manage dynamic int arrays easily, using an interface similar to java Vector class.

# Usage
First of all you have to include the header file <code>intVector.h</code>, after doing that is necessary to call in the main() function the <code>ERROR_STATEMENT;</code> preprocessor symbol, this will help you to catch all errors when using the library.
There are also other preprocessor sybols and macros to manage errors that you have to use:
- <code>ERROR_OCCURED</code> return true if an error occured in the previous function call
- <code>NOT_ERROR_OCCURED</code> return true if not error occured in the previous function call
- <code>IF_ERROR_QUIT(err_code, array)</code> requires a number (the error code) and the array, if an error occured this macro will exit the program
