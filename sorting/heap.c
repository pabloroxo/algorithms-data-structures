/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Heap sort
 */

#include <stdio.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void heapify(int numbers[], int size, int i) {
    int max = i;
    int left = ((2 * i) + 1);
    int right = ((2 * i) + 2);

    if ((left < size) && (numbers[left] > numbers[max])) {
        max = left;
    }

    if ((right < size) && (numbers[right] > numbers[max])) {
         max = right;
    }

    if (max != i) {
        swap(&numbers[i], &numbers[max]);
        heapify(numbers, size, max);
    }
}

void heapSort(int numbers[], int size) {
    for (int i = ((size / 2) - 1); i >= 0; i--) {
         heapify(numbers, size, i);
    }

    for (int i = (size - 1); i >= 0; i--) {
        swap(&numbers[0], &numbers[i]);

        heapify(numbers, i, 0);
    }
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r");

    int size;
    fscanf(file, "%d", &size);

    int i, numbers[size];
    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &numbers[i]);
    }

    fclose(file);

    heapSort(numbers, size);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
