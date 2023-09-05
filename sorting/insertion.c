/* Pablo Roxo - https://github.com/pabloroxo
 *
 * Insertion sort
 */

#include <stdio.h>

void merge(int numbers[], int left, int i, int right) {
    int j, k, l;
    int n1 = i - left + 1;
    int n2 = right - i;
    int leftArray[n1], rightArray[n2];

    for (j = 0; j < n1; j++) {
        leftArray[j] = numbers[left + j];
    }

    for (j = 0; j < n2; j++) {
        rightArray[j] = numbers[i + 1 + j];
    }

    j = 0;
    k = 0;
    l = left;

    while (j < n1 && k < n2) {
        if (leftArray[j] <= rightArray[k]) {
            numbers[l] = leftArray[j];
            j++;
        } else {
            numbers[l] = rightArray[k];
            k++;
        }
        l++;
    }

    while (j < n1) {
        numbers[l] = leftArray[j];
        j++;
        l++;
    }

    while (k < n2) {
        numbers[l] = rightArray[k];
        k++;
        l++;
    }
}

void mergeSort(int numbers[], int left, int right) {
    if (left < right) {
        int i = left + (right - left) / 2;

        mergeSort(numbers, left, i);
        mergeSort(numbers, i + 1, right);

        merge(numbers, left, i, right);
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

    mergeSort(numbers, 0, size - 1);

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
