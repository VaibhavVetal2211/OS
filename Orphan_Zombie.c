#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of integers to sort: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Creating a child process using fork()
    pid_t pid = fork();

    if (pid < 0) {
        // If fork fails
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {   // executing the child process
        // Child process: sorts using Selection Sort
        printf("Child Process: Sorting using Selection Sort...\n");
        selectionSort(arr, n);
        printf("Child Process: Sorted Array: ");
        printArray(arr, n);
        exit(0); // Child process exits
    } else {

        // Waiting for child process to finish
        wait(NULL);
        // Parent process: sorts using Bubble Sort
        printf("Parent Process: Sorting using Bubble Sort...\n");
        bubbleSort(arr, n);
        printf("Parent Process: Sorted Array: ");
        printArray(arr, n);

        
        printf("Parent Process: Child process has completed.\n");
    }

    return 0;
}

