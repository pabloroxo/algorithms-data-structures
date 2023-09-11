/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Comb sort
 */

#include <stdio.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

int newGap(int gap) {
    gap = (gap * 10) / 13;

    if (gap == 9 || gap == 10) {
        gap = 11;
    } else if (gap < 1) {
        gap = 1;
    }

    return gap;
}

void combSort(int numbers[], int size) {
    int i, j, swapped, gap = size;

    do {
        gap = newGap(gap);
        swapped = 0;

        for (i = 0; i < (size - gap); i++) {
            j = i + gap;

            if (numbers[i] > numbers[j]) {
                swap(&numbers[i], &numbers[j]);
                swapped = 1;
            }
        }
    } while (gap != 1 && swapped);
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

    combSort(numbers, size);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
