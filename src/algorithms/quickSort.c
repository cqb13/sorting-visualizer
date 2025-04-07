#include "../main.h"
#include <unistd.h>

int partition(int low, int high, int *numbers, char *buffer) {
  int pivot = numbers[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (numbers[j] < pivot) {
      i++;
      int temp = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = temp;
      clearLines(NUMBER_AMOUNT);
      usleep(100000);
      mapNumbersToBuffer(buffer, numbers);
      printBuffer(buffer);
      clearBuffer(buffer);
    }
  }

  int temp = numbers[i + 1];
  numbers[i + 1] = numbers[high];
  numbers[high] = temp;
  clearLines(NUMBER_AMOUNT);
  usleep(100000);
  mapNumbersToBuffer(buffer, numbers);
  printBuffer(buffer);
  clearBuffer(buffer);
  return i + 1;
}

void quickSort(int low, int high, int *numbers, char *buffer) {
  if (low < high) {
    int p = partition(low, high, numbers, buffer);
    quickSort(low, p - 1, numbers, buffer);
    quickSort(p + 1, high, numbers, buffer);
  }
}
