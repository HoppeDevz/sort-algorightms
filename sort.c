#include <stdio.h>
#include <stdlib.h>

const int NUMBER_OF_ELEMENTS = 5;



// 4    -1      10      32      17
// 




enum MENU_OPTIONS {
    BUBBLE_SORT = 1,
    SELECTION_SORT = 2,
    INSERTION_SORT = 3,
    MERGE_SORT = 4,
    QUICK_SORT = 5,
    EXIT = 6
};

void merge(int** refArr, int l, int m, int r) {

    int* arr = *refArr;

    int k;
    int l_length = m - l + 1;
    int r_length = r - m;

    int L[l_length];
    int R[r_length];

    for (int i = 0; i < l_length; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < r_length; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    k = l;

    while (i < l_length && j < r_length) {

        if (L[i] <= R[j]) {

            arr[k] = L[i];
            i++;
        }

        if (L[i] > R[j]) {

            arr[k] = R[j];
            j++;
        }

        k++;
    }

    if (i < l_length) {

        arr[k] = L[i];
        i++;
        k++;
    }

    if (j < r_length) {

        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int** refArr, int l, int r) {

    if (l < r) {

        int m = (l + r) / 2;

        mergeSort(refArr, l, m);
        mergeSort(refArr, m + 1, r);

        printf("merge -> l: %d | m: %d | r: %d\n", l, m, r);
        merge(refArr, l, m, r);
    }
}

void mergeSortRoutine() {

    int* numbers = malloc(sizeof(int) * NUMBER_OF_ELEMENTS);

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        scanf("%d", &numbers[i]);
    }

    system("clear");

    mergeSort(&numbers, 0, NUMBER_OF_ELEMENTS - 1);

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        printf("%d ", numbers[i]);
    }
}

void quickSort(int** arrRef, int start, int end) {
    
    int* arr = *arrRef;
    int pivot = arr[end];
    
    int swaptPtrIndex = start;
    int itPtrIndex = start;
    
    while (itPtrIndex < end) {

        if (arr[itPtrIndex] < pivot) {

            int aux = arr[swaptPtrIndex];

            arr[swaptPtrIndex] = arr[itPtrIndex];
            arr[itPtrIndex] = aux;

            swaptPtrIndex++;

        }

        itPtrIndex++;
    }

    // Move pivot to midPtrIndex
    if (arr[swaptPtrIndex] > pivot) {

        int aux = arr[swaptPtrIndex];

        arr[swaptPtrIndex] = pivot;
        arr[end] = aux;

    }
    
    // Call quicksort to left/right arr.

    if (start < swaptPtrIndex - 1) {
        quickSort(arrRef, start, swaptPtrIndex - 1);
    }

    if (swaptPtrIndex + 1 < end) {
        quickSort(arrRef, swaptPtrIndex + 1, end);
    }
    
}

void quickSortRoutine() {

    int* numbers = malloc(sizeof(int) * NUMBER_OF_ELEMENTS);
    
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        scanf("%d", &numbers[i]);
    }

    system("clear");

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        printf("%d ", numbers[i]);
    }

    quickSort(&numbers, 0, NUMBER_OF_ELEMENTS - 1);

    printf("\n\nQuick Sorted! 🥳🎉 \n");
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        printf("%d ", numbers[i]);
    }
}

void insertionSort() {

    int* numbers = malloc(sizeof(int) * NUMBER_OF_ELEMENTS);

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        scanf("%d", &numbers[i]);
    }

    system("clear");

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        if (i == 0)
            continue;

        for (int j = 0; j < i; j++) {

            if (numbers[i] < numbers[j]) {

                int aux = numbers[j];

                numbers[j] = numbers[i];
                numbers[i] = aux;

                continue;
            }
        }
    }

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        printf("%d ", numbers[i]);
    }
}

void selectionSort() {

    int* numbers = malloc(sizeof(int) * NUMBER_OF_ELEMENTS);

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        scanf("%d", &numbers[i]);
    }

    system("clear");

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        int minValueIndex = i;
        int minValue = numbers[i];

        for (int j = i; j < NUMBER_OF_ELEMENTS; j++) {
            
            if (numbers[j] < minValue) {

                minValue = numbers[j];
                minValueIndex = j;
            }
        }

        int aux = numbers[i];

        numbers[i] = minValue;
        numbers[minValueIndex] = aux;
    }

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        printf("%d ", numbers[i]);
    }
}

void bubbleSort() {

    int* numbers = malloc(sizeof(int) * NUMBER_OF_ELEMENTS);

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        scanf("%d", &numbers[i]);
    }

    system("clear");

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        for (int j = 0; j < NUMBER_OF_ELEMENTS; j++) {

            int aux;

            if (numbers[j] > numbers[j + 1]) {

                aux = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {

        printf("%d ", numbers[i]);
    }
}

int main() {

    system("clear");

    char flag = 1;
    char option;

    while (flag == 1) {

        printf("Select a sort method: \n");
        printf("\t1 - Bubble Sort\n");
        printf("\t2 - Selection Sort\n");
        printf("\t3 - Insert Sort\n");
        printf("\t4 - Merge Sort\n");
        printf("\t5 - Quick Sort\n");
        printf("\t6 - Sair\n");

        scanf("%d", &option);

        system("clear");

        switch (option) {

            case BUBBLE_SORT: {
                bubbleSort();
                break;
            }

            case SELECTION_SORT: {
                selectionSort();
                break;
            }

            case INSERTION_SORT: {
                insertionSort();
                break;
            }

            case MERGE_SORT: {
                mergeSortRoutine();
                break;
            }

            case QUICK_SORT: {
                quickSortRoutine();
                break;
            }

            case EXIT: {
                flag = 0;
            }
        }
    }

    return 0;
}