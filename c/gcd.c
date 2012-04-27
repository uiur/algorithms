#include <stdio.h>

int gcd(int a, int b);
// Test
void test(void);
void assert(int t);

int main(void) {
  test();

  return 0;
}

int gcd(int a, int b) {
  int temp;
  while (b > 0) {
    temp = a;
    a = b;
    b = temp % b;
  }
  
  return a;
}

// Test
void assert(int t) {
  if (!t) {
    printf("Test Failed!\n");
  }
}

void test(void) {
  assert(gcd(4,2) == 2);
  assert(gcd(30,12) == 6);
  assert(gcd(12,40) == 4);
  assert(gcd(4,1) == 1);
  assert(gcd(4,0) == 4);
}

