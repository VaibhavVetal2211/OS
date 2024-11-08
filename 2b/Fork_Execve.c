/*
Implement the C program in which main program accepts an array. Main program uses the
FORK system call to create a new process called a child process. Parent process sorts an array and
passes the sorted array to child process through the command line arguments of EXECVE system
call. The child process uses EXECVE system call to load new program which display array in reverse
order
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of integers you want to sort: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter numbers : \n");  
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
bubbleSort(arr,n);
    // Forking a child process
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        // Convert array to string arguments
        char arr_str[n][10];
        char* args[n + 2];
        args[0] = "./process";  // Executable name for child process
        for (i = 0; i < n; i++) {
            sprintf(arr_str[i], "%d", arr[i]);
            args[i + 1] = arr_str[i];
        }
        args[n + 1] = NULL;  // Mark the end of arguments
        
        execve(args[0], args, NULL);  // Execute the child process
        perror("execve");  // execve only returns on error
        exit(1);
    } else {
        // Parent process
        bubbleSort(arr, n);  // Sort the array using bubble sort
        wait(NULL);  // Wait for child process to complete
        printf("Parent Process id : %d\n", getpid());
    }
    return 0;
}

