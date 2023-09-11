/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Gnome sort
 */

#include <stdio.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void gnomeSort(int numbers[], int size) {
    int i = 0;

    while (i < size) {
        if (i == 0) {
            i++;
        }
        if (numbers[i] >= numbers[i - 1]) {
            i++;
        } else {
            swap(&numbers[i], &numbers[i - 1]);
            i--;
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

    gnomeSort(numbers, size);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
