/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Cocktail sort
 */

#include <stdio.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void cocktailSort(int numbers[], int size) {
    int i, start = 0, end = (size - 1), swapped;

    do {
        swapped = 0;

        for (i = start; i < end; i++) {
            if (numbers[i] > numbers[i + 1]) {
                swap(&numbers[i], &numbers[i + 1]);
                swapped = 1;
            }
        }

        if (swapped) {
            swapped = 0;
            end--;

            for (int i = (end - 1); i >= 0; i--) {
                if (numbers[i] > numbers[i + 1]) {
                    swap(&numbers[i], &numbers[i + 1]);
                    swapped = 1;
                }
            }

            start++;
        }
    } while (swapped);
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

    cocktailSort(numbers, size);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
