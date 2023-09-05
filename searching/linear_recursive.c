#include <stdio.h>

/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Linear search (recursively)
 */

int search(int numbers[], int number, int i, int size) {
    if (numbers[i] == number) {
        return i;
    } else if (i < size) {
        return search(numbers, number, ++i, size);
    } else {
        return -1;
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

    int found = search(numbers, number, 0, size);

    if (found != -1) {
        printf("Number %d found\n", number);
    } else {
        printf("Number %d not found\n", number);
    }

    return 0;
}
