// exponentiation (A^B) - https://en.wikipedia.org/wiki/Exponentiation_by_squaring
// Exp(unsigned A, unsigned B)
// INPUT: two unsigned numbers A, B
// OUTPUT: A^B
// TIME COMPLEXITY: O(log(B))

// modular exponentiation (A^B % M) - https://en.wikipedia.org/wiki/Modular_exponentiation
// modulo(unsigned long long A, unsigned long long B, unsigned long long M)
// INPUT: three unsigned long long numbers A, B, and M. [M is a prime number, by default M = 1e9 + 7]
// OUTPUT: (A^B)%M
// TIME COMPLEXITY: O(log(B))

// Inverse Modulo - wiki link
// invMod(unsigned long long A, unsigned long long M)
// INPUT: two unsigned long long numbers A, M. [M is a prime number, by default M = 1e9 + 7] 
// OUPUT: (inv(A))%M
// TIME COMPLEXITY: O(log(M))

// Precomputation Inverse modulo - https://en.wikipedia.org/wiki/Modular_multiplicative_inverse
// invModFast(unsigned range, unsigned M)
// INPUT: two unsigned numbers range, M, and range less than 1e8. [M is a prime number, by default M = 1e9+ 7]
// OUTPUT: vector<unsigned> of size A+1, where vector's ith index store (inv(i))%M.
// TIME COMPLEXITY: O(range)

#include "bits/stdc++.h"
using namespace std;

#define LL long long 
#define ll unsigned long long

class moduloMagic{
	const int MAX = 1e6;
	const int INF = 1e9;
	const int defaultVal = 1e9 + 7;

public:
	unsigned Exp(unsigned A, unsigned B)
	{
		unsigned x = 1, y = A;
		while(B>0)
		{
			if(B&1) x = (x*y);
			y = y*y;
			B>>=1;
		}
		return x;
	}

	ll multiply(ll a,ll b,ll c)
	{
	    ll x=0,y= a%c;
	    while(b>0)
	    {
	        if(b%2==1) x= (x+y)%c;
	        y= (y*2)%c;
	        b/=2;
	    }
	    return x%c;
	}

	ll modulo(ll a,ll b,ll c)
	{
	    ll ans=1;
	    while(b>0)
	    {
	        if(a>1000000000 && b>1000000000)
	        {
	            if(b%2==1) ans= multiply(ans,a,c);
	            a= multiply(a,a,c);
	            b/=2;
	        }
	        else
	        {
	            if(b%2==1) ans= ((ll)ans* (ll)a)%c;
	            a= ((ll)a* (ll)a)%c;
	            b/=2;
	        }
	        return ans%c;
	    }
	}

	ll invMod(ll A, ll M = defaultVal)
	{
		return modulo(A, M-2, M);
	}

	vector<unsigned> invModFast(unsigned range, unsigned M = defaultVal){
		
		vector<unsigned> inv_mod(rang+1);
		inv_mod[0] = inv_mod[1] = 1;
		
		for(int i = 2;i<=range;++i)
			inv_mod[i] = M-(((M/i) * inv_mod[M%i])%M);

		return inv_mod; 
	}		

};
