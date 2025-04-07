#include "../main.h"
#include <unistd.h>

void selectionSort(int *numbers, char *buffer) {
  for (int i = 0; i < NUMBER_AMOUNT - 1; i++) {
    clearLines(NUMBER_AMOUNT);
    usleep(100000);
    int minV = numbers[i];
    int minI = i;

    for (int k = i + 1; k < NUMBER_AMOUNT; k++) {
      if (numbers[k] < minV) {
        minV = numbers[k];
        minI = k;
      }
    }

    numbers[minI] = numbers[i];
    numbers[i] = minV;

    mapNumbersToBuffer(buffer, numbers);
    printBuffer(buffer);
    clearBuffer(buffer);
  }
}
