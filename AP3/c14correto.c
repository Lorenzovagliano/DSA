#include <stdio.h>

int main(void) {
  int n = 0, fact = 1;

  printf("Positive integer:");
  scanf("%d", &n);
  
  for (int i = 1; i <= n; ++i) {
    fact *= i;
  }

  printf("Factorial %d = %d\n", n, fact);
}
