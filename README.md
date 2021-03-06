# About
With this C library you will able to manage dynamic int arrays easily, using an interface similar to java Vector class.

# Usage
First of all you have to include the header file <code>intVector.h</code>, after doing that is necessary to insert as the first line of the <code>main()</code> function the <code>ERROR_STATEMENT;</code> preprocessor symbol, this will help you to catch all errors when using the library.
There are also other preprocessor symbols and macros to manage errors that you probably need:
- <code>ERROR_OCCURED</code> return true if an error occured in the previous function call
- <code>NOT_ERROR_OCCURED</code> return true if not error occured in the previous function call
- <code>ERROR</code> is the error flag, you have to pass this to the functions that requires it
- <code>IF_ERROR_QUIT(err_code, array)</code> requires a number (the error code) and the array, if an error occured this macro will exit the program with the given error code and will print a message to notify the exiting to the user

This library introduce a new data type, the <code>IntVector</code> type.<br>
To create a dynamic vector you need to declare an <code>IntVector</code> variabile and assign to it the return value of the <code>create(int value, int *error);</code> function.<br>
When you want to free your array (so when you don't use it more, and in any case before the <code>return 0;</code>) you have to use the <code>freeAll(IntVector vector, int *error);</code> function, this will destroy the array.
<br>
Here a list of all the functions available:
- <code>IntVector create(int value, int *error);</code>
- <code>void freeAll(IntVector vector, int *error);</code>
- <code>int getLength(IntVector vector, int *error);</code>
- <code>int getLastIndex(IntVector vector, int *error);</code>
- <code>IntVector addElementAt(IntVector vector, int index, int value, int *error);</code>
- <code>IntVector removeElementAt(IntVector vector, int index, int *error);</code>
- <code>IntVector removeLastElement(IntVector vector, int *error);</code>
- <code>IntVector addLastElement(IntVector vector, int value, int *error);</code>
- <code>int getValueUsingIndex(IntVector vector, int index, int *error);</code>
- <code>void setValueUsingIndex(IntVector vector, int index, int value, int *error);</code>
- <code>void quickSort(IntVector vector, int first, int last, int *error);</code>
- <code>void printVector(IntVector vector);</code>
 
<br><b>N.B.</b><br>
I suggest to handle any errors after you call one of these functions by using <code>IF_ERROR_QUIT(err_code, array)</code> or by creating your own error handle procedure using this <code>if (ERROR_OCCURED) { //do something }</code> as template.

<b> <h2>How to use functions ?</h2><b>
- <code>IntVector create(int value, int *error);</code>
  <br>
  Create the array with only the first element, require the value for the first element (an integer number) and the error flag: <code>ERROR</code>.
  This function generate an error if is impossible to allocate memory for the array.
- <code>void freeAll(IntVector vector, int *error);</code>
  <br>
  Free all the memory used to store the array, in other words it destroy the array. Require the array name and the error flag: <code>ERROR</code>.
  This function generate an error if is impossible to free the memory cause the array name passed to the function is <code>NULL</code>
- <code>int getLength(IntVector vector, int *error);</code>
- <code>int getLastIndex(IntVector vector, int *error);</code>
- <code>IntVector addElementAt(IntVector vector, int index, int value, int *error);</code>
- <code>IntVector removeElementAt(IntVector vector, int index, int *error);</code>
- <code>IntVector removeLastElement(IntVector vector, int *error);</code>
- <code>IntVector addLastElement(IntVector vector, int value, int *error);</code>
- <code>int getValueUsingIndex(IntVector vector, int index, int *error);</code>
- <code>void setValueUsingIndex(IntVector vector, int index, int value, int *error);</code>
- <code>void quickSort(IntVector vector, int first, int last, int *error);</code>
- <code>void printVector(IntVector vector);</code>
