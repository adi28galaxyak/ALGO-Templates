// This code performs maximum bipartite matching.
// Taking sets as jobs and person
// Running Time: O(|E| |V|)

// INPUT: weight[i][j] = edge between row node i and column node j
// OUTPUT: 
// 	- JOB vector representing which job is assigned to which person
// 	- maximum bipartite matching value

#include "bits/stdc++.h"
using namespace std;

typedef vector< int > VI;

const static int MAX = 5e3;
vector< VI > weight;

class matching{
	int V, E, person, jobs;
public:
	matching(int A, int J, int M){ // person, job and edges
		person = A;
		jobs = J;
		E = M;
		weight.resize(person+1);
		for(int i = 0;i<person;i++){
			for(int j = 0;j<jobs;j++)
				weight[i].push_back(0);
		}
	}

	void buildGraph(){
		int x, y;
		for(int i = 0;i<E;i++){
			cin>>x>>y;
			x--;y--;
			weight[x][y] = 1;
		}
	}

	bool match(int i, vector<bool> &seen, VI &JOB){
		for(int j = 0;j<jobs;j++){
			if(seen[j]==false and weight[i][j]){
				seen[j] = true;
				if(JOB[j]<0 or match(JOB[j], seen, JOB)){
					JOB[j] = i;
					return true;
				}
			}
		}
		return false;
	}

	int BipartiteMatching(){
		VI JOB(jobs+1, -1); // presently not assigned to anyone

		int ans = 0;
		for(int i = 0;i<person;i++){
			vector<bool> seen(jobs+1, false);
			if(match(i, seen, JOB)) ans++;
		}
		return ans;
	}
};
