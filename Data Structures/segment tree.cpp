// buildTree(int id, int L, int R)

// Default input: id = 0, L = 0, R = N-1 [where N is the size of input vector]

// INPUT: Default input
// OUTPUT: Builds a Segment Tree
// TIME COMPLEXITY: O(N*log(N))

// getVal(int id, int L, int R, int X, int Y)

// INPUT: two integer X, Y, representing the index range
// OUTPUT: Returns sum of vector element in the range [X, Y]  
// TIME COMPLEXITY: O(log(N))

// update(int id, int L, int R, int X, long long data)

// INPUT: X represent index range, data is the value to be updated at index X
// OUTPUT: updation done
// TIME COMPLEXITY: O(log(N))


#include "bits/stdc++.h"
using namespace std;

#define LL long long int
const int MAX = 1e5;

class SegTree
{
	struct Node
	{
		LL val;

		// You can create your own type of nodes

		void combine(Node &A, Node &B)
		{
			val = min(A.val, B.val);
		}
	};
	int n;

public:
	const int MAX = 1e5;
	const int INF = 1e9;
	vector<LL> arr;
	segTree(int size)
	{
		n = size;

		struct Node tree[n+2];
		arr.resize(n+2);

		for(int i = 0;i<n;i++)
		{
			scanf("%lld", &arr[i]);
		}
	}

	void buildTree(int id, int L, int R)
	{
		if(L==R)
		{
			tree[id].val = arr[L];
			return ;
		}

		int mid = (L+R)/2;
		buildTree(2*id+1, L, mid);
		buildTree(2*id+2, mid+1, R);

		tree[id].combine(tree[2*id+1], tree[2*id+2]);
	}

	void getVal(int id, int L, int R, int X, int Y)
	{
		if(L>R || X>R || Y<L) 
			return 0;

		if(L>=X && R<=Y) 
			return tree[id].val;

		int mid = (L+R)/2;
		LL leftVal = getVal(2*id+1, L, mid, X, Y);
		LL rightVal = getVal(2*id+2, mid+1, R, X, Y);
		return max(leftVal, rightVal);
	}

	void update(int id, int L, int R, int X, LL data)
	{
		if(L==R)
		{
			tree[id] = data;
			return ;
		}

		int mid = (L+R)/2;
		(mid>=X)?update(2*id+1, L, mid, X, data):update(2*id+2, mid+1, R, X, data);

		tree[id].combine(tree[2*id+1], tree[2*id+2]);
	}

};
