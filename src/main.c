#include "main.h"
#include "algorithms.h"
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
  for (int y = 0; y < NUMBER_AMOUNT; y++) {
    for (int x = 0; x < NUMBER_AMOUNT; x++) {
      printf("%c ", buffer[y * NUMBER_AMOUNT + x]);
    }
    printf("\n");
  }
}

int main() {
  int *numbers = malloc(sizeof(int) * NUMBER_AMOUNT);

  for (int i = 0; i < NUMBER_AMOUNT; i++) {
    numbers[i] = i + 1;
  }

  shuffleArray(numbers, NUMBER_AMOUNT);

  char *buffer = (char *)malloc(NUMBER_AMOUNT * NUMBER_AMOUNT * sizeof(char));
  clearBuffer(buffer);

  printBuffer(buffer);
  shellSort(numbers, buffer);
  clearLines(NUMBER_AMOUNT);
  mapNumbersToBuffer(buffer, numbers);
  printBuffer(buffer);
  clearBuffer(buffer);

  free(numbers);
  free(buffer);
  return 0;
}
