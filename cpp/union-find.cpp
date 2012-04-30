#include <iostream>
#include <cstdio>
using namespace std;

int parent[MAX_N];
int rank[MAX_N];

void init(int n) {
  for(int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 1;
  }
}

int find(int a) {
  if(parent[a] == a) {
    return a;
  }
  return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if(rank[a] < rank[b]) {
    int temp = a;
    a = b;
    b = temp;
  }
  parent[b] = a;
  if(rank[a] == rank[b]) rank[a]++;
}

