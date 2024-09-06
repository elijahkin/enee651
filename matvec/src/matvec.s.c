#include <xmtc.h>

int main() {
  for (int row = 0; row < m; ++row) {
    int dot = 0;
    for (int entry = rowptr[row]; entry < rowptr[row + 1]; ++entry) {
      dot += values[entry] * vector[col_ind[entry]];
    }
    result[row] = dot;
  }

// DONT MODIFY THE REST
#ifdef PRINT_RESULT
  for (int i = 0; i < m; ++i) {
    printf("%d\n", result[i]);
  }
#endif
}
