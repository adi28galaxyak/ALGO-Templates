// Strongly Connected Component using Kosaraju's Algorithm
// INPUT:
//     - A directed graph

// OUTPUT: 
//      - Prints the number of Strongly connected components in the given graph
//      - Prints the Strongly connected components in the graph.

#include "bits/stdc++.h"
using namespace std;

typedef vector< int > vi;
const int MAX = 1e5;
vector< bool > seen(MAX+1, false);
vector< int > graph[MAX+1], revGraph[MAX+1];
stack<int> torder;

struct StronglyConnectedComponent{
	void buildGraph(int V, int E){
		int x, y;
		for(int i = 0;i<E;i++){
			cin>>x>>y;
			graph[x].push_back(y);
		}
	}

	void dfs(int id){
		seen[id] = true;
		for(auto it: graph[id]){
			if(seen[it]==false) dfs(it);	
		}
		torder.push(id);
	}

	vector< int > topSort(int n){
        for(int id = 1;id<n+1;id++){
            if(!seen[id]) dfs(id);
        }

        vector<int> topological;
        while(!torder.empty()){
            topological.push_back(torder.top());
            torder.pop();
        }
       
        return topological;
    }

    void reverseGraph(int n){
        for(int id = 1;id<n+1;id++)
            for(auto it: graph[id]){
                revGraph[it].push_back(id);
            }
    }

    void revdfs(int id){
        seen[id] = true;
        printf("%d ", id);
        for(auto it: revGraph[id])
            if(!seen[it]) 
                revdfs(it);
    }
        
    int SCC(int n){
        int top, count = 0;
        vector< int > tsort = topSort(n);
        
        reverseGraph(n);
        
        for(int i = 0;i<n+1;i++) seen[i] = false;

        for(auto it: tsort){
        	if(!seen[it]){
                revdfs(it);
                cout<<endl;
                count++;
            }
        }
        
        return count;
    }
};

int main(){
	// freopen("inp.txt", "r", stdin);
	// StronglyConnectedComponent A;
	// int n, e;
	// cin>>n>>e;
	// A.buildGraph(n, e);
	// cout<<A.SCC(n)<<endl;;
	// while(!st.empty()){
	// 	cout<<st.top()<<endl;
	// 	st.pop();
	// }
	// A.dfs(1);
	// // vi Z = A.bfs(1);
	// for(int i=0;i<n+1;i++) cout<<i<<" "<<Z[i]<<endl;
}