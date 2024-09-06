#include <xmtc.h>

int main() {
  spawn(0, m - 1) {
    int dot = 0;
    for (int entry = rowptr[$]; entry < rowptr[$ + 1]; ++entry) {
      dot += values[entry] * vector[col_ind[entry]];
    }
    result[$] = dot;
  }

// DONT MODIFY THE REST
#ifdef PRINT_RESULT
  for (int i = 0; i < m; ++i) {
    printf("%d\n", result[i]);
  }
#endif
}
