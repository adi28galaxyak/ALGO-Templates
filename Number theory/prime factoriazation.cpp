// primeFact(unsigned number)
// INPUT: An unsigned number
// OUTPUT: map containing the prime factors of the number
// TIME COMPLEXITY: O(sqrt(num) + O(log(K)))


// etf(unsigned number)
// INPUT: An unsigned number
// OUTPUT: Euler totient value of number
// TIME COMPLEXITY: O(sqrt(num) + O(log(K)))

#include "bits/stdc++.h"
using namespace std;
#define ULL unsigned long long

class primeFactorization
{
	const int MAX = 1e6;
	const int INF = 1e9;
  public:
	map<unsigned, int> factors;
	set<unsigned> fact1s;

	void primeFact(unsigned num)
	{
		fact1s.clear();
		factors.clear();

		bool init = false;
		while(!(num&1))
		{
			(init==false)?(factors[2] = 1, init=true):factors[2]++;
			num/=2;
			fact1s.insert(2);
		}

		int i = 3, sqr = sqrt(num);
		for(;i<sqr+1;++i){
			init =false;
			while(!(num%i)){
				(init==false)?(factors[i] = 1, init=true):factors[i]++;
				num/=i;		
				fact1s.insert(num);
			}
		}

		if(num>2){
			factors[num] = 1;
			fact1s.insert(num);
		} 
	}
};


class eulerToitentFunction: public primeFactorization
{
public:
	ULL etf(unsigned A){
		primeFact(A);

		ULL ans = (ULL)1;
		for(auto it: fact1s){
			ans *= (it - 1);
		}

		return ans;
	}

};