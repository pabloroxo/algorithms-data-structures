/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Odd-even (also called Brick) sort
 */

#include <stdio.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void oddEvenSort(int numbers[], int size) {
    int i, sorted = 0;

    while (!sorted) {
        sorted = 1;

        for (i = 1; i < (size - 1); i += 2) {
            if (numbers[i] > numbers[i + 1]) {
                swap(&numbers[i], &numbers[i + 1]);
                sorted = 0;
            }
        }

        for (i = 0; i < (size - 1); i += 2) {
            if (numbers[i] > numbers[i + 1]) {
                swap(&numbers[i], &numbers[i + 1]);
                sorted = 0;
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

    oddEvenSort(numbers, size);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
