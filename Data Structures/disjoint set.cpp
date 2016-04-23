// UNION

// INPUT: Two integers X and Y
// OUTPUT: IT joins the Set of X and Set Y if they are not connected.

// FIND

// INPUT: An integer X
// OUTPUT: IT return the parent of Set X


#include "bits/stdc++.h"
using namespace std;

class DisjointSet{
    public: 
        int V, E;
        vector<int> parent;
        DisjointSet(int N, int M){ // Number of vertices, edges
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
