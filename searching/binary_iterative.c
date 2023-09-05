/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Binary search (iteratively)
 */

#include <stdio.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void sort(int numbers[], int size) {
    int i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (numbers[i] > numbers[j]) {
                swap(&numbers[i], &numbers[j]);
            }
        }
    }
}

int search(int numbers[], int number, int size) {
    int left = 0, right = size - 1, i;

    while (left <= right) {
        i = left + (right - left) / 2;

        if (numbers[i] == number) {
            return i;
        } else if (numbers[i] < number) {
            left = i + 1;
        } else {
            right = i - 1;
        }
    }

    return -1;
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

    int number;
    fscanf(file, "%d", &number);

    fclose(file);

    // Binary search only works with sorted arrays
    sort(numbers, size);

    int found = search(numbers, number, size);

    if (found != -1) {
        printf("Number %d found\n", number);
    } else {
        printf("Number %d not found\n", number);
    }

    return 0;
}
