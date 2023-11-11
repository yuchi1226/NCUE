#include <stdio.h>
#include <stdlib.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionSort(double arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    double data[2000];
    int dataSize = 0;
    double number;
    FILE *inputFile = fopen("test1.txt", "r");

    if (!inputFile) {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%lf", &number) != EOF) {
        data[dataSize] = number;
        dataSize++;
    }

    int choice;
    do {
        printf("Menu:\n1. Quick Sort\n2. Insertion Sort\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                quickSort(data, 0, dataSize - 1);
                break;
            case 2:
                insertionSort(data, dataSize);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }

        if (choice == 1 || choice == 2) {
            printf("\nSorted Data:\n");
            for (int i = 0; i < dataSize; i++) {
                printf("%.2f  ", data[i]);
            }
            printf("\n");

            printf("Total numbers: %d\n", dataSize);
            if (dataSize > 0) {
                double max = data[0];
                double min = data[0];
                for (int i = 1; i < dataSize; i++) {
                    if (data[i] > max) {
                        max = data[i];
                    }
                    if (data[i] < min) {
                        min = data[i];
                    }
                }
                printf("Maximum number: %.2f\n", max);
                printf("Minimum number: %.2f\n", min);
            }
        }
    } while (choice != 3);

    fclose(inputFile);
    return 0;
}

