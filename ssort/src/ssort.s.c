void heapify(int A[], int n, int i) {
  while (true) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest]) {
      largest = left;
    }
    if (right < n && A[right] > A[largest]) {
      largest = right;
    }

    if (largest == i) {
      break;
    }

    int temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;
    i = largest;
  }
}

void heap_sort(int A[], int n) {
  // Build the heap
  for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(A, n, i);
  }

  // One by one extract elements from heap
  for (int i = n - 1; i > 0; --i) {
    int temp = A[0];
    A[0] = A[i];
    A[i] = temp;
    heapify(A, i, 0);
  }
}

int main() {
  // Copy the unsorted array A into result
  for (int i = 0; i < N; ++i) {
    result[i] = A[i];
  }

  // Sort result
  heap_sort(result, N);
  return 0;
}
