#include "../main.h"
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

void copyArr(int *dest, int *src, int size, int offset) {
  int j = 0;
  for (int i = offset; i < size; i++) {
    dest[j++] = src[i];
  }
}

void merge(int *left, int leftSize, int *right, int rightSize, int *numbers,
           char *buffer) {
  int i = 0;
  int j = 0;
  int offset = 0;

  while (i < leftSize && j < rightSize) {
    if (left[i] < right[j]) {
      numbers[offset++] = left[i];
      i++;
    } else {
      numbers[offset++] = right[j];
      j++;
    }
  }

  if (i != leftSize - 1) {
    while (i < leftSize) {
      numbers[offset++] = left[i];
      i++;
    }
  }

  if (j != rightSize - 1) {
    while (j < rightSize) {
      numbers[offset++] = right[j];
      j++;
    }
  }
}

void mergeSort(int *numbers, char *buffer, int size) {
  if (size <= 1) {
    return;
  }

  int leftSize = size / 2;
  int rightSize = size - leftSize;
  int *left = malloc(leftSize * sizeof(int));
  copyArr(left, numbers, leftSize, 0);
  mergeSort(left, buffer, leftSize);

  int *right = malloc(rightSize * sizeof(int));
  copyArr(right, numbers, rightSize, leftSize);
  mergeSort(right, buffer, size - leftSize);

  merge(left, leftSize, right, rightSize, numbers, buffer);

  free(left);
  free(right);
}
