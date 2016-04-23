// genCentroidTree

// INPUT: A tree
// OUTPUT: Build a centroid tree
// Centroid tree is stored in parentCT



#include "bits/stdc++.h"
using namespace std;

#define LL long long int
const int MAX = 1e5;

int n, m;
set<int> graph[MAX+5];
vi countChild(MAX+5);
vi parentCT(MAX+5, -1); // Stores parent of each node in the centroid tree
int nodes, centroid;

struct CentroidDecomposition
{
    void buildGraph(int vertices, int edges)
    { 
        int x, y;
        for(int i = 0;i<edges;i++){
            cin>>x>>y;
            x--;y--;
            graph[x].insert(y);
            graph[y].insert(x);
        }
    }
    
    void pre(int id, int p, int init)
    { // DFS and assign parent to each node of centroid tree
        countChild[id] = 1;
        parentCT[id] = init;
        nodes++;
        for(auto it: graph[id])
        {
            if(it!=p)
            { 
                pre(it, id, init);
                countChild[id]+=countChild[it];
            }
        }
    }
    
    int findCentroid(int id, int N, int p=-1)
    { // To find the centroid of the tree
        for(auto it: graph[id])
        {
            if(countChild[it]>N/2)
                if(p!=it)
                    return findCentroid(it, N, id);
        }
        return id;    
    }
    
    void genCentroidTree(int id, int init = -1)
    { // Centroid Tree is generated
        nodes = 0;
        pre(id, -1, init);
        int centroid = findCentroid(id, nodes);
        for(auto it: graph[centroid])
        {
            
            // Deleting Centroid from tree
            graph[it].erase(centroid);
            genCentroidTree(it, centroid);
        }
    } 
}CT;

