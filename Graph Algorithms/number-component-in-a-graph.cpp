// Number Of Components in a graph
// INPUT:
//     - A graph

// OUTPUT: 
//     - Prints Number of components in the given graph

#include "bits/stdc++.h"
using namespace std;

typedef vector< int > vi;
const int MAX = 1e5;
vector< bool > seen(MAX+1, false);
vector< int > graph[MAX+1];

struct DFS{
	void buildGraph(int V, int E){
		int x, y;
		for(int i = 0;i<E;i++){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x); // Undirected Edge. For directed just make this line comment
		}
	}

	void dfs(int id){
		seen[id] = true;
		for(auto it: graph[id]){
			if(seen[it]==false) dfs(it);	
		}
	}

	int numComponents(int n){ // number of vertices
        int K = 0;
        for(int id = 1;id<n+1;id++){
            if(!seen[id]) {
                K++; // new component found
                dfs(id);
            }
        }
        return K;
    } 
};