#include <stdio.h>

/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Binary search (recursively)
 */

void sort(int numbers[], int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (numbers[i] > numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int search(int numbers[], int number, int left, int right) {
    if (left > right) {
        return - 1;
    }

    int i = left + (right - left) / 2;

    if (numbers[i] == number) {
        return i;
    } else if (numbers[i] < number) {
        return search(numbers, number, i + 1, right);
    } else {
        return search(numbers, number, left , i - 1);
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

    int number;
    fscanf(file, "%d", &number);

    fclose(file);

    // Binary search only works with sorted arrays
    sort(numbers, size);

    int found = search(numbers, number, 0, size - 1);

    if (found != -1) {
        printf("Number %d found\n", number);
    } else {
        printf("Number %d not found\n", number);
    }

    return 0;
}
