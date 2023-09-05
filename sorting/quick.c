/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Quick sort
 */

#include <stdio.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int numbers[], int low, int high) {
    int pivot = numbers[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (numbers[j] < pivot) {
            i++;
            swap(&numbers[i], &numbers[j]);
        }
    }

    swap(&numbers[i + 1], &numbers[high]);

    return i + 1;
}

void quicksort(int numbers[], int low, int high) {
    if (low < high) {
        int p = partition(numbers, low, high);
        quicksort(numbers, low, p - 1);
        quicksort(numbers, p + 1, high);
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

    quicksort(numbers, 0, size - 1);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
