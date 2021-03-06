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
