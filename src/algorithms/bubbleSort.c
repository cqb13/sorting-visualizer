#include "../main.h"
#include <unistd.h>

// TODO: fix
void bubbleSort(int *numbers, char *buffer) {
  for (int i = 0; i < NUMBER_AMOUNT; i++) {
    clearLines(NUMBER_AMOUNT);
    usleep(100000);

    for (int j = 0; j < NUMBER_AMOUNT; j++) {
      if (i == j) {
        continue;
      }

      if (numbers[j] > numbers[i]) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
      }
    }

    mapNumbersToBuffer(buffer, numbers);
    printBuffer(buffer);
    clearBuffer(buffer);
  }
}
