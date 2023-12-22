#include <stdio.h>
#include <windows.h>

void bubbleSort(int arr[], int n);
void merge(int *arr1, int *arr2, int *arr3, int n, int m);

int main() {
    int n, m;
    printf("Podaj rozmiar pierwszej tablicy (n): ");
    scanf("%d", &n);
    printf("Podaj rozmiar drugiej tablicy (m): ");
    scanf("%d", &m);
    int arr1[n], arr2[m], arr3[n + m];
    printf("Podaj elementy pierwszej tablicy:\n");
    for (int i = 0; i < n; i++) {
        printf("arr1[%d]: ", i);
        scanf("%d", &arr1[i]);
    }
    printf("Podaj elementy drugiej tablicy:\n");
    for (int i = 0; i < m; i++) {
        printf("arr2[%d]: ", i);
        scanf("%d", &arr2[i]);
    }
    bubbleSort(arr1, n);
    bubbleSort(arr2, m);
    merge(arr1, arr2, arr3, n, m);

    printf("\nPosortowana i scalona tablica:\n");
    for (int i = 0; i < n + m; i++) {
        printf("arr3[%d]: %d\n", i, arr3[i]);
    }

    return 0;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void merge(int *arr1, int *arr2, int *arr3, int n, int m) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n) {
        arr3[k++] = arr1[i++];
    }

    while (j < m) {
        arr3[k++] = arr2[j++];
    }
}
