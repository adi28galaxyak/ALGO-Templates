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
vector<  > graph(MAX+5);

const int MAX = 1e5;
int N;
int chainNo = 0;
VI chainHead(MAX+5); // Head of the chain
VI chainPos(MAX+5); // Position of node in chain
VI chainInd(MAX+5); // which chain node is present
VI chainSize(MAX+5); // Size of chain
VI subtree(MAX+5, 0); // Subtree rooted at i
VI parent(MAX+5, -1); // parent of each node

struct HeavyLightDecomposition{
	
	int dfs(int id, int p = -1){
		subtree++; // including id
		for(auto it: graph[id]){
			if(it!=p){
				subtree[id]+=dfs(it, id);
			}
		}

		return subtree[id];
	}

	void init(){
		cin>>N;
		dfs(0);
	}

	void hld(int id){
		if(chainHead[chainNo]==-1)
			chainHead[chainNo] = id;

		chainInd[id] = chainNo;
		chainPos[id] = chainSize[chainNo];
		chainSize[chainNo]++;

		int maxchild = -1, ind = -1;
		for(auto it: graph[id]){
			if(it==p) continue;
			if(subtree[it]>maxchild){
				maxchild = subtree[it];
				ind = it;
			}
		}

		// it is the heavy child
		if(ind>=0) hld(ind);

		// About light child
		for(auto it: graph[id]){
			if(it==p or it==ind) continue;
			chainNo++;
			hld(it);
		}
	}
};

