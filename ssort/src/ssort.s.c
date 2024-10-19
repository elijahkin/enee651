#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int A[], int n, int i) {
  int largest = i;       // Initialize largest as root
  int left = 2 * i + 1;  // left child
  int right = 2 * i + 2; // right child

  // If left child is larger than root
  if (left < n && A[left] > A[largest]) {
    largest = left;
  }

  // If right child is larger than largest so far
  if (right < n && A[right] > A[largest]) {
    largest = right;
  }

  // If largest is not root
  if (largest != i) {
    swap(&A[i], &A[largest]);

    // Recursively heapify the affected sub-tree
    heapify(A, n, largest);
  }
}

void heapSort(int A[], int n) {
  // Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(A, n, i);
  }

  // One by one extract elements from heap
  for (int i = n - 1; i > 0; i--) {
    // Move current root to end
    swap(&A[0], &A[i]);

    // Call max heapify on the reduced heap
    heapify(A, i, 0);
  }
}

// Function to print the array
void printArray(int A[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main() {
  int A[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(A) / sizeof(A[0]);

  printf("Original array: \n");
  printArray(A, n);

  heapSort(A, n);

  printf("Sorted array: \n");
  printArray(A, n);

  return 0;
}
