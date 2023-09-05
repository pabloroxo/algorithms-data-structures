/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Merge sort
 */

#include <stdio.h>

void insertionSort(int numbers[], int size) {
    int i, key, j;

    for (i = 1; i < size; i++) {
        key = numbers[i];
        j = i - 1;

        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }

        numbers[j + 1] = key;
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

    insertionSort(numbers, size);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
