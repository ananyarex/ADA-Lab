#include <stdio.h>
#include <time.h>

int num;
clock_t start, end, t;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);  
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;  
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int s = partition(arr, low, high);  

        quickSort(arr, low, s - 1);  
        quickSort(arr, s + 1, high);  
    }
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &num);

    int ip_array[num]; 

    
    for (int i = num-1; i >= 0; i--) {
        ip_array[i] = i + 11;
    }

    start = clock(); 

    quickSort(ip_array, 0, num - 1); 

    end = clock();  

    t = end - start; 

    printf("\nThe sorted array:\n");
    for (int i = 0; i < num; i++) {
        printf("%d\n", ip_array[i]);  
    }

    printf("\nTime taken: %.6f seconds\n", (double)t / CLOCKS_PER_SEC);

    return 0;
}
