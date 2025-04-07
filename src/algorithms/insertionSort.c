#include "../main.h"
#include <unistd.h>

void insertionSort(int *numbers, char *buffer) {
  for (int i = 1; i < NUMBER_AMOUNT; i++) {
    clearLines(NUMBER_AMOUNT);
    usleep(100000);
    int temp = numbers[i];
    int pIndex = i;

    while (pIndex > 0 && temp < numbers[pIndex - 1]) {
      numbers[pIndex] = numbers[pIndex - 1];
      pIndex--;
    }

    numbers[pIndex] = temp;

    mapNumbersToBuffer(buffer, numbers);
    printBuffer(buffer);
    clearBuffer(buffer);
  }
}
