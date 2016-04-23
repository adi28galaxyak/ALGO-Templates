// Implementation of Dijkstra's algorithm using adjacency lists
// and priority queue for efficiency.

// INPUT:
//      - Weighted Graph
//      - Starting vertex

// OUTPUT: A Vector containing shortest distance between starting vertex and rest.

// Running time: O(|E| log |V|)

#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector< VI > VII;
typedef pair<int, int> pii;
#define FF first
#define SS second
#define PB(v) push_back(v)
#define MP(x,y) make_pair(x, y)

const int MAX = 1e5;
const int INF = 1e9;
vector< vector< pii > > graph(MAX+5);

struct DIJKSTRA{
	void buildGraph(int vertices, int edges){ 
        int x, y, distance;
        for(int i = 0;i<edges;i++){
            cin>>x>>y>>distance;
            graph[x].push_back(MP(y, distance));
            graph[y].push_back(MP(x, distance)); 
        }
    }

/*  		Nodes are indexed from 1		*/
    VI dij(int start, int N){ // SSSP from start
    	priority_queue<pii,vector<pii>, greater<pii> > PQ; // MIN HEAP
 
    	VI DIST(N+1, INF);
    	PQ.push(MP(0, start));

    	while(!PQ.empty()){
    		pii extract_min = PQ.top();
    		PQ.pop();

    		int BESTDIST = extract_min.FF, id = extract_min.SS;
    		if(BESTDIST<DIST[id]){
    			DIST[id] = BESTDIST; // Updating new distance
    			for(auto it: graph[id]){
    				if(DIST[it.FF] > DIST[id]+it.SS){
    					PQ.push(MP(DIST[id]+it.SS, it.FF));
    				}
    			}
    		}
    	}

    	return DIST;
    }
}SSSP;




