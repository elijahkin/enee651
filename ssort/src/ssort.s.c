#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int A[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && A[left] > A[largest]) {
    largest = left;
  }
  if (right < n && A[right] > A[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(&A[i], &A[largest]);
    heapify(A, n, largest);
  }
}

void heap_sort(int A[], int n) {
  // Build the heap
  for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(A, n, i);
  }

  // One by one extract elements from heap
  for (int i = n - 1; i > 0; --i) {
    swap(&A[0], &A[i]);
    heapify(A, i, 0);
  }
}

int main() {
  // TODO Eventually remove since these come from the data
  int A[] = {12, 11, 13, 5, 6, 7};
  int N = sizeof(A) / sizeof(A[0]);
  int result[N];

  // Copy the unsorted array A into result
  for (int i = 0; i < N; ++i) {
    result[i] = A[i];
  }

  // Sort result
  heap_sort(result, N);

  // TODO Check that result is correctly sorted
  return 0;
}
