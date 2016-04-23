// Lowest Common Ancestor in a Tree
// Running Time: O(log |N|)
// INPUT: graph - You need to build it
// OUTPUT: 
//     - LCA of two nodes U, V
//     - path distance between U, V

#include "bits/stdc++.h"
using namespace std;

const int MAX = 1e5;
vector< int > graph[MAX+5];

const int INF = 1e9, LOGN = 20;
int level[MAX+8], DP[LOGN+5][MAX+5];

struct LCA{
    int n;
public:
    LCA(int N){
        n = N;
    }

    void dfs0(int u)
    {
        for(auto it=graph[u].begin();it!=graph[u].end();it++)
            if(*it!=DP[0][u])
            {
                DP[0][*it]=u;
                level[*it]=level[u]+1;
                dfs0(*it);
            }
    }
    void preprocess()
    {
        level[0]=0;
        DP[0][0]=0;
        dfs0(0);
        for(int i=1;i<LOGN;i++)
            for(int j=0;j<n;j++)
                DP[i][j] = DP[i-1][DP[i-1][j]];
    }
    int lca(int a,int b)
    {
        if(level[a]>level[b])swap(a,b);
        int d = level[b]-level[a];
        for(int i=0;i<LOGN;i++)
            if(d&(1<<i))
                b=DP[i][b];
        if(a==b)return a;
        for(int i=LOGN-1;i>=0;i--)
            if(DP[i][a]!=DP[i][b])
                a=DP[i][a],b=DP[i][b];
        return DP[0][a];
    }
    int dist(int u,int v)
    {
        return level[u] + level[v] - 2*level[lca(u,v)];
    }
};

int main(){
    // verified used in various programming contest
}