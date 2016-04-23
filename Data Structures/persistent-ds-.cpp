// Persistent Data Structure
// INPUT: 
// 	- Initial array
// 	- Update first K elements of array at each query
// OUTPUT:
// 	- Status of array at Kth Query

#include "bits/stdc++.h"
using namespace std;

#define LL long long int

struct node{
	LL val;
	struct node *link;
};

typedef struct node node;

class persistent{
	int N, Q;
public:
	vector< node* > ROOTS;
	node *root = NULL;
	
	node *gen(int x){
		node *P;
		P = (node *)malloc(sizeof(node));
		P->val = x;
		P->link = NULL;
		return P;
	}

	void all(int F, int id=-1){
		LL x;
		cin>>x;
		node *p = gen(x);
		
		node *R;
		if(id!=-1 and F<=N){
			node *q = ROOTS.back();
			for(int i = 0;i<F;i++) {q = q->link;}
			R = q;
		}

		ROOTS.push_back(p);
		for(int i = 1;i<F;i++){
			cin>>x;
			p->link = gen(x);
			p = p->link;
		}

		if(F<=N and id!=-1) {p->link = R;}
	}

	persistent(int V){ // number of nodes
		N = V;
		all(N);
	}

	void query(int q){
		Q = q;
		int F;
		while(q--){
			cin>>F; 
			all(F, 1);
		}
	}

	void disp(int kq){
		// status of array at kth query; kq<q
		node *p = ROOTS[kq];
		while(p) cout<<p->val<<" ";
		cout<<endl;
	}
};

