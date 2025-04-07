#include "../main.h"
#include <unistd.h>

void shellSort(int *numbers, char *buffer) {
  for (int gap = NUMBER_AMOUNT / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < NUMBER_AMOUNT; i++) {
      int temp = numbers[i];

      int j;
      for (j = i; j >= gap && numbers[j - gap] > temp; j -= gap) {
        clearLines(NUMBER_AMOUNT);
        usleep(100000);

        numbers[j] = numbers[j - gap];

        mapNumbersToBuffer(buffer, numbers);
        printBuffer(buffer);
        clearBuffer(buffer);
      }

      numbers[j] = temp;
    }
  }
}
