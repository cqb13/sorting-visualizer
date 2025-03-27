#include "main.h"
#include <stdio.h>
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

void sequentialSort(int *numbers, char *buffer) {
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
