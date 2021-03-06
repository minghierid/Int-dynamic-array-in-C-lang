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

<b><h2>How to use functions ?</h2><b>
- <code>IntVector create(int value, int *error);</code>
  <br>
  Create the array with only the first element, require the value for the first element (an integer number) and the error flag: <code>ERROR</code>.
  This function generate an error if is impossible to allocate memory for the array.
- <code>void freeAll(IntVector vector, int *error);</code>
  <br>
  Free all the memory used to store the array, in other words it destroy the array. Require the array name and the error flag: <code>ERROR</code>.
  This function generate an error if is impossible to free the memory cause the array name passed to the function is <code>NULL</code>.
- <code>int getLength(IntVector vector, int *error);</code>
  <br>
  This function return the length of the array, require the array name and the error flag: <code>ERROR</code>.
  It generate an error if the array name passed is <code>NULL</code>.
- <code>int getLastIndex(IntVector vector, int *error);</code>
  <br>
  This function return the last index of the array, require the array name and the error flag: <code>ERROR</code>.
  It generate an error if the array name passed is <code>NULL</code>.
- <code>IntVector addElementAt(IntVector vector, int index, int value, int *error);</code>
  <br>
  This function add an element (so an integer number) in the array to the element with the given index, it return the array. Require the array name, the index where you want to   insert the new element, the value for the new element and the error flag: <code>ERROR</code>. It generate an error if passed index is not valid, so if it's less than 0 or       greter than the array length (if I give an index equals to array length the new element will be added at the end of the array).
- <code>IntVector removeElementAt(IntVector vector, int index, int *error);</code>
  <br>
  This function remove the element with the given index from the array. it return the array. Require the array name, the index of the element you want to remove and the error  flag: <code>ERROR</code>. It generate an error if passed index is not valid, so if it's less than 0, greter or equals than the array length or if the array has only one  element  (you can't remove an element if the array has only one, there must be at least one element).
- <code>IntVector removeLastElement(IntVector vector, int *error);</code>
   <br>
   Works like <code>IntVector removeElementAt(IntVector vector, int index, int *error);</code> but it remove only the last element.
- <code>IntVector addLastElement(IntVector vector, int value, int *error);</code>
  <br>
  Works like <code>IntVector addElementAt(IntVector vector, int index, int value, int *error);</code> but add an element at the end of the array .
- <code>int getValueUsingIndex(IntVector vector, int index, int *error);</code>
  <br>
  Return the value of the element at the given index. Require the array name, the index and the error flag: <code>ERROR</code>.
  It generate an error if the passed index is not valid, so if is less than 0, greater or equals to the array length.
- <code>void setValueUsingIndex(IntVector vector, int index, int value, int *error);</code>
  <br>
  Change the value of an array element. Require the array name, the index, the new value and the error flag: <code>ERROR</code>.
  It generate an error if the passed index is not valid, so if is less than 0, greater or equals to the array length.
- <code>void quickSort(IntVector vector, int first, int last, int *error);</code>
  <br>
  Sorts the array in ascending order, require the array name, the index of the firs element, the index of the last element and the error flag: <code>ERROR</code>.
  It generate an error if the passed indexes are not valid, so if are less than 0, greater or equals to the array length.
- <code>void printVector(IntVector vector);</code>
  <br>
  Print the array, require the array name.
  <br><br>
# Example.c
```
 #include "intVector.h"

int main(int argc, char const *argv[])
{
  ERROR_STATEMENT;

  IntVector myArray = create(10, ERROR);
  IF_ERROR_QUIT(-1, myArray);
  
  myArray = addLastElement(myArray, 1050, ERROR);
  IF_ERROR_QUIT(-1, myArray);
  myArray = addLastElement(myArray, 50, ERROR);
  IF_ERROR_QUIT(-1, myArray);
  myArray = addLastElement(myArray, 30, ERROR);
  IF_ERROR_QUIT(-1, myArray);
  myArray = addElementAt(myArray, 2, 125, ERROR);
  IF_ERROR_QUIT(-1, myArray);
  myArray = removeElementAt(myArray, 3, ERROR);
  IF_ERROR_QUIT(-1, myArray);
  myArray = removeLastElement(myArray, ERROR);
  myArray = addLastElement(myArray, 3580, ERROR);
  IF_ERROR_QUIT(-1, myArray);
  myArray = addLastElement(myArray, 9601, ERROR);
  IF_ERROR_QUIT(-1, myArray);
  myArray = addLastElement(myArray, 7530, ERROR);
  IF_ERROR_QUIT(-1, myArray);
    
  printf("\nThe value of the element with index 3 is: %d\n", getValueUsingIndex(myArray, 3, ERROR));
  IF_ERROR_QUIT(-1, myArray);

  int newVal = 189;
  setValueUsingIndex(myArray, 4, newVal, ERROR);
  IF_ERROR_QUIT(-1, myArray);

  quickSort(myArray, 0, getLastIndex(myArray, ERROR), ERROR);
  IF_ERROR_QUIT(-1, myArray);
    
  printVector(myArray);
  printf("\nArray length: %d - last element index: %d\n", getLength(myArray, ERROR), getLastIndex(myArray, ERROR));
  IF_ERROR_QUIT(-1, myArray);

  freeAll(myArray, ERROR);
  IF_ERROR_QUIT(-1, myArray);
  return 0;
}
```
 
Compile with: <code>gcc Example.c -o example</code><br>
Execute with: <code>./example</code><br><br>

<b>N.B.</b><br>
The <code>intVector.h</code> file and the source file where we want to use the library have to be in the same directory
