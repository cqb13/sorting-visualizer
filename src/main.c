#include "main.h"
#include "algorithms/bubbleSort.h"
#include "algorithms/insertionSort.h"
#include "algorithms/mergeSort.h"
#include "algorithms/quickSort.h"
#include "algorithms/selectionSort.h"
#include "algorithms/shellSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearLines(int lines) {
  for (int i = 0; i < lines; i++) {
    printf("\033[A\033[K");
  }
}

void shuffleArray(int *arr, int n) {
  srand(time(NULL));

  for (int i = n - 1; i > 0; i--) {
    int j = rand() % (i + 1);

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

void mapNumbersToBuffer(char *buffer, int *numbers) {
  for (int i = 0; i < NUMBER_AMOUNT; i++) {
    int value = numbers[i];

    int yOffset = NUMBER_AMOUNT - 1;
    while (value > 0) {
      buffer[yOffset * NUMBER_AMOUNT + i] = '#';
      yOffset--;
      value--;
    }
  }
}

void clearBuffer(char *buffer) {
  for (int y = 0; y < NUMBER_AMOUNT; y++) {
    for (int x = 0; x < NUMBER_AMOUNT; x++) {
      buffer[y * NUMBER_AMOUNT + x] = ' ';
    }
  }
}

void printBuffer(char *buffer) {
  char *displayBuffer =
      malloc(NUMBER_AMOUNT * (NUMBER_AMOUNT * 2 + 1) + 1 * sizeof(char));

  char *ptr = displayBuffer;
  for (int y = 0; y < NUMBER_AMOUNT; y++) {
    for (int x = 0; x < NUMBER_AMOUNT; x++) {
      *ptr++ = buffer[y * NUMBER_AMOUNT + x];
      *ptr++ = ' ';
    }
    *ptr++ = '\n';
  }

  *ptr = '\0';
  printf("%s", displayBuffer);
  free(displayBuffer);
}

void displaySupportedAlgorithms() {
  printf("Supported Algorithms:\n");
  printf("  Bubble Sort: bubble\n");
  printf("  Insertion Sort: insertion\n");
  printf("  Merge Sort: merge\n");
  printf("  Quick Sort: quick\n");
  printf("  Selection Sort: selection\n");
  printf("  Shell Sort: shell\n");
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    displaySupportedAlgorithms();
    return 0;
  }

  int *numbers = malloc(sizeof(int) * NUMBER_AMOUNT);

  for (int i = 0; i < NUMBER_AMOUNT; i++) {
    numbers[i] = i + 1;
  }

  shuffleArray(numbers, NUMBER_AMOUNT);

  char *buffer = (char *)malloc(NUMBER_AMOUNT * NUMBER_AMOUNT * sizeof(char));
  clearBuffer(buffer);

  printBuffer(buffer);

  for (int i = 0; i < NUMBER_AMOUNT; i++) {
    printf("%d, ", numbers[i]);
  }
  printf("\n");

  if (*argv[1] == *"selection") {
    selectionSort(numbers, buffer);
  } else if (*argv[1] == *"insertion") {
    insertionSort(numbers, buffer);
  } else if (*argv[1] == *"bubble") {
    bubbleSort(numbers, buffer);
  } else if (*argv[1] == *"shell") {
    shellSort(numbers, buffer);
  } else if (*argv[1] == *"quick") {
    quickSort(0, NUMBER_AMOUNT, numbers, buffer);
  } else if (*argv[1] == *"merge") {
    mergeSort(numbers, buffer, NUMBER_AMOUNT);
  } else {
    displaySupportedAlgorithms();
    return 0;
  }

  clearLines(NUMBER_AMOUNT);
  mapNumbersToBuffer(buffer, numbers);
  printBuffer(buffer);
  clearBuffer(buffer);

  free(numbers);
  free(buffer);
  return 0;
}
