// construct(int N, vector< long long > &A)

// INPUT: N representing size of input vector, A represents input vector
// OUTPUT: Builds a fenwick tree or BIT
// TIME COMPLEXITY: O(N*log(N))

// getVal(int i)

// INPUT: An integer i less than N.
// OUTPUT: Sum of vector elements in the range [0, i].  
// TIME COMPLEXITY: O(log(N))

// update(int i, long long val)

// INPUT: i represents the index of vector whoes value is to be updated by val.
// OUTPUT: updation done
// TIME COMPLEXITY: O(log(N))


#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class binaryIndexTree
{
    const int MAX = 1e5;
    const int INF = 1e9;
    int size;
    ll sum;

 public:

	vector< ll > tree;
	ll getVal(int i)
	{
	    sum=0;
		++i;                   //1 more indexing in BIT
		while(i>0)
		{
			sum+= tree[i];
			i-= (i &-i);        // get to parent
		}
		return sum;
	}

	void update(int i,ll val)
	{
		++i;                     //1 more indexing in BIT
		while(i<=size)
		{
			tree[i]+=val;
			i+= (i &-i);        // get to child
		}

	}

	void construct(int N, vector< ll > &A)
	{
		size = N;
		tree.resize(size+2);
		for(int i=0;i<=size+1;++i) tree[i] = 0;

		for(int i=0;i<size;++i)
			update(i, A[i]);
	}

}BIT;

