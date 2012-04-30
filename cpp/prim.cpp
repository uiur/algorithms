// O(V^2)
#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 100000000;

int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;

int prim() {
  int res = 0;
  fill(mincost, mincost+V, INF);
  fill(used, used+V, false);
  mincost[0] = 0;
  
  while(true) {
    int v = -1;
    for(int u = 0; u < V; u++) 
      if(!used[u] && (v == -1 || mincost[v] > mincost[u]))
        v = u;
    if(v==-1) break;
    used[v] = true;
    v += mincost[v];
    mincost[v] = 0;

    for(int u = 0; u < V; u++)
      mincost[u] = min(mincost[u], cost[v][u]);
  }
  return res;
}
