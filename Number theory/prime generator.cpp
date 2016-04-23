// INPUT: an unsigned integer less than 1e8+1
// OUTPUT: A boolean vector array, where ith index is true if i is a prime otherwise false.
// TIME COMPLEXITY: O(N*log(log(N)))

#include "bits/stdc++.h"
using namespace std;

#define LL long long 
#define ULL unsigned long long

class primeGenerator{
	const int MAX = 1e6;
	const int INF = 1e9;
public:
	vector<bool> checkPr;

	void seive(unsigned range){
		assert(range>=0);
		checkPr.resize(range+2, true);

		checkPr[0] = checkPr[1] = false;
		for(int i = 4;i<=range;i+=2) checkPr[i] = false;

		int sqr = sqrt(range), j, i;
		for(i = 3;i<=sqr;i+=2){
			if(checkPr[i]){
				for(j = i*i;j<range+1;j+=i)
					checkPr[j] = false;
			}
		}
	}
};