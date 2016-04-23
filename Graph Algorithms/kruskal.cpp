// Implementation of Kruskal's algorithm using adjacency lists
// and disjoint sets.

// INPUT: A weighted Graph.
// OUTPUT: Cost of the Minimum Spanning Tree.

// Running time: O(|E| log |V|)

#include "bits/stdc++.h"
using namespace std;

#define FF first
#define SS second

typedef long long int LL;
typedef pair< int, int > pii;
typedef vector< int > vi;

priority_queue< pair<LL, pii>, vector< pair<LL, pii> >, greater< pair<LL, pii> > > ST;
vector< vector< pair<int, LL> > > tree;
    
class DisjointSet{
    public: 
        int V, E;
        vector<int> parent;
        DisjointSet(int N, int M){
            V = N;
            E = M;
            
            parent.resize(V+2);
            for(int i = 0;i<V+2;i++)
                parent[i] = i;
        }    
        
        int find(int id){
            return (id==parent[id]?id:find(parent[id]));
        }
        
        void UNION(int X, int Y){
            int Px = find(X), Py = find(Y);
            if(Px==Py) return ;
            parent[Px] = Py;
        }
};


struct MST{
    LL Kruskal(){
        LL wt, totalCost = 0;
        for(int i = 0;i<E;i++){
            scanf("%d %d %lld", &x, &y, &wt);
            ST.push(make_pair(wt, make_pair(x, y)));
        }
        tree.clear();
        tree.resize(V+2);
            
        DisjointSet djs(V, E);    
        while(!ST.empty()){
            pair< LL, pii > top = ST.top();
            ST.pop();
            int X = top.SS.FF, Y = top.SS.SS;
            wt = top.FF;
            if(djs.find(X)!=djs.find(Y)){
                djs.UNION(X, Y);
                totalCost+=wt;
                tree[X].push_back(make_pair(Y, wt));
                tree[Y].push_back(make_pair(X, wt));
            }    
        }
        
        return totalCost;
    }
}