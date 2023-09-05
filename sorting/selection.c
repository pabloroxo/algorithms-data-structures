/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Selection sort
 */

#include <stdio.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void selectionSort(int numbers[], int size) {
    int i, j, min;

    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (numbers[min] > numbers[j]) {
                min = j;
            }
            if (min != i) {
                swap(&numbers[i], &numbers[min]);
            }
        }
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

    selectionSort(numbers, size);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
