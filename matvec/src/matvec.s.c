#include <xmtc.h>

int main() {
  for (int row = 0; row < m; ++row) {
    result[row] = 0;
    for (int entry = rowptr[row]; entry < rowptr[row + 1]; ++entry) {
      result[row] += values[entry] * vector[col_ind[entry]];
    }
  }

// DONT MODIFY THE REST
#ifdef PRINT_RESULT
  for (int i = 0; i < m; ++i) {
    printf("%d\n", result[i]);
  }
#endif
}
