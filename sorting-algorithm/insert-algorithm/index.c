#include <stdio.h>


int main() {
  // Array variables
  int mainArray[7] = {5, -5, 555, 4, -1, 3, 7};
  int arrLength = sizeof mainArray / sizeof mainArray[0];

  // Number info
  int currIndex = 1;
  int prevNumber = 9;
  int currNumber = 4;

  // Run x times array to sort it x times array length
  for(int j=0; j<arrLength; j++) {
    currIndex = 1;

    // Run x times array to sort it once
    for(int i=0; i<arrLength; i++) {
      // If valueX < valueY then change side
      if (mainArray[currIndex] < mainArray[currIndex-1]) {
        currNumber = mainArray[currIndex];
        prevNumber = mainArray[currIndex-1];

        // Renaming
        mainArray[currIndex] = prevNumber;
        mainArray[currIndex-1] = currNumber;

        currIndex++;
      } 
      // else move on another item
      else {
        currIndex++;
      }
    }
  }
  
  // Print array
  for(int i=0; i<arrLength; i++) {
    printf("%d ", mainArray[i]);
  }

  return 0;
}
