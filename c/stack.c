#include <stdio.h>

#define STACK_SIZE 100
typedef int itemType;

typedef struct {
  int p;
  itemType stack[STACK_SIZE];
} Stack;

int empty(Stack *s);
itemType pop(Stack *s);
void push(Stack *s, itemType item);

// Test
void test(void);
void assert(int t);

int main(void) {
  test();

  return 0;
}

int empty(Stack *s) {
  return s->p == 0 ? 1 : 0;
}

itemType pop(Stack *s) {
  return s->stack[--(s->p)];
}

void push(Stack *s, itemType item) {
  s->stack[s->p++] = item;
}

// Test
void assert(int t) {
  if (!t) {
    printf("Test Failed!\n");
  }
}

void test(void) {
  Stack s = {0,{}};
  assert(empty(&s));
  push(&s,1);
  push(&s,4);
  assert(pop(&s) == 4);
  assert(pop(&s) == 1);
  assert(empty(&s));
}

